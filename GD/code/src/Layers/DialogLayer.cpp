#include "includes.h"
#include <ctime>



void DialogLayer::addToMainScene(){
    nextScene->addChild(this, 
        (cocos2d::CCDirector::sharedDirector()->getNextScene()->getHighestChildZ() < 1000) ? 1000 : cocos2d::CCDirector::sharedDirector()->getNextScene()->getHighestChildZ() + 1
    );
}

/* Figured out that Robtop is using time(NULL) to do everything
 * for example on android this part would be 
 *  clock_gettime(0,&local_34)
 *  m_time = (local_34.tv_sec + local_34.tv_nsec) / 1000.0;
 * 
 * on windows it would be using ftime()
 * _ftime64((timeb *)&stack0xffffffe8);
 * FUN_007c2f6f(_time);
 * m_time = _time.time / 1000.0
 * 
 * 
 * both handle time_t differently under the hood but it could very well be that it's using time(nullptr)
 * just differently. So I will just use time(nullptr) from now on. when decompiling time values */

void DialogLayer::animateIn(DialogAnimationType type){
    setVisible(true);   
    m_time = time(nullptr) / 1000.0;

    switch (type){
        case kDialogAnimationTypeFromCenter: {
            m_mainLayer->setScale(0.1);
            m_mainLayer->runAction(cocos2d::CCEaseElasticOut::create(cocos2d::CCScaleTo::create(0.5, 1.0), 0.6));
            break;
        }
        case kDialogAnimationTypeFromLeft: {
            cocos2d::CCPoint pos = ccp(-191.0f, m_mainLayer->getPosition().y);
            m_mainLayer->setPosition(pos);
            m_mainLayer->runAction(cocos2d::CCEaseElasticOut::create(cocos2d::CCMoveTo::create(0.5, pos), 0.6));
            break;
        }
        case kDialogAnimationTypeFromRight: {
            cocos2d::CCPoint pos = ccp(cocos2d::CCDirector::sharedDirector()->getScreenRight() + 190.0 + 1.0, m_mainLayer->getPosition().y);
            m_mainLayer->setPosition(pos);
            m_mainLayer->runAction(cocos2d::CCMoveTo::create(0.5, pos));
            break;
        }
        case kDialogAnimationTypeFromTop: {
            cocos2d::CCPoint pos = ccp(m_mainLayer->getPosition().x, (cocos2d::CCDirector::sharedDirector()->getScreenTop() + 50.0) + 1.0);
            m_mainLayer->setPosition(pos);
            m_mainLayer->runAction(cocos2d::CCEaseElasticOut::create(cocos2d::CCMoveTo::create(0.5, pos), 0.6));
            break;
        }
        case kDialogAnimationTypeFromBottom: {
            cocos2d::CCPoint pos = ccp(m_mainLayer->getPosition().x, (cocos2d::CCDirector::sharedDirector()->getScreenTop() - 50.0) - 1.0);
            m_mainLayer->setPosition(pos);
            m_mainLayer->runAction(cocos2d::CCEaseElasticOut::create(cocos2d::CCMoveTo::create(0.5, pos), 0.6));
            break;
        }
        default: 
            break;
    }
  
    float opacity = getOpacity();
    if (opacity != 0.0 && opacity < 0.0 == opacity) {
        setOpacity(0);
        runAction(cocos2d::CCFadeTo::create(opacity, 41));
    }
}

void DialogLayer::animateInDialog()
{
    animateIn(m_animationType);
}

void DialogLayer::animateInRandomSide()
{
    float rnd = rand() / 32767.0;
    if (rnd >  0.66) {
        return animateIn(kDialogAnimationTypeFromLeft);
    } else if (rnd > 0.33) {
        return animateIn(kDialogAnimationTypeFromRight);
    } else {
        return animateIn(kDialogAnimationTypeFromCenter);
    }
}

bool DialogLayer::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    if (m_id == -1) {
        m_id = touch->m_nId;
        handleDialogTap();
    }
    return true;
}


void DialogLayer::ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    if (m_id == touch->m_nId) {
        ccTouchEnded(touch, event);
    }
}


void DialogLayer::ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    if (m_id == m_nId) {
        m_id = m_nId = -1;
    }
}


void DialogLayer::ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event){
    return /* Noop */;
}


DialogLayer * DialogLayer::create(DialogObject *dObject, int frameID)
{
    return createDialogLayer(dObject, nullptr, frameID);
}

DialogLayer * DialogLayer::createDialogLayer(DialogObject *object, cocos2d::CCArray *objects,int frameID){
    DialogLayer* pRet = new DialogLayer();
    if (pRet != nullptr && pRet->init(object, objects, frameID)){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}

DialogLayer * DialogLayer::createWithObjects(cocos2d::CCArray *array, int frameID)
{
    return createDialogLayer(nullptr, array, frameID);
}

void DialogLayer::displayDialogObject(DialogObject *object)
{
    if (object == nullptr){
        return;
    }

    m_animationRunning = true;
    m_hasMoreDialog = object->m_canSkip;
    m_sprite->stopAllActions();
    m_sprite->setOpacity(0);

    /* Cleanup icon and textArea if we displayed something before */
    if (m_icon != nullptr) {
        m_icon->removeMeAndCleanup();
        m_icon = nullptr;
    }

    if (m_textArea != nullptr) {
        m_textArea->removeMeAndCleanup();
        m_textArea = nullptr;
    }

    m_label->setString(object->m_npcName.c_str());
    m_label->updateDisplayedColor(object->m_color);

    if (object->m_iconType > 0) {
        object->m_iconType = (object->m_iconType > 51) ? object->m_iconType : 52;
        object->m_iconType = (object->m_iconType < 1) ? object->m_iconType : 1;
        m_icon = cocos2d::CCSprite::create(
            cocos2d::CCString::createWithFormat("dialogIcon_%03d.png", object->m_iconType)->getCString()
        );
        m_mainLayer->addChild(m_icon, 2);
        m_icon->setPosition(ccp(-143.0, 0.0));
    }

    m_textArea = TextArea::create(object->m_description,"chatFont.fnt", 1.0, 220.0 / object->m_height, ccp(0.0, 1.0), 20.0,false);
    m_textArea->setAnchorPoint(ccp(0.0, 0.5));
    m_textArea->setScale(object->m_height);
    m_mainLayer->addChild(m_textArea, 3);
    m_textArea->setPosition(ccp(-92.0, 0.0));
    m_textArea->fadeInCharacters(0.2, 0.02);
}

void DialogLayer::displayNextObject()
{
    if (m_objects->count() != 0) {
        displayDialogObject(reinterpret_cast<DialogObject *>(m_objects->objectAtIndex(0)));
        m_objects->removeObjectAtIndex(0,true);
        updateNavButtonFrame();
    }
}



void DialogLayer::finishCurrentAnimation()
{
    m_animationRunning = false;
    if (m_textArea != nullptr) {
        m_textArea->stopAllCharacterActions();
        m_textArea->showAll();
    }
    m_sprite->stopAllActions();
    m_sprite->setOpacity(0xff)
    updateNavButtonFrame();
}

void DialogLayer::keyBackClicked()
{
    if (m_dialogDelegate != nullptr) {
        m_dialogDelegate->dialogClosed(this);
    }
    m_dialogDelegate = nullptr;
    if (m_textArea != nullptr) {
        m_textArea = nullptr;
    }
    setKeypadEnabled(false);
    setKeyboardEnabled(false);
    if (m_loadOnNextScene == false) {
        removeFromParentAndCleanup(true);
    }
}

void DialogLayer::fadeInTextFinished(TextArea *textArea)
{
    m_animationRunning = false;
    m_sprite->stopAllActions();
    m_sprite->setOpacity(0)
    m_sprite->runAction(cocos2d::CCFadeIn::create((m_objects == nullptr || m_objects->count() == 0) ? 0.5 : 0.3));
}

bool DialogLayer::init(DialogObject *object, cocos2d::CCArray *array, int frameID)
{
    cocos2d::ccColor4B color = cocos2d::ccc4(0, 0, 0, 0x96);
    if (!cocos2d::CCLayerColor::initWithColor(color)){
        return false;
    }

    if (array != nullptr) {
        m_objects = array;
        m_objects->retain();
    }

    cocos2d::CCSize winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    cocos2d::CCDirector::sharedDirector()->getTouchPadDispatcher()->registerForcePrio(this, 2);
    setTouchEnabled(true);
    setKeypadEnabled(true);
    setKeyboardEnabled(true);

    m_mainLayer = cocos2d::CCLayer::create();
    m_mainLayer->addChild(this);
    m_mainLayer->setContentSize(cocos2d::CCSizeZero);
    m_mainLayer->setPosition(ccp(winSize.width * 0.5, winSize.height  * 0.5));

    cocos2d::extension::CCScale9Sprite* scale9sprite = cocos2d::extension::CCScale9Sprite::create(cocos2d::CCString::createWithFormat("GJ_square%02d.png",frameID)->getCString(), CCRectMake(0.0,0.0,80.0,80.0));
    scale9sprite->setContentSize(CCSizeMake(380.0,100.0));
    m_mainLayer->addChild(scale9sprite, -2);
    m_label = cocos2d::CCLabelBMFont::create(" ","bigFont.fnt");
    m_mainLayer->addChild(m_label, 2);

    m_label->setAnchorPoint(ccp(0.0,1.0));
    m_label->setPosition(ccp(-93.0,36.0));
    m_label->limitLabelWidth(200.0, 0.5, 0.0);
    
    cocos2d::extension::CCScale9Sprite* scale9sprite2 = cocos2d::extension::CCScale9Sprite::create("square02b_001.png", CCRectMake(0.0, 0.0, 80.0, 80.0));
    scale9sprite2->setContentSize(CCSizeMake(280.0,80.0));
    m_mainLayer->addChild(scale9sprite2, -1);
    scale9sprite2->setPosition(ccp(40.0,0.0));
    scale9sprite2->setColor(cocos2d::ccc3(0, 0, 0));
    scale9sprite2->setOpacity(50);
    m_sprite = cocos2d::CCSprite::createWithSpriteFrameName("GJ_chatBtn_01_001.png");
    m_mainLayer->addChild(m_sprite, 3);
    m_sprite->setPosition(ccp(0.0, -50.0));
    m_sprite->setOpacity(0);
    if (m_objects == nullptr) {
        displayDialogObject(object);
    } else {
        displayNextObject();
    }
    updateNavButtonFrame();
    return true;
}



void DialogLayer::keyDown(cocos2d::enumKeyCodes keys)
{
    if (keys != cocos2d::KEY_Up) {
        if (keys < cocos2d::KEY_Right) {
            if (keys == cocos2d::KEY_Escape){
                return handleDialogTap();
            }
            if (keys != cocos2d::KEY_Space){
                return;
            }
        }
        else {
            if ((keys == cocos2d::CONTROLLER_Left) || (keys == cocos2d::CONTROLLER_UNKNOWN /* Unknown enum */)){
                return handleDialogTap();
            }
            if (keys != cocos2d::CONTROLLER_A)
                return;
        }
    }
    handleDialogTap();

    // I did not like ghidra's response so I made my own switchblock below instead beacuse (as far as I'm aware) 
    // it means the same thing however some further investigating into it's assembly might be needed...
    
    // For those who want to google this or anything else I'll just dump ghidra's assembly of it into here
    // I mainly just want to confirm this is a switchblock before I change the code above. with the code below
    // 004c53c0 26  29           cmp        keys ,#0x26
    // 004c53c2 10  d0           beq        LAB_004c53e6
    // 004c53c4 03  dc           bgt        LAB_004c53ce
    // 004c53c6 1b  29           cmp        keys ,#0x1b
    // 004c53c8 0d  d0           beq        LAB_004c53e6
    // 004c53ca 20  29           cmp        keys ,#0x20
    // 004c53cc 0a  e0           b          LAB_004c53e4
    //                      LAB_004c53ce                                    XREF[1]:     004c53c4 (j)   
    // 004c53ce 40  f2  f5  33   movw       r3,#0x3f5
    // 004c53d2 99  42           cmp        keys ,r3
    // 004c53d4 07  d0           beq        LAB_004c53e6
    // 004c53d6 40  f2  f7  33   movw       r3,#0x3f7
    // 004c53da 99  42           cmp        keys ,r3
    // 004c53dc 03  d0           beq        LAB_004c53e6
    // 004c53de 40  f2  e9  33   movw       r3,#0x3e9
    // 004c53e2 99  42           cmp        keys ,r3
    //                      LAB_004c53e4                                    XREF[1]:     004c53cc (j)   
    // 004c53e4 01  d1           bne        LAB_004c53ea
    //                      LAB_004c53e6                                    XREF[4]:     004c53c2 (j) , 004c53c8 (j) , 
    //
    // 004c53e6 ff  f7  7b  bf    b.w        DialogLayer::handleDialogTap
                            //  -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
                            //  LAB_004c53ea                                    XREF[1]:     004c53e4 (j)   
    // 004c53ea 70  47           bx         lr


    // switch (keys) {
    //     case cocos2d::KEY_Up:
    //     case cocos2d::KEY_Right:
    //     case cocos2d::KEY_Escape:
    //     case cocos2d::CONTROLLER_Left:
    //     case cocos2d::CONTROLLER_UNKNOWN:
    //     case cocos2d::CONTROLLER_A:
    //         return handleDialogTap();
    //     default:
    //         return;
    // }
}


void DialogLayer::handleDialogTap()
{
    m_time = time(nullptr) / 1000.0;
    if (m_time >= 0.0f || m_unkBool){
        if (m_animationRunning == false)
        {
            if ((m_objects == nullptr) || (m_objects->count() == 0)) 
            {
                onClose();
            } 
            else {
                displayNextObject();
            }
        } 
        else if (m_hasMoreDialog == false) 
        {
            finishCurrentAnimation();
        }
    }
}


void DialogLayer::onClose()
{
    if (m_dialogDelegate != nullptr) {
        m_dialogDelegate->dialogClosed(this);
    }
    m_dialogDelegate = nullptr;
    if (m_textArea != nullptr) {
        m_textArea->m_delegate = nullptr;
    }
    setKeypadEnabled(false);
    setKeyboardEnabled(false);
    if (m_loadOnNextScene == false){
        removeFromParentAndCleanup(true); 
    }
}

/* seems to go directly into CCLayer::onEnter()... */
void DialogLayer::onEnter(){
    CCLayer::onEnter();
}


void DialogLayer::registerWithTouchDispatcher()
{
    cocos2d::CCDirector::sharedDirector()->getTouchPadDispatcher()->addPrioTargetedDelegate(this, -0x1f5, true);
}


void DialogLayer::updateChatPlacement(DialogChatPlacement chat)
{
    cocos2d::CCSize size = cocos2d::CCDirector::sharedDirector()->getWinSize();
    switch (chat){
        case kDialogChatPlacementCenter: {
            m_mainLayer->setPosition(ccp(size.width * 0.5, size.height * 0.5));
            break;
        }
        case kDialogChatPlacementTop : {
            m_mainLayer->setPosition(ccp(size.width * 0.5, (size.height - 50.0) - 20.0));
            break;
        }
        case kDialogChatPlacementBottom : {
            m_mainLayer->setPosition(ccp(size.width * 0.5, 70.0));
            break;
        }
        default:
            break;
    }
}

void DialogLayer::updateNavButtonFrame()
{
    if ((m_objects == nullptr) || (m_objects->count() == 0)) {
        m_sprite->setDisplayFrame(cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("GJ_chatBtn_02_001.png"));
    } 
    else {
        m_sprite->setDisplayFrame(cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("GJ_chatBtn_01_001.png"));
    }
}

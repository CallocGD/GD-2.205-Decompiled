#include "includes.h"


void CCBlockLayer::ccTouchCancelled(CCTouch *touch,CCEvent *event){}


bool CCBlockLayer::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    return true;
}

CCBlockLayer* CCBlockLayer::create(){
    CCBlockLayer* pRet = new CCBlockLayer();
    if ((pRet != nullptr) && pRet->init()){
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return nullptr;
}



void CCBlockLayer::decrementForcePrio()
{
    if (m_registered != false) {
        m_registered = false;
        cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->unregisterForcePrio(this);
    }
}

void CCBlockLayer::disableUI(){}

void CCBlockLayer::draw(){
    if (getOpacity() != 0) {
        cocos2d::CCLayerColor::draw();
    }
}


void CCBlockLayer::enableUI(){}

void CCBlockLayer::enterAnimFinished(){}

void CCBlockLayer::enterLayer()
{
    enableUI();
    showLayer(false);
}

void CCBlockLayer::exitLayer()
{
    setKeypadEnabled(false);
    disableUI();
    hideLayer(false);
}


void CCBlockLayer::hideLayer()
{
    layerHidden();
}

void CCBlockLayer::incrementForcePrio()
{
    if (m_registered == false) {
        m_registered = true;
        cocos2d::CCDirector::sharedDirector()->getTouchPadDispatcher()->registerForcePrio(this, 2);
    }
}

bool CCBlockLayer::init()
{   
    if (!initWithColor(cocos2d::ccc4(0,0,0,0x7d))){
        return false;
    }
    
    incrementForcePrio();
    setTouchEnabled(true);
    setKeypadEnabled(true);
    setKeyboardEnabled(true);
    /* Robtop seems to have called this but it doesn't do anything :/ */
    cocos2d::CCDirector::sharedDirector()->getWinSize();
    customSetup();
    m_isShowing = true;
    return true;
}

void CCBlockLayer::keyBackClicked()
{
    exitLayer();
}

void CCBlockLayer::layerHidden()
{
    setVisible(false);
    if (m_isShowing){
        removeFromParentAndCleanup(true);
    }
}

void CCBlockLayer::layerVisible()
{
    setVisible(true);
}


void CCBlockLayer::registerWithTouchDispatcher()
{
    cocos2d::CCDirector::sharedDirector()->getTouchPadDispatcher()->addTargetedDelegate(this,-500,true);
}

void CCBlockLayer::showLayer()
{
    layerVisible();
}

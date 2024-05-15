#include "includes.h"
// Blame Intellisense for misbehaving with me...
// #include "GameObject.h"
// #include "OBB2D.h"



/* I will be posting complexities of functions from ghidra's own
 * built-in scripts to show their difficulty so if I skip over any 
 * of them, you'll know why */
void GameObject::activateObject()
{
    return;
}



void GameObject::activatedByPlayer(PlayerObject* playerObject){
    /* NOOP */
};

/* complexity: 363 */
void GameObject::addColorSprite(std::string p0)
{
    return;
}

/* Unknown Fields */
void GameObject::addColorSpriteToParent(bool p0)
{
    return;
}


void GameObject::addColorSpriteToSelf()
{
    /* if we are indeed the parent we must exit... */
    if (this == reinterpret_cast<GameObject *>(getParent())) return;
    m_isChild = true;
    m_colorSprite->removeFromParentAndCleanup(false);
    addChild(m_colorSprite, m_show ? 100 : -100);
    m_colorSprite->setScale(1);
    m_colorSprite->setRotation(0);
    auto contentSize = getContentSize();
    m_colorSprite->setPosition(CCPointMake(contentSize.width * 0.5, contentSize.height * 0.5));
}

/* Unknown Fields */
void GameObject::addCustomBlackChild(std::string p0, float p1, bool p2)
{
    return;
}


cocos2d::CCSprite* GameObject::addCustomChild(std::string pszSpriteFrameName, cocos2d::CCPoint pos, int zOrder)
{
    cocos2d::CCSprite* sprite = cocos2d::CCSprite::createWithSpriteFrameName(pszSpriteFrameName.c_str());
    sprite->setPosition(convertToNodeSpace(pos) + pos);
    addChild(sprite, zOrder);
    return sprite;
}



cocos2d::CCSprite * GameObject::addCustomColorChild(std::string customColor)
{
  
    if (m_colorSprite != nullptr) {
        m_colorSprite->removeFromParent();
        if (m_colorSprite != nullptr) {
            m_colorSprite->release();
        } 
        m_colorSprite = nullptr;
    }
    createSpriteColor(2);
    m_colorSprite = cocos2d::CCSprite::createWithSpriteFrameName(customColor.c_str());
    m_colorSprite->retain();
    m_colorSprite->setPosition(getPosition());
    return m_colorSprite;
}


void GameObject::addEmptyGlow()
{
    createGlow("emptyGlow.png");
    if (m_glow != nullptr) m_glow->setDontDraw(true);
}

/* complexity: 105 , numerous if statements that should be switch blocks... :( , 300+ lines of code */
void GameObject::addGlow(std::string p0){}


cocos2d::CCSprite* GameObject::addInternalChild(cocos2d::CCSprite* sprite, std::string frameName, cocos2d::CCPoint pos, int zOrder)
{
    cocos2d::CCSprite* new_sprite = cocos2d::CCSprite::createWithSpriteFrameName(frameName.c_str());
    new_sprite->setPosition(sprite->convertToNodeSpace(pos) + pos);
    sprite->addChild(new_sprite,zOrder);
    return new_sprite;
}


cocos2d::CCSprite * GameObject::addInternalCustomColorChild(std::string frameName, cocos2d::CCPoint pos, int zOrder)
{

    if (m_colorSprite == nullptr) return nullptr;
    m_colorSprite = cocos2d::CCSprite::createWithSpriteFrameName(frameName.c_str());
    m_colorSprite->setPosition(m_colorSprite->convertToNodeSpace(pos) + pos);
    m_colorSprite->addChild(m_colorSprite, zOrder);
    return m_colorSprite;
}


cocos2d::CCSprite * GameObject::addInternalGlowChild(std::string frameName, cocos2d::CCPoint pos)
{
    if (m_glow == nullptr) return nullptr;
    m_glow = cocos2d::CCSprite::createWithSpriteFrameName(frameName.c_str());
    m_glow->setPosition(m_glow->convertToNodeSpace(pos) + pos);
    m_glow->addChild(m_glow, -1);
    return m_glow;
}


/*  complexity: 8, Too Many Unknown Fields and data to work with at the moment... */
/* Unknown Return: GameObject::addMainSpriteToParent(bool p0){}; */


/* Unknown Subclass field at 0x1d7 */
void GameObject::addNewSlope01(bool p0)
{
    return;
}


void GameObject::addNewSlope01Glow(bool dontDraw)
{  
  
    if (m_glow == nullptr) return;
    if (dontDraw) m_glow->setDontDraw(true);
    
    cocos2d::CCSprite* sprite = cocos2d::CCSprite::createWithSpriteFrameName(getGlowFrame("blockOutline_14new_001.png").c_str());
    sprite->setRotation(-45);
    m_glow->addChild(sprite);
    /* It's probably this but IDK about what it's CCPoint is or where it's coming form... */
    sprite->setPosition(sprite->convertToNodeSpace(m_glow->getAnchorPoint()));
}

/* Same Problem as addNewSlope01 we don't know what 0x1d7 is supposed to be... */
void GameObject::addNewSlope02(bool p0)
{
    return;
}


void GameObject::addNewSlope02Glow(bool dontDraw)
{
    if (m_glow == nullptr) return;
    if (dontDraw) m_glow->setDontDraw(true);
    
    cocos2d::CCSprite* sprite = cocos2d::CCSprite::createWithSpriteFrameName(getGlowFrame("blockOutline_15new_001.png").c_str());
    sprite->setRotation(-26.5);
    m_glow->addChild(sprite);
    /* It's probably this but IDK about what it's CCPoint is or where it's coming form... */
    sprite->setPosition(sprite->convertToNodeSpace(m_glow->getAnchorPoint()));
}



void GameObject::addRotation(float rotationX, float rotationY)
{
    setRotationX(getRotationX() + rotationX);
    setRotationY(getRotationY() + rotationY);
}


/* unknown part at line 13: 
 * if (*(float *)((int)&sub + 0x34) == *(float *)((int)&sub + 0x38)) { 
 *
 * TODO: Ask Robtop 
 */
void GameObject::addRotation(float p0)
{
    return;
}


void GameObject::addToColorGroup(int color)
{
    if ((m_totalColors < 10) && ((color - 1) < 9999)) {
        createColorGroupContainer(10);
        for (int i = 0; i < m_totalColors; i++){
            if ((*m_colorArray)[i] == color) 
                break;
        }
        m_totalColors++;
    }
}

void GameObject::addToCustomScaleX(float scaleX)
{
    m_textureRectDirty = true;
    m_objectRectDirty = true;
    m_scaleXInc = m_scaleXInc + scaleX;
    m_customScaleX = m_customScaleX + scaleX;
    return;
}


void GameObject::addToCustomScaleY(float scaleY)
{
    m_textureRectDirty = true;
    m_objectRectDirty = true;
    m_scaleYInc = m_scaleYInc + scaleY;
    m_customScaleY = m_customScaleY + scaleY;
}



int GameObject::addToGroup(int groupNumber)
{
    if ((m_groupsCount < 10) && (groupNumber - 1 < 9999)) {
        createGroupContainer(10);
        int i = 0;
        while (true) {
            if (m_groupsCount <= i) {
                m_groupContainer->operator[](m_groupsCount) = groupNumber;
                m_groupsCount += 1;
                return 1;
            }
            if (m_groupContainer->operator[](i) == groupNumber) break;
            i++;
        }
        return -1;
    }
    return 0;
}


void GameObject::addToOpacityGroup(int _opacity)
{

    if ((m_opacityGroupCount < 10) && (_opacity - 1 < 9999)) {
        createOpacityGroupContainer(10);
        for (int i = 0; i < m_opacityGroupCount; i + 1) {
            if (m_opacityGroupContainer[i] == _opacity) 
                return;
        }
        m_opacityGroupContainer[m_opacityGroupCount] = _opacity;
        m_opacityGroupCount += 1;
    }
}



void GameObject::addToTempOffset(double x, double y)
{  
    if (!m_horizonalOffsetOnly)
        m_realPositionX += x;
    m_realPositionY += y;
}


void GameObject::animationTriggered()
{
  /* NOOP */
}


static int GLOBAL_MID;

void GameObject::assignUniqueID(){
    m_unqiueID = GLOBAL_MID;
    //  what is this bullshit ;-; 
    //  *(int *)((int)&sub + 0x30) = GLOBAL_MID;
    // Maybe it's this?
    setTag(GLOBAL_MID);
    GLOBAL_MID++;
}



bool GameObject::belongsToGroup(int groupID)
{
    if (0 < m_groupsCount) {
        for (int i = 0; i < m_groupsCount; i++) {
            if (m_groupContainer->operator[](i) == groupID) 
                return true;
        }
    }
    return false;
}


/* Unknown Return: GameObject::blendModeChanged(){}; */


cocos2d::CCRect GameObject::calculateOrientedBox(){
    m_boxCalculated = true;
    updateOrientedBox();
    return getObjectRect();
};

bool GameObject::canAllowMultiActivate(){
    return false;
}

bool GameObject::canBeOrdered(){
    return false;
}

bool GameObject::canChangeCustomColor(){
    return canChangeMainColor() | canChangeSecondaryColor();
}

bool GameObject::canChangeMainColor(){
    return m_mainColor->m_defaultColorID != 0;
}

bool GameObject::canChangeSecondaryColor(){
    return m_detailColor->m_defaultColorID != 0;
}


bool GameObject::canMultiActivate(bool unk){
    return false;
}


bool GameObject::canReverse(){
    return false;
}


bool GameObject::canRotateFree(){
    /* What the fuck is this code Robtop? -_- */
    return ((m_objectType < 0x1a) && ((1 << (m_objectType & 0xff) & 0x2200001U))) && m_isNoTouch;
}

/* complexity: 18 , I am not doing this yet, too many unknown fields, However feel free to do it before I get to it if you must... */
/* Unknown Return: GameObject::claimParticle(){}; */

/* Unknown Class members are preventing me from doing this one... */
/* Unknown Return: GameObject::colorForMode(int p0, bool p1){}; */

/* Unknown Class Members */
void GameObject::commonInteractiveSetup()
{
}

/* Unknown Class Members */
void GameObject::commonSetup()
{
}


void GameObject::copyGroups(GameObject *object)
{
    if (object->m_groupsCount >= 1) {
        for (int i = 0; i < object->m_groupsCount; i = i + 1) {
            addToGroup(getGroupID(i));
        }
    }
}

/* TODO: There's some objects I have not Reversed yet in this one... */
/* Unknown Return: GameObject::createAndAddParticle(int p0, char const* p1, int p2, cocos2d::tCCPositionType p3){}; */

void GameObject::createColorGroupContainer(int group)
{
    if (m_colorArray) {
        m_colorArray = new std::array<short, 10>;
        for (int i; i < group; i++){
            m_colorArray->operator[](i) = 0;
        }
    }
}


void GameObject::createGlow(std::string frameName)
{
    if (m_glow != nullptr) {
        m_glow->release();
        m_glow->removeMeAndCleanup();
        m_glow = nullptr;
    }
    m_glow = cocos2d::CCSprite::createWithSpriteFrameName(frameName.c_str());
    m_glow->retain();
    m_glow->setPosition(getPosition());
    m_glow->setOpacity(0xff);
}

void GameObject::createGroupContainer(int group)
{
    if (m_groupContainer) {
        m_groupContainer = new std::array<short, 10>;
        for (int i; i < group; i++){
            m_groupContainer->operator[](i) = 0;
        }
    }
}



void GameObject::createOpacityGroupContainer(int group)
{
    if (m_groupContainer) {
        m_groupContainer = new std::array<short, 10>;
        for (int i; i < group; i++){
            m_groupContainer->operator[](i) = 0;
        }
    }
}

/* TODO: GJSpriteColor */
/* Unknown Return: GameObject::createSpriteColor(int p0){}; */


GameObject * GameObject::createWithFrame(const char *frame)
{
    /* 0x488 */
    auto gameObject = new GameObject;
    if (gameObject != nullptr && gameObject->init(frame)) {
        gameObject->autorelease();
        return gameObject;
    }
    CC_SAFE_DELETE(gameObject);
    return nullptr;
}

/* Hell no, I am not ready to do this one...  complexity: 216, 600+ lines of code */
GameObject* GameObject::createWithKey(int key)
{
}


void GameObject::customObjectSetup(std::vector<std::string>& p0, std::vector<void*>& p1)
{
    /* NOOP */
}

/* complexity: 967 , 3600+ lines of code... ;-; */
void GameObject::customSetup()
{

}

/* complexity: 7 , Unknown Class Members 45 lines of code */
void GameObject::deactivateObject(bool p0)
{

}


void GameObject::deselectObject()
{
    m_isSelected = false;
    updateObjectEditorColor();
}

/* 2 Unknown Class variables */
void GameObject::destroyObject()
{
//   field_0x33a = 1;
//   field_0x292 = 1;
    setOpacity(0);
}


/* Unknown Class Members, complexity: 23, Lines of code 120 */
/* Unknown Return: GameObject::determineSlopeDirection(){}; */

/* Robtop, I think Think the math is not nessesary but feel free to enlighten me on why this is here - Calloc */

bool GameObject::didScaleXChange()
{
    return (m_scaleX * 10000.0) - (m_currentScaleX * 10000.0) != 0;
}

bool GameObject::didScaleYChange()
{
    return (m_scaleY * 10000.0) - (m_currentScaleY * 10000.0) != 0;
}

// 2 Unknown Class Members
// void GameObject::dirtifyObjectPos()
// {
//   field133_0x2bd = true;
//   field134_0x2be = true;
// }


void GameObject::dirtifyObjectRect()
{
    m_objectRectDirty = true;
    m_orientedRectDirty = true;
}


void GameObject::disableObject() {
    destroyObject();
    triggerActivated(0.f);
}


bool GameObject::dontCountTowardsLimit()
{
    return m_objectID == 0x1f;
}


void GameObject::duplicateAttributes(GameObject *object)
{
    m_zOrder = object->getObjectZOrder();
    setCustomZLayer(object->getObjectZLayer());
    m_editorLayer = object->m_editorLayer;
    m_editorLayer2 = object->m_editorLayer2;
    m_isDontFade = object->m_isDontFade;
    m_isHighDetail = object->m_isHighDetail;
    m_isIceBlock = object->m_isIceBlock;
    m_isDontEnter = object->m_isDontEnter;
    m_isNoTouch = object->m_isNoTouch;
    m_isGripSlope = object->m_isGripSlope;
    m_hasNoEffects = object->m_hasNoEffects;
    m_isPassable = object->m_isPassable;
    m_hasNoGlow = object->m_hasNoGlow;
    m_isHide = object->m_isHide;
    m_isNonStickX = object->m_isNonStickX;
    m_isDontBoostY = object->m_isNonStickY;
    m_isDontBoostY = object->m_isDontBoostY;
    m_isExtraSticky = object->m_isExtraSticky;
    m_isScaleStick = object->m_isScaleStick;
    m_isDontBoostX = object->m_isDontBoostX;
    m_hasNoParticles = object->m_hasNoParticles;
    m_hasNoAudioScale = object->m_hasNoAudioScale;
}   

/* Unknown Class Members, complexity: 6 , lines of code: 53 */
/* Unknown Return: GameObject::duplicateColorMode(GameObject* p0){}; */


void GameObject::duplicateValues(GameObject *object)
{
    if (getRotationX() == getRotationY()) {
        setRotation(object->getRotation());
    }
    else {
        setRotationX(getRotationX());
        setRotationY(getRotationY());
    }
    setFlipX(object->isFlipX());
    setFlipY(object->isFlipY());
    duplicateColorMode(object);
    m_zOrder = object->m_zOrder;
    setCustomZLayer(object->getCustomZLayer());
    m_isDontFade = object->m_isDontFade;
    m_isDontEnter = object->m_isDontEnter;
    m_hasNoEffects = object->m_hasNoEffects;

    for (int i = 0; i < object->m_groupsCount; i++) {
        addToGroup(object->getGroupID(i));
    }
    // I think this is it?...
    updateCustomScaleX(object->m_scaleX);
    updateCustomScaleY(object->m_scaleY);
}


/*  complexity: 2 , Reason: Unknown Globals , Lines: 27 */
/* Unknown Return: GameObject::editorColorForCustomMode(int p0){}; */

/* complexity: 13, Reason: Unknown Class Member if Statements Should be switch blocks... , Lines: 80 */
/* Unknown Return: GameObject::editorColorForMode(int p0){}; */


void GameObject::fastRotateObject(float roataion)
{
    m_rotationX += roataion;
    m_rotationY += roataion;
    addRotation(roataion);
    if ((m_objectType != 7) && (m_boxCalculated == false)) {
        calculateOrientedBox();
    }
}


void GameObject::firstSetup()
{
    /* NOOP */
}

/* complexity: 1, Reason: Unknown Class Members , Lines: 230 */
/* GameObject::GameObject() */

/* complexity: 8, Reason: Unknown Class Members, Lines: 64 */
/* Unknown Return: GameObject::getActiveColorForMode(int p0, bool p1){}; */


/* The Random Pluse thingys from stero madness and many other Robtop levels... */

const char * GameObject::getBallFrame(int _ID){
    return cocos2d::CCString::createWithFormat("rod_ball_%02d_001.png", (_ID < 3) ? _ID & ~(_ID >> 0x1f) : 3)->getCString();
}


/* complexity: 3, Reason: Unknown Class Members, Slight Complexity on one part, Lines: 31*/
/* Unknown Return: GameObject::getBoundingRect(){}; */



cocos2d::CCPoint GameObject::getBoxOffset(){

}; 

/* complexity: 3, Reason: Unknown Function with Unknown std functions , Lines: 23 */
/* Unknown Return: GameObject::getColorFrame(std::string p0){}; */


int GameObject::getColorIndex()
{
    switch(m_objectID) {
        case 744: 
            return 1003;
        case 30: 
            return 1001;
        case 105: 
            return 1004;
        case 29: 
            return 1000;
        case 900: 
            return 1009;
        case 915: 
            return 1002;
        case 899: 
            return m_targetColor;
        default: 
            return 0;
    }
}

/* complexity: 13, Reason: Unknown Class Members and Heavy Complex parts, Lines: 139 */
/* Unknown Return: GameObject::getColorKey(bool p0, bool p1){}; */


int GameObject::getCustomZLayer()
{
    return m_customZLayer;
}

/* Same Issue as the other Frame thingy... */
/* Unknown Return: GameObject::getGlowFrame(std::string p0){}; */

/* Unknown Return Type */
/* 
undefined GameObject::getGroupDisabled()
  return m_groupDisabled;
}
*/


int GameObject::getGroupID(int groupID){
    if (groupID < 10) {
        if (m_groupContainer != nullptr) {
            return m_groupContainer->operator[](groupID);
        }
    }
    
    m_groupContainer = nullptr;
    
    return 0;
};



std::string GameObject::getGroupString(){
    fmt::Writer writer; 
    bool toggle = true;
    unsigned int i = 0;

    /* Not sure why robtop would do this a total of 20 times if there's only up to 10 possible groups :/ */
    for (unsigned int i = 0; i != 20; i += 2){
        auto value = (*m_groupContainer)[i];
        if (value > 0) {
            if (!toggle){ 
                writer << ".";
            }
            writer << value;
            toggle = false;
        }
    }
    std::string data = writer.str();
    writer.Clear();
    return data;
}


bool GameObject::getHasRotateAction()
{
    return false;
}


bool GameObject::getHasSyncedAnimation()
{
  return false;
}


cocos2d::CCPoint GameObject::getLastPosition()
{
    return CCPointMake(m_lastPositionX, m_lastPositionY);
}


GJSpriteColor * GameObject::getMainColor()
{
    return m_baseColor;
}



int GameObject::getMainColorMode(){
    auto color = getMainColor();
    return (color != nullptr) ? color->getColorMode() : 0;
};


int GameObject::getObjectDirection(){
    determineSlopeDirection();
    int slope = m_slopeType - 2;
    if (5 <  slope) {
        return 4;
    }
    int ID = 1;
    int i = 1 << (slope & 0xffU);
    if ((i & 0x24) == 0) {
        if ((i & 0x18) == 0) {
            if ((i & 3) == 0) {
              ID = 4;
            }
            else {
              ID = 3;
            }
            return ID;
        }
    }
    else {
        ID = 2;
    }
    return ID;
}


int GameObject::getObjectLabel()
{
    return 0;
}


float GameObject::getObjectRadius()
{
    if ((m_customScaleX != 1.0) || (m_customScaleX != 1.0)) {
        if (-1 < ((m_customScaleX < m_customScaleY) << 0x1f)) {
          m_customScaleY = m_customScaleX;
        }
        m_objectRadius = m_objectRadius * m_customScaleY;
    }
    return m_objectRadius;
}

cocos2d::CCRect GameObject::getObjectRect()
{
    return getObjectRect2(m_OBB2DWidth, m_OBB2DHeight);
}


cocos2d::CCRect GameObject::getObjectRect(float width, float height)
{
    if (m_isOrientedRectDirty) {
        m_customScaleX = abs(m_customScaleX);
        m_customScaleY = abs(m_customScaleY);
    }

    cocos2d::CCSize size = CCSizeMake(m_spriteSizeWidth * m_customScaleX, m_spriteSizeHeight * m_customScaleY);
    size.width *= width;
    size.height *= height;
    cocos2d::CCPoint boxOffset = getBoxOffset();
    m_customScaleX = size.height;
    if (m_objectRectCanRotate) {
        size.height = size.width;
        size.width = m_customScaleX;
    }
    cocos2d::CCPoint offset = getRealPosition() + boxOffset;
    return CCRectMake(offset.y - size.width * 0.5, offset.x - size.height * 0.5, size.width, size.height);
}


cocos2d::CCRect GameObject::getObjectRect2(float width,float height)
{
    if (m_objectRectDirty) {
        m_objectRectDirty = false;
        m_transferedObjectRect = (m_oriented) ? getOuterObjectRect(): getObjectRect(width, height);
    }
    return m_transferedObjectRect;
}


bool GameObject::getObjectRectDirty()
{
    return m_objectRectDirty;
}

cocos2d::CCRect& GameObject::getObjectRectPointer()
{
    if (m_objectRectDirty) {
        getObjectRect();
    }
    return m_transferedObjectRect;
}

double GameObject::getObjectRotation(){
    m_defaultRotationX + m_UnkownRotation;
};

/* complexity: 10 , Reason: Unknown Memebers and Unknown vtable Calls Otherwise Ask Robtop, Lines of Code: 86 */
cocos2d::CCRect GameObject::getObjectTextureRect(){
    cocos2d::CCSize size;
    float height;
    if (m_textureRectDirty == false) {
        if (m_objectPosXDirty) {
            m_objectPosXDirty = false;
            m_objectTextureRect.origin.x =  m_lastPositionX - (m_objectTextureRect.size.width * 0.5);
            m_objectTextureRect.origin.y = m_lastPositionY - (m_objectTextureRect.size.height * 0.5);
        }
    }
    else {
        m_textureRectDirty = false;
        m_objectPosXDirty = false;
        if (m_updateCustomContentSize == false) {
            if (m_hasContentSize == false) {
                size = m_size = getContentSize();
            }
            else {
                size = m_size;
            }
            
            if (m_customScaleX != 1.0) {
                size.width = size.width * abs(m_customScaleX);
            }
            height = size.width;
            if (m_customScaleY != 1.0) {
              size.height = size.height * abs(m_customScaleY);
            }
            if (m_objectRectCanRotate == false) {
                height = getRotationX();
                if ((height != 0.0) && (abs(height) != 180.0)) {
                    size.width = sqrtf(size.height * size.height + size.width * size.width);
                    size.height = size.width;
                }
            }
            else {
              size.width = size.height;
              size.height = height;
            }
            m_objectTextureRect.size.width = size.width;
            height = size.width * 0.5;
            m_objectTextureRect.size.height = size.height;
            m_objectTextureRect.origin.x = (m_lastPositionX - height);
            m_objectTextureRect.origin.y = (m_lastPositionY - (size.height * 0.5));
            if (size.width != 30.0 && size.width < 30.0 == size.width) {
                height = height - 15.0;
            }
            if (size.width != 30.0 && size.width < 30.0 == size.width) {
                m_objectTextureRectHeight = height;
            }
        } else {
            m_objectRectDirty = true;
            m_objectTextureRect = getObjectRect();
        }
    }
  
    return m_objectTextureRect;
  
}; 


int GameObject::getObjectZLayer()
{
    return (m_customZLayer) ? m_customZLayer : m_defaultZLayer;
}

int GameObject::getObjectZOrder()
{
    return (m_zOrder) ? m_zOrder :  m_defaultZOrder;
}


OBB2D * GameObject::getOrientedBox()
{
    if ((m_OBB2D == nullptr) || (m_orientedRectDirty)) {
        calculateOrientedBox();
    }
    return m_OBB2D;
}

bool GameObject::getOrientedRectDirty(){
    return m_orientedRectDirty;
}


cocos2d::CCRect GameObject::getOuterObjectRect()
{
    if (m_orientedRectDirty) {
        updateOrientedBox();
    }
    return (m_OBB2D->getBoundingRect());
}

/* TODO: There should be switches when there isn't... */
int GameObject::getParentMode(){

};


float GameObject::getRScaleX()
{ 
    return getScaleX();
}


float GameObject::getRScaleY()
{ 
    return getScaleY();
}


cocos2d::CCPoint GameObject::getRealPosition()
{
  return CCPointMake(m_lastPositionX, m_lastPositionY);
}

GJSpriteColor* GameObject::getRelativeSpriteColor(int ID)
{
    bool isColorObj = isColorObject();
    if ((ID == 2) || (!isColorObj)) {
        return m_detailColor;
    }
    else if (isColorObj) {
        return nullptr;
    }
    return m_baseColor;
}

/* UNKNOWN VALUES MAYBE ITS ZERO? */

static cocos2d::ccHSVValue ccHSVValueZERO = cocos2d::cchsv(0.0, 0.0, 0.0, false, false);


/* Ghidra had this */
// static float DAT_00aa4c04;
// static float DAT_00aa4c08;
// static float DAT_00aa4c0c;
// bool isHSVEqualTo(cocos2d::_ccHSVValue *hsv){
//     short sVar1;
//     if (((hsv->h == DAT_00aa4c04) && (hsv->s == DAT_00aa4c08)) && (hsv->v == DAT_00aa4c0c)) {
//         sVar1._0_1_ = hsv->absoluteSaturation;
//         sVar1._1_1_ = hsv->absoluteBrightness;
//         return sVar1 == _DAT_00aa4c10;
//     }
//     return false;
// }

/* What I think it's referring to... */

bool isHSVEqualTo(cocos2d::_ccHSVValue hsv){
    return hsv.h == ccHSVValueZERO.h && 
        hsv.s == ccHSVValueZERO.s && 
        hsv.v == ccHSVValueZERO.v && 
        hsv.absoluteBrightness == ccHSVValueZERO.absoluteBrightness && 
        hsv.absoluteSaturation == ccHSVValueZERO.absoluteSaturation;
}


// Would Recommend reading https://wyliemaster.github.io/gddocs/#/resources/client/level-components/level-object if you don't understand what this is doing...

std::string GameObject::getSaveString(GJBaseGameLayer* base)
{
    fmt::Writer writer = fmt::BasicWriter<char>();

    /* My goal with this function is to try and not confuse you, I can reformat this later if compiling does not match */

    writer << 1 << "," << m_objectID;
    writer << "," << 2 << "," << (getPosition().x);
    writer << "," << 3 << "," << (getPosition().y - 90.0);

    if (m_disableGlow) {
        writer << "," << 96 << "," << 1;
    }
    
    if (m_isPassable) {
        writer << "," << 134 << "," << m_isPassable;
    }

    if (m_hasExtendedCollision) {
        writer << "," << 511 << "," << m_hasExtendedCollision);
    }
    
    if (m_isNonStickX) {
        writer << "," << 136 << "," << m_isNonStickX);
    }

    if (m_isNonStickY) {
        writer << "," << 289 << "," << m_isNonStickY;
    }
    
    if (m_isExtraSticky) {
        writer << "," << 495 << "," << m_isExtraSticky;
    }
    
    if (m_dontBoost) {
        writer << "," << 496 << "," << m_dontBoost;
    }
    
    if (m_dontBoostX) {
        writer << "," << 509 << "," << m_dontBoostX;
    }
    
    if (m_applyScaleStick) {
        writer << "," << 356 << "," << m_applyScaleStick;
    }

    if (m_hasNoAudioScale) {
        writer << "," << 372 << "," << m_hasNoAudioScale;
    }

    if (m_customColorType != 0) {
        writer << "," << 497 << "," << m_customColorType;
    }

    if (m_iceBlock) {
        writer << "," << 137 << "," << m_iceBlock;
    }

    if (m_isGripSlope) {
        writer << "," << 193 << "," << m_isGripSlope;
    }

    if (m_isNoTouch) {
        writer << "," << 121 << "," << m_isNoTouch;
    }

    if (m_enterChannel != 0) {
        writer << "," << 343 << "," << m_enterChannel;
    }

    if (m_objectMaterial != 0) {
        writer << "," << 446 << "," << m_objectMaterial;
    }
  
    if (isFlipX()) {
        writer << "," << 4 << "," << 1;
    }
    
    if (isFlipY()) {
        writer << "," << 5 << "," << 1;
    }
    if (0 < m_linkedGroup) {
        writer << "," << 108 << "," << m_linkedGroup;
    }

    if (m_editorLayer != 0) {
        writer << "," << 20 << "," << m_editorLayer;
    }

    if (m_editorLayer2 != 0) {
        writer << "," << 61 << "," << m_editorLayer2;
    }

    if (m_isHighDetail) {
        writer << "," << 103 << "," << m_isHighDetail;
    }

    if (m_groupCount > 0) {
        writer << "," << 0x39 << "," << getGroupString();
    }
    if ((m_hasGroupParentsString) && (base != nullptr)) {
        std::string parentStr = base->getGroupParentsString(this);
        if (parentStr.size() != 0) {
            writer << "," << 274 << ","  << parentStr;
        }
    }

    if (m_isDontFade) {
        writer << "," << 64 << "," << 1;
    }

    if (m_isDontEnter) {
        writer << "," << 67 << "," << 1;
    }

    if (m_hideEffects) {
        writer << "," << 116 << "," << m_hideEffects;
    }

    if (m_hasNoParticles) {
        writer << "," << 507 << "," << m_hasNoParticles;
    }

    /* We have yet to hand m_property155, m_property156, m_property53 real names */
    if (0 < m_property155) {
        writer << "," << 155 << "," << m_property155;
    }

    if (0 < m_property156) {
        writer << "," << 156 << "," << m_property156;
    }

    if (m_property53 != 0) {
        writer << "," << 53 << "," << m_property53;
    }
    if (m_zOrder != 0) {
        writer << "," << 0x19 << "," << m_zOrder;
    }

    /* Rotation Variables... */

    float rY = getRotationX();
    float rX = getRotationY();
    rY = rY - (rY / 360.0) * 360;
    rX = rX - (rX / 360.0) * 360;
    if (rY != rY) {
        rY = (rY * 100.0 + 0.5) / 100.0;
    }
    if (rX != rX) {
        rX = (rX * 100.0 + 0.5) / 100.0;
    }
    if (rY == rX) {
        if (rY == 0.0) goto SKIP_131;
        writer << "," << 6 << ",";
    }
    else {
        writer << "," << 131 << "," << rY << "," << 132 << ",";
    }
    writer << rX;

    SKIP_131:
    if (m_baseColor->m_colorID != 0) {
        writer << "," << 21 << "," << m_baseColor->m_colorID;
    }

    if ((m_detailColor != nullptr) && (m_detailColor->m_colorID != 0)) {
        writer << "," << 22 << "," << m_detailColor->m_colorID;
    }

    if (m_customZLayer != 0) {
        writer << "," << 24 << "," << m_customZLayer;
    }

    if (m_customScaleX != 1.0) {
        writer << "," << 128 << "," << m_customScaleX;
    }

    if (m_customScaleY != 1.0) {
        writer << "," << 129 << "," << m_customScaleY;
    }

    if (m_toggleGroupParent) {
        writer << "," << 34 << "," << m_toggleGroupParent;
    }
    
    if (m_toggleAreaParent) {
        writer << "," << 279 << "," << m_toggleAreaParent;
    }

    /* Not sure how GameToolbox::stringFromHSV is supposed to work because In Ghidra it shows up very weirdly... */
    if (!isHSVEqualTo(m_baseColor->m_hsv)) {
        writer << "," << 41 << "," << 1 << "," << 43 << "," << GameToolbox::stringFromHSV(m_basecolor->m_hsv, "\x92");
    }


    if ((m_detailColor != nullptr) && (!isHSVEqualTo(m_detailColor->m_hsv))) {
        writer << "," << 42 << "," << 1 << "," << 44 << "," <<  GameToolbox::stringFromHSV(m_basecolor->m_hsv, "\x92");
    }
    
    std::string saveString = writer.c_str();
    writer.Clear();
    return saveString;
}



cocos2d::CCPoint GameObject::getScalePosDelta()
{
    cocos2d::CCPoint pos = cocos2d::CCPointZero;
    cocos2d::CCRect objRect = getObjectRect();
    
    float height = objRect.size.height;

    if (m_objectRectCanRotate) {
        objRect.size.height = objRect.size.width;
        objRect.size.width = height;
    }

    if (didScaleXChange()) {
        pos.x = (objRect.size.width - (objRect.size.width / m_customScaleX) * m_UnknownScaleX) * 0.5;
    }

    if (didScaleYChange()) {
        pos.y = (objRect.size.height - (objRect.size.height / m_customScaleY) * m_UnknownScaleY) * 0.5;
    }

    if (m_objectRectCanRotate) {
        /* flip pos.y and pos.x around... */
        height = pos.y;
        pos.y = pos.x;
        pos.x = height;
    }

    return pos;
}



GJSpriteColor* GameObject::getSecondaryColor()
{
    return m_detailColor;
}

int GameObject::getSecondaryColorMode()
{
    GJSpriteColor *secondaryColor = getSecondaryColor();
    return (secondaryColor != nullptr) ? secondaryColor->getColorMode() : 0;
}

float GameObject::getSlopeAngle(){
    cocos2d::CCRect rect = getObjectRect();
    return atanf(rect.size.height / rect.size.width);
}

cocos2d::CCPoint GameObject::getStartPos(){
    return m_startPosition;
};


int GameObject::getTextKerning(){
    return 0;
};


int GameObject::getType()
{
    return m_type;
}


cocos2d::CCPoint GameObject::getUnmodifiedPosition(){
    return CCPointMake(
        m_lastPositionX - m_currentPositionX, 
        m_lastPositionY - m_currentPositionY
    )
};

/* TODO: GJEffectManager */
cocos2d::ccColor3B GameObject::groupColor(cocos2d::ccColor3B color, int ID, bool isDetail)
{
    m_color.r = color->r;
    m_color.g = color->g;
    m_color.b = color->b;
    for (int i = 0; i < m_totalColors; i = i + 1) {
        int color = m_effectManager->colorForGroupID(ID, m_color, isDetail);
        m_color.r = color & 0xFF;
        m_color.g = (color >> 8) & 0xFF;
        m_color.b = (color >> 0x10) & 0xFF;
    }
    return m_color;
}



float GameObject::groupOpacityMod()
{
    int size = 0;
    float opacityMod = 1.0;
    while( true ) {
        if (m_opacityGroupSize <= size) {
            return opacityMod;
        }
        opacityMod *= m_effectManager->opacityModForGroup((*m_opacityMod)[size]);
        if (opacityMod <= 0.0) 
            break;
        size++;
    }
    return 0.0;
}



void GameObject::groupWasDisabled()
{
    m_numOfGroups -= 1;
    m_groupDisabled = m_numOfGroups >> 0x1f;
}

void GameObject::groupWasEnabled(){
    m_numOfGroups += 1;
    m_groupDisabled = m_numOfGroups >> 0x1f;
};


bool GameObject::hasBeenActivated(){
    return false;
};


bool GameObject::hasBeenActivatedByPlayer(PlayerObject *player)
{
    return false;
}

bool GameObject::hasSecondaryColor()
{
    return m_colorSprite != nullptr;
}


/* Shoutouts to iAndy_HD3 for helping me figure out what was actually going on here... */

bool GameObject::ignoreEditorDuration()
{

    if (m_type == 30)
        return true;
    if (m_objectID < 287) {
        if (m_objectID < 286) {
            switch (m_objectID) {
                case 10:
                case 11:
                case 12:
                case 13:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 31:
                case 32:
                case 33:
                case 35:
                case 36:
                case 45:
                case 46:
                case 47:
                case 55:
                case 56:
                case 57:
                case 58:
                case 59:
                case 67:
                case 84:
                case 99:
                case 101:
                case 111:
                case 140:
                case 141:
                case 142:
                case 200:
                case 201:
                case 202:
                case 203:
                    return true;
                default:
                    return false;
                }
        }
        return true;
    }
    if (m_objectID < 1935)
    {
        if (m_objectID < 1931)
            return false;
        if (m_objectID > 1585) {
            if (m_objectID > 1704) {
                switch (m_objectID) {
                case 1751:
                case 1755:
                case 1811:
                case 1812:
                case 1813:
                case 1815:
                case 1816:
                case 1817:
                case 1818:
                case 1819:
                case 1829:
                case 1859:
                case 1912:
                case 1915:
                case 1917:
                    return true;
                default:
                    return false;
                }
            }
            if (m_objectID != 1704) {
                switch (m_objectID) {
                    case 1594:
                    case 1595:
                    case 1611:
                    case 1612:
                    case 1613:
                    case 1616:
                        return true;
                    default:
                        return false;
                }
            }
            return true;
        }
        if (m_objectID == 1585)
            return true;
        if (m_objectID <= 1022)
        {
            if (m_objectID < 1022) {
                switch (m_objectID){
                    case 660:
                    case 745:
                    case 747:
                    case 749:
                        return true;
                    default:
                        return false;
                }
            }
            return true;
        }
        if (m_objectID > 1268)
            return m_objectID = 1329 && m_objectID = 1334;
        if (m_objectID == 1268)
            return true;
        return m_objectID == 1049;
    }
    if (m_objectID > 3027)
    {
        if (m_objectID > 3620)
        {
            switch (m_objectID)
            {
            case 3640:
            case 3641:
            case 3642:
            case 3643:
            case 3645:
            case 3655:
            case 3660:
            case 3661:
            case 3662:
                return true;
            default:
                return false;
            }
        }
        if (m_objectID == 3617)
            return true;
        if (m_objectID > 3604)
        {
            switch (m_objectID)
            {
            case 3606:
            case 3607:
            case 3608:
            case 3609:
            case 3612:
            case 3613:
            case 3614:
            case 3615:
                return true;
            default:
                return false;
            }
        }
        if (m_objectID == 3604)
            return true;
        if (m_objectID == 3029)
            return false;
        if (m_objectID == 3033)
            return true;
        return m_objectID == 3600;
    }
    if (m_objectID == 3027)
        return true;
    if (m_objectID > 2900) {
        switch (m_objectID) {
            case 2902:
            case 2903:
            case 2904:
            case 2905:
            case 2907:
            case 2925:
            case 2926:
            case 3004:
            case 3005:
            case 3006:
            case 3007:
            case 3008:
            case 3009:
            case 3010:
            case 3016:
            case 3017:
            case 3018:
            case 3019:
            case 3020:
            case 3021:
            case 3022:
            case 3023:
            case 3024:
                return true;
            default:
                return false;
        }
    }
    if (m_objectID == 2899)
        return true;
    if (m_objectID > 2066)
    {
        if (m_objectID == 2068)
            return false;
        if (m_objectID == 2069)
            return true;
        return m_objectID == 2866;
    }
    if (m_objectID == 2066 || m_objectID == 2016)
        return true;
    if (m_objectID == 2061)
        return false;
    return m_objectID == 2064;
}

bool GameObject::ignoreEnter(){
    return m_ignoreEnter;
}

bool GameObject::ignoreFade()
{
    return m_ignoreFade;
}


bool GameObject::init(char const* frame)
{
    if (CCSpritePlus::initWithSpriteFrameName(frame)) {
        commonSetup();
        // Seems that robtop added a new class member to CCNode 
        // TODO: Add new class member to CCNode.h in Libcocos2d headers
        // (CCNode).m_hasNoManagement = true;
        return true;
    }
    return false;
}


bool GameObject::initWithTexture(,CCTexture2D *texture)
{
  
    if (CCSpritePlus::initWithTexture(texture)) {
        commonSetup();
        return true;
    }
    return false;
}



/* NOTE: This is likely to be a static function... */

bool GameObject::isBasicEnterEffect(int ID)
{
    return ((ID < 0x3c) && ((ID < 0x37) && (6 < ID - 0x16U))) ? false : (ID == 0x77b);
}



bool GameObject::isBasicTrigger()
{  
    bool a, b;
    if (m_objectID < 0x64e) {
        if (0x64b < m_objectID) {
            return true;
        }
        
        if (m_objectID < 0x22) {
            if (0x1f < m_objectID) {
                return true;
            }
            a = 5 < m_objectID - 0x16U;
            b = m_objectID - 0x16U == 6;
        }
        else {
            a = 3 < m_objectID - 0x37U;
            b = m_objectID - 0x37U == 4;
        }
    }
    
    else {
        if (m_objectID == 0x77b) {
            return true;
        }
        if (0x77b < m_objectID) {
            if (m_objectID < 0xbc9) {
                return false;
            }
            if (0xbcd < m_objectID) {
                if (m_objectID != 0xbcf) {
                    return false;
                }
                return true;
            }
            return true;
        }
        a = m_objectID != 0x71a;
        b = m_objectID == 0x71b;
    }
    
    if (!a || b) {
        return true;
    }
    return false;
}


bool GameObject::isColorObject()
{
    if ((((m_customColorType == 0) ? m_isPixelScaleObject : m_customColorType == 1) == false) 
            && (!hasSecondaryColor())) && (m_baseColor->m_defaultColorID  != 0x3ec) {
        if (m_baseColor->m_defaultColorID != 0) {
            return true;
        }
    }
    return false;
}


bool GameObject::isColorTrigger()
{
    bool hasIt;
    if (m_objectID != 0x2e8) {
        if (m_objectID < 0x2e9) {
            if (m_objectID < 0x1d) {
                return false;
            }
            if (m_objectID < 0x1f) {
                return true;
            }
            hasIt = m_objectID == 0x69;
        } else {
            if (m_objectID < 899) {
                return false;
            }
            if (m_objectID < 0x385) {
                return true;
            }
            hasIt = m_objectID == 0x393;
        }
        if (!hasIt) {
            return false;
        }
    }
    return true;
}


bool GameObject::isConfigurablePortal()
{
    bool hasIt;
    if (m_objectID < 0x120) {
        if (0x11d < m_objectID) {
            return true;
        }
        if (m_objectID == 0x2f) {
            return true;
        }
        if (m_objectID < 0x30) {
            if (1 < m_objectID - 0xcU) {
                return false;
            }
            return true;
        }
        hasIt = m_objectID == 0x6f;
    } else {
        if (m_objectID == 0x2e9) {
            return true;
        }
        if (m_objectID < 0x2ea) {
            hasIt = m_objectID == 0x294;
        } else {
            if (m_objectID == 0x533) {
                return true;
            }
            hasIt = m_objectID == 0x78d;
        }
    } 
    return hasIt;
}


/* TODO: Format with 4 spaces... */

bool GameObject::isEditorSpawnableTrigger()
{
    int ID2;
    unsigned int ID;
    bool a;
    bool b;

    if (m_objectID == 0x80e) {
        return true;
    }
    if (0x80e < m_objectID) {
        if (m_objectID == 0xbce) {
            return true;
        }
        if (m_objectID < 0xbcf) {
            if (m_objectID == 0xb5b) {
                return true;
            }
            if (0xb5b < m_objectID) {
                if (m_objectID < 0xb6e) {
                    if (0xb66 < m_objectID) {
                        return true;
                    }
                    b = 7 < m_objectID - 0xb5dU;
                    a = m_objectID - 0xb5dU == 8;
                } else {
                    if (m_objectID == 2999) {
                        return true;
                    }
                    if (m_objectID < 2999) {
                        return false;
                    }
                    b = 9 < m_objectID - 0xbbeU;
                    a = m_objectID - 0xbbeU == 10;
                }
                goto LAB_0035a17e;
            }
            if (m_objectID < 0xb56) {
                if (0xb52 < m_objectID) {
                    return true;
                }
                ID = m_objectID - 0x812;
            } else {
                ID = m_objectID - 0xb57;
            }
        } else {
            if (m_objectID < 0xe20) {
                if (0xe1b < m_objectID) {
                    return true;
                }
                if (m_objectID < 0xbd8) {
                    if (0xbd4 < m_objectID) {
                        return true;
                    }
                    a = m_objectID == 0xbd0;
                    goto RETURN;
                }
                if (m_objectID == 0xbd9) {
                    return true;
                }
                if (m_objectID < 0xbd9) {
                    return false;
                }
                b = 6 < m_objectID - 0xe12U;
                a = m_objectID - 0xe12U == 7;
                goto LAB_0035a17e;
            }
            if (m_objectID < 0xe3a) {
                if (0xe37 < m_objectID) {
                    return true;
                }
                b = 2 < m_objectID - 0xe21U;
                a = m_objectID - 0xe21U == 3;
                goto LAB_0035a17e;
            }
            if (m_objectID == 0xe47) {
                return true;
            }
            if (m_objectID < 0xe47) {
                return false;
            }
            ID = m_objectID - 0xe4c;
        }
    LAB_0035a17c:
        b = 1 < ID;
        a = ID == 2;
    LAB_0035a17e:
        if (b && !a) {
            return false;
        }
        return true;
    }
    if (m_objectID == 0x63b) {
        return true;
    }
    if (m_objectID < 0x63c) {
        if (m_objectID == 0x393) {
            return true;
        }
        if (m_objectID < 0x394) {
            if (m_objectID == 0x69) {
                return true;
            }
            if (m_objectID < 0x6a) {
                ID2 = -0x1d;
            LAB_0035a0aa:
                b = m_objectID + ID2 != 0;
                a = m_objectID + ID2 == 1;
                goto LAB_0035a17e;
            }
            if (m_objectID == 0x2e8) {
                return true;
            }
            if (m_objectID < 0x2e8) {
                return false;
            }
            ID = m_objectID - 899;
            goto LAB_0035a17c;
        }
        if (m_objectID == 0x4f4) {
            return true;
        }
        if (m_objectID < 0x4f5) {
            if (m_objectID < 0x3ee) {
                return false;
            }
            if (m_objectID < 0x3f0) {
                return true;
            }
            ID2 = 0x419;
        }
        else {
            if (m_objectID < 0x542) {
                return false;
            }
            if (m_objectID < 0x544) {
                return true;
            }
            ID2 = 0x631;
        }
    }
    else if (m_objectID < 0x77b) {
        if (0x777 < m_objectID) {
            return true;
        }
        if (m_objectID == 0x713) {
            return true;
        }
        if (m_objectID < 0x714) {
            if (m_objectID < 0x64b) {
                return false;
            }
            if (m_objectID < 0x64e) {
                return true;
            }
            a = m_objectID == 0x650;
            goto RETURN;
        }
        if (m_objectID < 0x716) {
            return false;
        }
        if (m_objectID < 0x718) {
            return true;
        }
        ID2 = 0x719;
    } else {
        if (m_objectID == 0x78c)
        {
            return true;
        }
        if (m_objectID < 0x78d) {
            ID2 = -0x77c;
            goto LAB_0035a0aa;
        }
        if (m_objectID < 0x78e) {
            return false;
        }
        if (m_objectID < 0x790) {
            return true;
        }
        ID2 = 0x7df;
    }
    a = m_objectID == ID2;
RETURN:
    return (!a);
}

/* TODO: Optimize */

bool GameObject::isFacingDown(){
    bool ret;
    int flipY;
    unsigned int rotation;
    
    rotation = (unsigned int)getObjectRotation();
    flipY = isFlipY();
    if (rotation % 0x5a == 0) {
        ret = (rotation ^ (int)rotation >> 0x1f) - ((int)rotation >> 0x1f) == 0xb4;
    } else if (rotation - 0x5b < 0xb3) {
        ret = 1;
    } else {
        rotation = rotation + 0x10d;
        ret = true;
        if (0xb2 < rotation)
        {
            ret = false;
        }
        if (rotation < 0xb3)
        {
            ret = 1;
        }
    } 
    if (flipY != 0) {
        ret = ret ^ 1;
    }
    return ret;
}

/* TODO: Rename inner variables and Optimize code down to be Robtop Accurate*/

bool GameObject::isFacingLeft(){
    bool ret;
    float objectRoation;
    bool flipY;
    bool uVar3;
    int extraout_r1;
    unsigned int objectRoation;

    objectRoation = getObjectRotation();
    flipY = isFlipY();
    uVar3 = (objectRoation % 0x5a) == 0;
    if (uVar3) {
        if ((int)objectRoation < 0) {
            objectRoation = objectRoation + 0x168;
        }
        if (objectRoation == 0x10e) {
            return (bool)((byte)flipY ^ 1);
        }
        if (objectRoation == 0x5a) {
            uVar3 = flipY;
        }
        ret = uVar3 > 0;
        if (objectRoation != 0x5a) {
            ret = false;
        }
    } else {
        if (objectRoation - 0x5b < 0xb3) {
            ret = true;
        } else {
            objectRoation = objectRoation + 0x10d;
            uVar3 = objectRoation;
            if (0xb2 < objectRoation)
            {
                uVar3 = 0;
            }
            ret = uVar3 > 0;
            if (objectRoation < 0xb3)
            {
                ret = true;
            }
        }
        if (flipY != 0)
        {
            return (bool)(ret ^ 1);
        }
    }
    return ret;
}


bool GameObject::isFlipX()
{
    return m_isFlipX;
}


bool GameObject::isFlipY()
{
    return m_isFlipY;
}


bool GameObject::isSettingsObject()
{
    if (m_objectID != 0xe1d) {
        return m_objectID == 0xe4e;
    }
    return true;
}


bool GameObject::isSpawnableTrigger()
{
    return;
}


bool GameObject::isSpecialObject()
{
    return;
}


bool GameObject::isSpecialSpawnObject()
{
    return;
}


bool GameObject::isSpeedObject()
{
    return;
}


bool GameObject::isStoppableTrigger()
{
    return;
}


bool GameObject::isTrigger()
{
    return;
}


void GameObject::loadGroupsFromString(std::string p0)
{
    return;
}



void GameObject::makeInvisible(){
    m_invisible = true;
    m_isNotEditor = true;
    setOpacity(0);
}


void GameObject::makeVisible()
{
    m_invisible = false;
    m_isNotEditor = false;
    setOpacity(255);
}

/* Currently we don't have the right things to get this one done just yet... */
GameObject* GameObject::objectFromVector(std::vector<std::string>& p0, std::vector<void*>& p1, GJBaseGameLayer* p2, bool p3)
{

}

// TODO
// float GameObject::opacityModForMode(, int param_2, bool param_3)

// {
//     float fVar1;
//     CCSprite *sprite;
//     uint uVar2;
//     CCRGBAProtocol_vtable *pCVar3;
//     float mode;

//     if (0 < param_2)
//     {
//         if (param_3)
//         {
//             sprite = (CCSprite *)m_colorSprite1;
//         }
//         else
//         {
//             sprite = (CCSprite *)m_colorSprite2;
//         }
//         pCVar3 = (sprite->getColor();
//         uVar2 = (uint)(0.0 < pCVar3) * (int)pCVar3 & 0xff;
//         if (uVar2 < 0xfa)
//         {
//             mode = (int)uVar2 * 0.004;
//             goto RETURNMODE;
//         }
//     }
//     mode = 1.0;
// RETURNMODE:
//     if (0 < m_opacityGroupSize)
//     {
//         fVar1 = groupOpacityMod(this);
//         mode = mode * fVar1;
//     }
//     return mode;
// }

// TODO
// CCNode *
// GameObject::parentForZLayer(,int zlayer,bool unknown,int parentMode)

// {
//   PlayLayer *this_00;
//   GameManager *GM;
//   CCNode *pCVar1;
//   byte m_isUIObject;
  
//   if (m_isEditor == false) {
//     GM = GameManager::sharedState();
//     m_isUIObject = m_isUIObject;
//     this_00 = GM->m_playLayer;
//   }
//   else {
//     GM = GameManager::sharedState();
//     m_isUIObject = m_isUIObject;
//     this_00 = (PlayLayer *)GM->m_levelEditorLayer;
//   }
//   pCVar1 = GJBaseGameLayer::parentForZLayer
//                      ((GJBaseGameLayer *)this_00,zlayer,unknown,parentMode,(uint)m_isUIObject);
//   return pCVar1;
// }


bool GameObject::particleWasActivated(){
    /* I guess this works? :/ */
    return (bool)(this);
}

/* Unknown Return: GameObject::perspectiveColorFrame(char const* p0, int p1){}; */


/* Unknown Return: GameObject::perspectiveFrame(char const* p0, int p1){}; */

void GameObject::playDestroyObjectAnim(GJBaseGameLayer* p0)
{
    return;
}



/* Unknown Return: GameObject::playPickupAnimation(cocos2d::CCSprite* p0, float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, bool p9, float p10, float p11){}; */


/* Unknown Return: GameObject::playPickupAnimation(cocos2d::CCSprite* p0, float p1, float p2, float p3, float p4){}; */

void GameObject::playShineEffect()
{
    return;
}



void GameObject::quickUpdatePosition()
{
    cocos2d::CCPoint position = CCPointMake(m_lastPositionX, m_lastPositionY);
    setPosition(position);
    if ((m_colorSprite != nullptr) && (m_positionUpdated == false)) {
        m_colorSprite->setPosition(position);
    }
}


void GameObject::quickUpdatePosition2()
{
    m_obPosition.x = m_lastPositionX;
    m_obPosition.y = m_lastPositionY;
}

void GameObject::removeColorSprite()
{
    if (m_colorSprite != nullptr) {
        m_colorSprite->release();
        m_colorSprite = nullptr;
    }
}

/* TODO: I'll do this one tomorrow */
void GameObject::removeFromGroup(int p0)
{
    return;
}




void GameObject::removeGlow()
{
    if (m_glow != nullptr) {
        m_glow->release();
        m_glow->removeMeAndCleanup();
        m_glow = nullptr;
    }
}

void GameObject::reorderColorSprite()
{ 
    return;
}

void GameObject::resetColorGroups()
{
    for (int i = 0; i < m_totalColors; i++) {
        (*m_colorArray)[i] = 0;
    }
    m_totalColors = 0;
}


void GameObject::resetGroupDisabled()
{
    m_numOfGroups = 0;
    m_groupDisabled = false;
}

void GameObject::resetGroups(){
    m_groupCount = 0;
}


static int GLOBAL_MID;

void GameObject::resetMID()
{
    GLOBAL_MID = 10;
}


void GameObject::resetMainColorMode()
{
    GJSpriteColor *mainColor;
    unsigned int colorID;
    mainColor = getMainColor();
    if (mainColor != nullptr) {
        colorID = mainColor->m_defaultColorID;
        if (colorID < 0x44d) {
            colorID = colorID & ~(colorID >> 0x1f);
        }
        else {
            colorID = 0x44d;
        }
        mainColor->m_defaultColorID = colorID;
        mainColor->m_colorID = 0;
    }
}   

void GameObject::resetMoveOffset()
{
    m_lastPositionX = m_startPosition.x;
    m_lastPositionY = m_startPosition.y;
}

/* TODO: 6 Unknown class members That I did not find or name off yet... */
void GameObject::resetObject()
{
    return;
}



void GameObject::resetRScaleForced()
{
    m_fScaleX = 0.0;
    m_fScaleY = 0.0;
    setRScaleX(1.0);
    setRScaleY(1.0);
}

void GameObject::resetSecondaryColorMode()
{
    GJSpriteColor *color;
    unsigned int colorID;

    color = getSecondaryColor(this);
    if (color != nullptr){
        colorID = color->m_defaultColorID;
        if (colorID < 0x44d)
        {
            colorID = colorID & ~((int)colorID >> 0x1f);
        }
        else
        {
            colorID = 0x44d;
        }
        color->m_defaultColorID = colorID;
        color->m_colorID = 0;
    }
}

void GameObject::restoreObject()
{
    m_disabled = false;
    m_invisible = false;
    setOpacity(0xff);
}

void GameObject::saveActiveColors(GameObject *this)

{
    bool rotatesFree;
    int iVar1;
    GameObject *pGVar2;
    GameManager *GM;
    GJSpriteColor *m_detailColor;
    bool is7;

    m_previousType = m_type;
    m_colorMode = getMainColorMode();
    // Not sire what this was about...
    // pGVar2 = getSecondaryColorMode();
    m_baseColorUsesHSV = m_baseColor->m_usesHsv;
    // m_previousObjectState = this; or this..
    if (m_detailColor != nullptr)
    {
        m_detailColor = m_detailColor;
    }
    m_detailColorUsesHSV = m_detailColor > 0;

    // TODO Find GameManager's Class member's name...
    // if (GameManager::sharedState()->field83_0x1c2 == false)
    // {
    //     setupColorSprite(this, m_colorMode, true);
    //     setupColorSprite(this, (int)m_previousObjectState, false);
    // }
    if (m_isDontEnter != false)
    {
        m_ignoreEnter = true;
    }
    if (m_isDontFade != false)
    {
        m_ignoreFade = true;
    }
    if (m_isNoTouch != false)
    {
        m_type = 7;
    }
    rotatesFree = canRotateFree(this);
    is7 = m_type == 7;
    m_isNotDamaging = is7;
    m_isStaticGroup = is7;
    m_isObjectRect2Dirty = rotatesFree;
    if ((m_alwaysHide != false) && (m_isEditor == false))
    {
        m_isNotEditor = true;
    }
}

/* TODO: Has heavy amounts of ghidra type conversions that shouldn't exitst... */
void GameObject::selectObject(cocos2d::ccColor3B p0)
{
    return;
}

// TODO : Unkown Class members related to AreaOpacity apparently... 

// void
// GameObject::setAreaOpacity(float param_2,float param_3_00,int param_4)

// {
//   byte bVar1;
//   float fVar2;
  
//   if ((field290_0x47c != param_4) ||
//      ((int)((uint)(param_3_00 < field289_0x478) << 0x1f) < 0)) {
//     bVar1 = m_opacity;
//     fVar2 = param_2 * (int)(uint)bVar1;
//      setOpacity)(this,(uint)(0.0 < fVar2) * (int)fVar2 & 0xff);
//     m_opacity = bVar1;
//     field290_0x47c = param_4;
//     field289_0x478 = (int)param_3_00;
//   }
//   return;
// }





void GameObject::setChildColor(cocos2d::ccColor3B *color)
{
    unsigned short colorMode;

    if (m_colorSprite != nullptr)
    {
        colorMode = (unsigned short)color->r;
        if (color->r == 0) {
            if ((color->g == 0) && (colorMode = (unsigned short)color->g, color->b == 0)) {
                colorMode = (m_mainChildColorMode == 1) ? 2 : 1;
            }
        } else {
            colorMode = 0;
        }
        m_mainChildColorMode = colorMode;
        m_colorSprite->setColor(color);
        m_colorSprite->setChildColor(color);
    }
}


void GameObject::setCustomZLayer(int zLayer)
{
    if (m_zLayer == 0) {
        m_customZLayer = zLayer;
    }
}



void GameObject::setDefaultMainColorMode(int colorMode){
    GJSpriteColor *color;
    unsigned int colorID;
  
    color = getMainColor();
    if (color != nullptr) {
        color->m_colorID = 0;
        if (colorMode < 0x44d) {
            colorID = colorMode & ~(colorMode >> 0x1f);
        }
        else {
            colorID = 0x44d;
        }
        color->m_defaultColorID = colorID;
    }
}


void GameObject::setDefaultSecondaryColorMode(unsigned int colorMode)
{
    GJSpriteColor *color;
    unsigned int colorID;
  
    color = getSecondaryColor();
    if (color != nullptr) {
        color->m_colorID = 0;
        if (colorMode < 0x44d) {
            colorID = colorMode & ~((int)colorMode >> 0x1f);
        }
        else {
            colorID = 0x44d;
        }
        color->m_defaultColorID = uVar2;
    }
}

void GameObject::setFlipX(bool flipx)
{
    if (m_isFlipX != flipx) {
        m_isFlipX = flipx;
        setScaleX(getScaleX() ^ 0);
    }
}

void GameObject::setFlipX(bool flipy)
{
    if (m_isFlipY != flipy) {
        m_isFlipY = flipy;
        setScaleY(getScaleY() ^ 0);
    }
}


void GameObject::setGlowColor(cocos2d::ccColor3B *color)
{
    if ((m_is1704 == false) && (m_glow != nullptr)) {
        m_glow->setColor(color);
        m_glow->setChildColor(color);
    }
}


void GameObject::setGlowOpacity(unsigned char opacity)
{
    uint _opacity;
    float newOpacity;

    if (m_glow != nullptr) {
        newOpacity = (int)(uint)opacity * m_glowOpacityMultiplier;
        _opacity = (int)(0.0 < newOpacity) * (int)newOpacity & 0xff;
        m_glow->setOpacity(_opacity);
        m_glow->setChildOpacity(_opacity);
    }
}

/* Todo: Rename m_position to m_lastPosition */

void GameObject::setLastPosition(CCPoint *lastPosition)
{
    m_position = lastPosition;
}


void GameObject::setMainColorMode(int colorMode)
{
    GJSpriteColor *color = getMainColor(this);
    if (color != nullptr) {
        color->SetColorIDForMode(colorMode);
    }
}

/* TODO: it's just big... */
void GameObject::setObjectColor(cocos2d::ccColor3B const& p0)
{
    return;
}


void GameObject::setObjectLabel(CCLabelBMFont *font)
{
    /* NOOP */
    return;
}



void GameObject::setObjectRectDirty(bool dirty)
{
    m_objectRectDirty = dirty;
}

/* TODO: Big function */
void GameObject::setOpacity(unsigned char p0)
{
    return;
}


void GameObject::setOrientedRectDirty(bool dirty)
{
    m_orientedBoxDirty = dirty;
}

// TODO
// void GameObject::setPosition(cocos2d::CCPoint const &position)
// {
//     cocos2d::CCParticleSystem *m_particles;
//     cocos2d::CCSprite *sprite;
//     CCSpritePlus::setPosition(position);
//     if (m_particles != nullptr)
//     {
//         if (((m_obPortalPosition).x == 0.0) && ((m_obPortalPosition).y == 0.0)){
//             m_particles->vtable->cocos2d_CCNode_setPosition)(m_particles, position);
//         } else {
//             cocos2d::CCNode::convertToWorldSpace((CCNode *)&local_3c, (CCPoint *)this);
//             cocos2d::CCNode::convertToWorldSpace((CCNode *)&local_34, (CCPoint *)this);
        
//             pcVar2 = (code *)m_particles->vtable->cocos2d_CCNode_setPosition;
//             cocos2d::CCPoint::CCPoint(&CStack_2c, (position->x + local_3c) - local_34,
//                                       (position->y + local_38) - local_30);
//             (*pcVar2)(m_particles, &CStack_2c);
//         }
//     }
//     sprite = m_glow;
//     if (sprite != nullptr)
//     {
//         sprite->setPosition(position);
//     }
//     sprite = m_colorSprite;
//     if ((sprite != nullptr) && (m_positionUpdated == false)) {
//         sprite->setPosition(position);
//     }
//     return;
// }


void GameObject::setRotation(float rotation)
{
    cocos2d::CCSprite *sprite;

    if ((m_fRotationX != rotation) || (m_fRotationY != rotation))
    {
        m_objectRectDirty = true;
        m_orientedBoxDirty = true;
        m_textureRectDirty = true;

        CCSpritePlus::setRotation(rotation);
        
        sprite = m_glow;
        if (sprite != nullptr) {
            sprite->setRotation(rotation);
        }
        
        sprite = m_colorSprite;
        if ((sprite != nullptr) && (m_positionUpdated == false)) {
            sprite->setRotation(rotation);
        }

        if ((m_particles != nullptr) && (m_noRotation == false)) {
            m_particles->setRotation(rotation);
        }

        if ((((rotation == 90.0) || (rotation == -90.0)) || (rotation == 270.0)) || (rotation == -270. 0)) {
            m_objectRectCanRotate = true;
        } else {
            m_objectRectCanRotate = false;
        }
    }
}

void GameObject::setRRotation(float rrotation)
{
    float updatedRoatation;
    float _newRRotation;

    updatedRoatation = m_defaultRotationX + m_UnkownRotation;
    _newRRotation = updatedRoatation + rrotation;
    if (updatedRoatation == m_defaultRotationY + m_defaultRoation)
    {
        setRotation(_newRRoation);
    } else {
        setRotationX(_newRRotation);
        setRotationY(m_defaultRotationY + m_defaultRoation + rrotation);
    }
}


void GameObject::setRScale(float p0)
{
    return;
}


void GameObject::setRScaleX(float p0)
{
    return;
}


void GameObject::setRScaleY(float p0)
{
    return;
}


void GameObject::setRotation(float p0)
{
    return;
}



void GameObject::setRotationX(float rotation)
{
    cocos2d::CCSprite *sprite;

    if (m_fRotationX != rotation){
        m_objectRectDirty = true;
        m_orientedBoxDirty = true;
        m_textureRectDirty = true;

        CCSpritePlus::setRotationX(rotation);
        
        sprite = m_glow;
        if (sprite != nullptr) {
            sprite->setRotationX(rotation);
        }
        
        sprite = m_colorSprite;
        if ((sprite != nullptr) && (m_positionUpdated == false)) {
            sprite->setRotationX(rotation);
        }

        if ((m_particles != nullptr) && (m_noRotation == false)) {
            m_particles->setRotationX(rotation);
        }

        if ((((rotation == 90.0) || (rotation == -90.0)) || (rotation == 270.0)) || (rotation == -270. 0)) {
            m_objectRectCanRotate = true;
        } else {
            m_objectRectCanRotate = false;
        }
    }
}



void GameObject::setRotationX(float rotation)
{
    cocos2d::CCSprite *sprite;

    if (m_fRotationY != rotation){
        m_objectRectDirty = true;
        m_orientedBoxDirty = true;
        m_textureRectDirty = true;

        CCSpritePlus::setRotationY(rotation);
        
        sprite = m_glow;
        if (sprite != nullptr) {
            sprite->setRotationY(rotation);
        }
        
        sprite = m_colorSprite;
        if ((sprite != nullptr) && (m_positionUpdated == false)) {
            sprite->setRotationY(rotation);
        }

        if ((m_particles != nullptr) && (m_noRotation == false)) {
            m_particles->setRotationY(rotation);
        }

        if ((((rotation == 90.0) || (rotation == -90.0)) || (rotation == 270.0)) || (rotation == -270. 0)) {
            m_objectRectCanRotate = true;
        } else {
            m_objectRectCanRotate = false;
        }
    }
}


void GameObject::setScale(float p0)
{
    return;
}


void GameObject::setScaleX(float p0)
{
    return;
}


void GameObject::setScaleY(float p0)
{
    return;
}


void GameObject::setSecondaryColorMode(int p0)
{
    return;
}


void GameObject::setStartPos(cocos2d::CCPoint p0)
{
    return;
}


void GameObject::setType(GameObjectType p0)
{
    return;
}


void GameObject::setVisible(bool p0)
{
    return;
}



/* Unknown Return: GameObject::setupColorSprite(int p0, bool p1){}; */

void GameObject::setupCustomSprites(std::string p0)
{
    return;
}



/* Unknown Return: GameObject::setupPixelScale(){}; */


/* Unknown Return: GameObject::setupSpriteSize(){}; */


/* Unknown Return: GameObject::shouldBlendColor(GJSpriteColor* p0, bool p1){}; */


/* Unknown Return: GameObject::shouldDrawEditorHitbox(){}; */


/* Unknown Return: GameObject::shouldLockX(){}; */


/* Unknown Return: GameObject::shouldNotHideAnimFreeze(){}; */


/* Unknown Return: GameObject::shouldShowPickupEffects(){}; */


/* Unknown Return: GameObject::slopeFloorTop(){}; */


/* Unknown Return: GameObject::slopeWallLeft(){}; */


/* Unknown Return: GameObject::slopeYPos(cocos2d::CCRect p0){}; */


/* Unknown Return: GameObject::slopeYPos(float p0){}; */


/* Unknown Return: GameObject::slopeYPos(GameObject* p0){}; */


/* Unknown Return: GameObject::spawnDefaultPickupParticle(GJBaseGameLayer* p0){}; */


/* Unknown Return: GameObject::spawnXPosition(){}; */


/* Unknown Return: GameObject::transferObjectRect(cocos2d::CCRect& p0){}; */

void GameObject::triggerActivated(float p0)
{
    return;
}


void GameObject::triggerObject(GJBaseGameLayer* p0, int p1, std::vector<int> const* p2)
{
    return;
}



/* Unknown Return: GameObject::unclaimParticle(){}; */

void GameObject::update(float p0)
{
    return;
}



void GameObject::updateBlendMode()
{
    m_shouldBlendBaseColor = shouldBlendColor(m_baseColor,true);
    if (m_colorSprite == nullptr) {
        m_shouldBlendBaseColor = false;
    }
    else if (m_detailColor->getColorMode() != 0x3f4) {
        m_shouldBlendDetailColor = shouldBlendColor(m_detailColor,false);
    }
}


void GameObject::updateCustomColorType(short type)
{ 
    m_customColorType = type;
    m_isDetailOnly = getRelativeSpriteColor(true) == nullptr;
}   

void GameObject::updateCustomScaleX(float x)
{
    long _x = lroundf(x * 1000.0);
    m_fScaleX = 0.0;
    m_customScaleX = _x / 1000.0;
    m_UnknownScaleX = _x / 1000.0;
    setRScaleX(1);
    m_textureRectDirty = true;
    m_objectRectDirty = true;
}

void GameObject::updateCustomScaleY(float y)
{
    long _y = lroundf(y * 1000.0);
    m_fScaleY = 0.0;
    m_customScaleY = _y / 1000.0;
    m_UnknownScaleY = _y / 1000.0;
    setRScaleY(1);
    m_textureRectDirty = true;
    m_objectRectDirty = true;
}


void GameObject::updateHSVState()
{
    if (m_baseColor != nullptr) {
        m_baseColor->m_usesHsv = !isHSVEqualTo(&m_baseColor->m_hsv);
    }
    if (m_detailColor != nullptr) {
        m_detailColor->m_usesHsv = !isHSVEqualTo(&m_detailColor->m_hsv);
    }
}

void GameObject::updateIsOriented()
{    
    m_oriented = false;
    if ((m_type != 7) && canRotateFree()) {
        if ((getRotation() % 90) && (m_objectRadius <= 0.0)) {
            calculateOrientedBox();
        }
    }
}

void GameObject::updateMainColor(const cocos2d::ccColor3B &color)
{
    setObjectColor(color);
}

void GameObject::updateMainColor()
{
    updateMainColor(colorForMode(m_colorMode,true));
    updateMainOpacity();
}


void GameObject::updateMainColorOnly()
{
    if (((m_colorMode != 0) && (m_totalColors != 0)) && (m_opacityGroupSize != 0))  {
        updateMainColor(colorForMode(m_colorMode,true));    
    }
}

void GameObject::updateMainOpacity()
{
    m_baseColor->m_opacity = opacityModForMode(m_colorMode,true);
}


void GameObject::updateMainParticleOpacity(unsigned char opacity);
{
  return /* NOOP */;
}

void GameObject::updateObjectEditorColor()
{
    GameObject *child;

    int mode = m_baseColor->getColorMode();
    if (mode == m_baseColor->m_defaultColorID) {
        mode = 0;
    }
    unsigned int color = editorColorForMode(mode);
    setObjectColor(cocos2d::ccc3((color >> 16), (color >> 8) & 0xFF, (color & 0xFF)));
    if (m_colorSprite != nullptr) {
        m_baseColor = m_detailColor;
        mode = m_baseColor->getColorMode();
        if (mode == m_baseColor->m_defaultColorID) {
            mode = 0;
        }
        color = editorColorForMode(mode);
        updateSecondaryColor(cocos2d::ccc3((color >> 16), (color >> 8) & 0xFF, (color & 0xFF)));
    }
    if ((m_hasDetailFrame != false) && (child = reinterpret_cast<GameObject *>(getChildByTag(999)), child != nullptr)) {
        // UNKNOWN VARAIBLE! child->getTexture(&DAT_0098ac40);
    }
}


void GameObject::updateOrientedBox(){
    if (m_OBB2D == nullptr) {
        m_OBB2D = OBB2D::create(getRealPosition() + getBoxOffset(), m_spriteSizeWidth * m_OBB2DWidth * m_customScaleX,
                                m_spriteSizeHeight * m_OBB2DHeight * m_customScaleY,
                                -(getObjectRotation() * 0.01745329));
        m_OBB2D->retain();
    } else if (m_orientedRectDirty) {
        m_OBB2D->calculateWithCenter(getRealPosition() + getBoxOffset(), m_spriteSizeWidth * m_OBB2DWidth * m_customScaleX,
               m_spriteSizeHeight * m_OBB2DHeight * m_customScaleY,-(getObjectRotation() * 0.01745329)) ;
        m_orientedRectDirty = false;
    }
}


void GameObject::updateParticleColor(cocos2d::ccColor3B const &color)
{
    if (m_particles != nullptr) {
        m_particles->setStartColor(cocos2d::ccc4f(color.r / 255.0, color.g / 255.0, color.b / 255.0, 1));
        m_particles->setEndColor(cocos2d::ccc4f(color.r / 255.0, color.g / 255.0, color.b / 255.0, 0));
    }
}

void GameObject::updateParticleOpacity(unsigned char opacity)
{
    if (m_particles != nullptr){
        if ((opacity < 0x33) && (m_particles->isActive()))
        {
            m_particles->stopSystem();
        } else if ((isVisible()) && (m_particles->isActive())){
            m_particles->resumeSystem();
        }
    }
}

void GameObject::updateSecondaryColor() {
    if ((hasSecondaryColor()) && ((m_previousObjectState != nullptr) || (m_groupCount != 0))){
        updateSecondaryColor(colorForMode(m_previousObjectState, false));
        updateSecondaryOpacity();
    }
}

void GameObject::updateSecondaryColor(cocos2d::ccColor3B const& color){
    setChildColor(color);
}



void GameObject::updateSecondaryColorOnly()
{
    if ((hasSecondaryColor(this)) && ((m_previousObjectState != nullptr || (m_groupCount != 0))) )
    {
        updateSecondaryColor(colorForMode(m_previousObjectState, false));
    }
}

void GameObject::updateSecondaryOpacity(){
    m_detailColor->m_opacity = opacityModForMode(m_previousObjectState,false);
}

void GameObject::updateSecondaryParticleOpacity(unsigned char opacity)
{
    return /* NOOP */;
}


void GameObject::updateStartPos()
{
    cocos2d::CCPoint pos = getPosition();
    startPosX = m_startPosition.x;
    x = m_lastPositionX - startPosX;
    pos.x = pos.x - x;
    startPosY = m_startPosition.y;
    y = m_lastPositionY - startPosY;
    pos.y = pos.y - y;
    if ((startPosX != pos.x) || (startPosY != pos.y)) {
        m_objectRectDirty = true;
        m_orientedBoxDirty = true;
        m_textureRectDirty = true;
        m_lastPositionX = pos.x + x;
        m_lastPositionY = pos.y + y;
        m_startPosition = pos;
    }
}

void GameObject::updateStartValues(GameObject *this)
{
    updateStartPos();
    m_defaultFlipX = isFlipX();
    m_defaultFlipY = isFlipY(); 
    float rotationX = getRotationX();
    float rotationY =  getRotationY();
    if (rotationX == rotationY){
        if (m_UnknownRotation != 0.0)
        {
            rotation = roundf(rotationX - m_UnknownRotation);
        }
        m_defaultRotationX = rotationX;
    }
    else
    {
        m_defaultRotation = m_defaultRoation;
        if ((m_UnknownRotation == 0.0) && (m_defaultRotation == 0.0))
        {
            m_defaultRotationX = rotationX;
            m_defaultRotationY = rotationY;
            goto EXIT;
        }
        rotationX = roundf(rotationX - m_UnknownRotation);
        m_defaultRotationX = rotation;
        rotationY = roundf(rotationY - m_defaultRotation);
    }
    m_defaultRotationY = rotationY;
EXIT:
    m_defaultScaleX = m_customScaleX - m_scaleXInc;
    m_defaultScaleY = m_customScaleY - m_scaleYInc;
}

void GameObject::updateTextKerning(int kerning)
{
    return /* NOOP */;
}

void GameObject::updateUnmodifiedPositions()
{
    if (m_unmodifiedPositionsDirty != false) {
        m_unmodifiedPositionsDirty = false;
        m_unmodifiedPositionX = (m_lastPositionX - m_currentPositionX );
        m_unmodifiedPositionY = (m_lastPositionY - m_currentPositionY );
    }
}

/* TODO */
/* Unknown Return: GameObject::usesFreezeAnimation(){}; */


bool GameObject::usesSpecialAnimation()
{
    if (m_objectID < 1843) {
        if (((m_objectID < 1839) && (m_objectID != 1591)) && (m_objectID != 0x639)) {
            return false;
        }
    } else if ((m_objectID - 2892) > 1) {
        return false;
    }
    return true;
}

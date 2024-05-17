#include "includes.h"


CCLightStrip* CCLightStrip::create(float width, float toWidth, float toHeight, float duration, float delay){ 
    CCLightStrip* obj = new CCLightStrip; 
    if ((obj != nullptr) && obj->init(width, toWidth, toHeight, duration, delay)){ 
        obj->autorelease(); 
        return obj; 
    }
    CC_SAFE_DELETE(obj);
    return nullptr;
}

bool CCLightStrip::init(float width, float toWidth, float toHeight, float duration, float delay){
    m_toWidth = toWidth;
    m_objectWidth = width;
    m_toHeight = toHeight;
    m_height = 1.0;
    m_width = width;
    m_opacity = 255.0;
    m_duration = duration;
    setVisible(0);
    cocos2d::CCDirector::sharedDirector()->getActionManager()->addAction(
        cocos2d::CCSequence::create(
            cocos2d::CCDelayTime::create(delay),
            cocos2d::CCShow::create(), 
            cocos2d::CCSpawn::create(
                cocos2d::CCEaseOut::create(cocos2d::CCActionTween::create(duration,"height", m_height, m_toHeight), 2.0f),
                cocos2d::CCEaseOut::create(cocos2d::CCActionTween::create(duration,"width", m_width, m_toWidth), 2.0f),
                0
            ),
            0
        ), 
        this,
        false
    );
    return true;
}   


void CCLightStrip::draw(){
    if (isVisible()) {
        cocos2d::ccGLBlendFunc(2, 1);
        cocos2d::ccDrawColor4B(m_color.r,m_color.g,m_color.b, (0.0 < m_opacity) * m_opacity);
        float unk = m_objectWidth + (m_width - m_objectWidth) * 0.25;
        cocos2d::CCPoint poli[4] = {
            CCPointMake(-( unk * 0.5) , 0.0),
            CCPointMake(unk * 0.5,0.0),
            CCPointMake(m_width * 0.5, m_height),
            CCPointMake(-(m_width * 0.5),m_height)
        };
        cocos2d::ccDrawSolidPoly(poli, 4, cocos2d::ccc4f(m_color.r / 255.0, m_color.g / 255.0 , m_color.b / 255.0, m_opacity / 255.0));
        cocos2d::ccGLBlendFunc(1, 3);
    }
}


void CCLightStrip::updateTweenAction(float value, const char* keyword){
    if (keyword == std::string("height")){
        m_height = value;
    } else if (keyword == std::string("width")){
        m_width = value;
    } else if (keyword == std::string("opacity")) {
        m_opacity = value;
    }
}

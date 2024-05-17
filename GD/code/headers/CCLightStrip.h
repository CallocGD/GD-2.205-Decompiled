#ifndef __CCLIGHTSTRIP_H__
#define __CCLIGHTSTRIP_H__

#include "includes.h"

/* So, This object is basically used with Lightning Objects from what I can tell */

class CCLightStrip : public cocos2d::CCNode {
public:

    CCLightStrip() = default;

    CCLightStrip * create (float width, float toWidth, float toHeight, float duration, float delay);
    bool init(float width, float toWidth, float toHeight, float duration, float delay);
    void draw();
    void updateTweenAction(float value,const char *keyword);

    float m_objectWidth;
    float m_toWidth;
    float m_toHeight;	
    float m_duration;
	cocos2d::ccColor4B m_color;
    float m_opacity;
    float m_width;
    float m_height;	

};


#endif // __CCLIGHTSTRIP_H__

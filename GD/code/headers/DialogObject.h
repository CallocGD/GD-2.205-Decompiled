#ifndef __DIALOGOBJECT_H__
#define __DIALOGOBJECT_H__

#include "includes.h"

class DialogObject : public cocos2d::CCObject {
    public:
        std::string m_text;
        std::string m_npcName;
        int m_dialogType;
        cocos2d::ccColor3B m_color;
        float m_textWidth;
        bool m_canSkip;

        static DialogObject* create(
            std::string npc, 
            std::string text, 
            int type, 
            float width, 
            bool canSkip, 
            cocos2d::ccColor3B colour
        );

        bool init(
            std::string npc, 
            std::string text, 
            int type, 
            float width, 
            bool canSkip, 
            cocos2d::ccColor3B colour
        );

};



#endif // __DIALOGOBJECT_H__


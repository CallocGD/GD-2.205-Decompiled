#include "../headers/includes.h"

DialogObject* DialogObject::create(std::string npc, std::string text, int type, float width, bool canSkip, cocos2d::ccColor3B color)
{
	auto pRet = new DialogObject;

	if (pRet && pRet->init(npc, text, type, width, canSkip, colour))
	{
		pRet->autorelease();
		return pRet;
	}

	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool DialogObject::init(std::string npc, std::string text, int type, float width, bool canSkip, cocos2d::ccColor3B colour)
{
	m_npcName = npc;
	m_text = text;
	m_dialogType = type;
	m_textWidth = width;
	m_canSkip = canSkip;
	m_color = colour;
	return true;
}


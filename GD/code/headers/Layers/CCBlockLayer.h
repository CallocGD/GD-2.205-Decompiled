#ifndef __CCBLOCKLAYER_H__
#define __CCBLOCKLAYER_H__

#include "../includes.h"

class CCBlockLayer : public cocos2d::CCLayerColor {
	// virtual ~CCBlockLayer();
public:
	static CCBlockLayer* create();
    CCBlockLayer(): 
        m_isShowing(false), 
        m_unregistered(false) 
    {}

	void decrementForcePrio();
	void incrementForcePrio();

	virtual bool init();
	virtual void draw();
	virtual bool ccTouchBegan(cocos2d::CCTouch*, cocos2d::CCEvent*);
	virtual void ccTouchMoved(cocos2d::CCTouch*, cocos2d::CCEvent*) {}
	virtual void ccTouchEnded(cocos2d::CCTouch*, cocos2d::CCEvent*) {}
	virtual void ccTouchCancelled(cocos2d::CCTouch*, cocos2d::CCEvent*) {}
	virtual void registerWithTouchDispatcher();
	virtual void keyBackClicked();
	virtual void customSetup() {}
	virtual void enterLayer();
	virtual void exitLayer();
	virtual void showLayer(bool);
	virtual void hideLayer(bool);
	virtual void layerVisible();
	virtual void layerHidden();
	virtual void enterAnimFinished() {}
	virtual void disableUI() {}
	virtual void enableUI() {}

	bool m_isShowing;
    bool m_unregistered;
};



#endif // __CCBLOCKLAYER_H__

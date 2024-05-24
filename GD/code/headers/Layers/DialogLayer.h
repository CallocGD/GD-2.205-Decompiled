#ifndef __DIALOGLAYER_H__
#define __DIALOGLAYER_H__

#include "../includes.h"

enum DialogAnimationType {
    kDialogAnimationTypeInstant = 0,
    kDialogAnimationTypeFromCenter = 1,
    kDialogAnimationTypeFromLeft = 2,
    kDialogAnimationTypeFromRight = 3,
    kDialogAnimationTypeFromTop = 4,
    kDialogAnimationTypeFromBottom = 5,
};

enum DialogChatPlacement {
	kDialogChatPlacementCenter = 0,
	kDialogChatPlacementTop = 1,
	kDialogChatPlacementBottom = 2
};


class DialogLayer : public cocos2d::CCLayerColor, public TextAreaDelegate {
	// virtual ~DialogLayer();
public:
	static DialogLayer* create(DialogObject* object , int frameID);

	void addToMainScene();
	void animateIn(DialogAnimationType type);
	void animateInDialog();
	void animateInRandomSide();
	static DialogLayer* createDialogLayer(DialogObject*, cocos2d::CCArray*, int);
	static DialogLayer* createWithObjects(cocos2d::CCArray* objects, int frameID);
	void displayDialogObject(DialogObject*);
	void displayNextObject();
	void finishCurrentAnimation();
	void handleDialogTap();
	bool init(DialogObject*, cocos2d::CCArray*, int);
	void onClose();
	void updateChatPlacement(DialogChatPlacement);
	void updateNavButtonFrame();


	virtual void onEnter();
	virtual bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void ccTouchCancelled(cocos2d::CCTouch* touch, cocos2d::CCEvent* event);
	virtual void registerWithTouchDispatcher();
	virtual void keyBackClicked();
	virtual void keyDown(cocos2d::enumKeyCodes);
	virtual void fadeInTextFinished(TextArea* textArea);

    float m_time;
    cocos2d::CCLayer *	m_mainLayer;
    cocos2d::CCLabelBMFont * m_label;	
    TextArea * m_textArea;
    cocos2d::CCSprite* m_icon;
    cocos2d::CCArray* m_objects;	
    int	m_id;
    cocos2d::CCSprite *	m_sprite;
    bool m_animationRunning;
    bool m_hasMoreDialog;
    DialogDelegate * m_dialogDelegate;
	/* IDK What to name this one... */
    bool m_unkBool;	
    DialogAnimationType	m_animationType;
    bool m_loadOnNextScene;
};

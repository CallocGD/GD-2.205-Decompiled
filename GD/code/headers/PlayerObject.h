#include "includes.h"

// dump from ida. the chars are either pad or bools, i just havent checked them. very very subject to change

struct __cppobj __attribute__((aligned(4))) PlayerObject : GameObject
{
	AnimatedSpriteDelegate* m_pAnimatedSpriteDelegate;
	_DWORD dword4;
	_DWORD dword8;
	double dwordC;
	_DWORD dword14;
	_DWORD dword18;
	cocos2d::CCDictionary* dword1C;
	cocos2d::CCDictionary* dword20;
	float m_fAutoCheckPointInterval;
	_DWORD dword28;
	bool m_bAutoCheckpointEnabled;
	GameObject* m_pObject;
	_DWORD dword34;
	int m_nCurrentIcon;
	_DWORD dword3C;
	_DWORD dword40;
	_DWORD dword44;
	_DWORD dword48;
	_DWORD dword4C;
	_DWORD dword50;
	char dword54;
	bool m_bNotOnSlope;
	char field_482;
	char field_483;
	GameObject* m_pCollidedSlope;
	_DWORD dword5C;
	_DWORD dword60;
	int m_nSlopeUniqueID;
	bool m_bGoingDown;
	char field_495;
	char field_496;
	char field_497;
	cocos2d::CCArray* m_pParticleArray;
	bool m_bGlow;
	bool m_bVisibility;
	char field_49E;
	char field_49F;
	GhostTrailEffect* m_pGhostTrail;
	cocos2d::CCSprite* m_pIcon;
	cocos2d::CCSprite* m_pIconSecondary;
	cocos2d::CCSprite* m_pIconWhitener;
	cocos2d::CCSprite* m_pIconExtra;
	cocos2d::CCSprite* m_pVehicle;
	cocos2d::CCSprite* m_pVehicleSecondary;
	_DWORD dword90;
	cocos2d::CCSprite* m_pVehicleWhitener;
	cocos2d::CCSprite* m_pVehicleExtra;
	_DWORD dword9C;
	cocos2d::CCMotionStreak* m_pTrail;
	HardStreak* m_pWaveTrail;
	HardStreak* m_pHardStreak;
	double m_dXAcceleration;
	double m_dJumpAcceleration;
	double m_dGravity;
	float dwordC4;
	float m_fSafeModeTime;
	char dwordCC;
	char field_4F9;
	char field_4FA;
	char field_4FB;
	bool m_bJumped;
	char field_4FD;
	char field_4FE;
	char field_4FF;
	bool dwordD4;
	_DWORD dwordD8;
	double dwordDC;
	_DWORD dwordE4;
	_DWORD dwordE8;
	double m_dTimeCopy;
	double m_dTimeCopy2;
	float dwordFC;
	float dword100;
	cocos2d::ccColor3B m_cFirstColour;
	cocos2d::ccColor3B m_cSecondColour;
	double m_dSafeSpiderTime;
	_DWORD dword114;
	_DWORD dword118;
	_DWORD dword11C;
	_DWORD dword120;
	_DWORD dword124;
	_DWORD dword128;
	_DWORD dword12C;
	GameObject* m_pObject1;
	CheckpointObject* m_pPendingCheckpoint;
	int m_nCheckpointTotal;
	GJRobotSprite* m_pRobotSprite;
	GJRobotSprite* m_pSpiderSprite;
	_DWORD dword144;
	cocos2d::CCParticleSystem* m_pParticles;
	cocos2d::CCParticleSystem* m_pParticle1;
	cocos2d::CCParticleSystem* m_pParticle2;
	cocos2d::CCParticleSystem* m_pParticle3;
	cocos2d::CCParticleSystem* m_pBurstEffect;
	cocos2d::CCParticleSystem* m_pParticle5;
	cocos2d::CCParticleSystem* m_pParticle7;
	_DWORD dword164;
	cocos2d::CCParticleSystem* m_pParticle4;
	cocos2d::CCParticleSystem* m_pParticle6;
	float dword170;
	float dword174;
	int m_nStreakID;
	float m_fStreakStroke;
	_DWORD dword180;
	_DWORD dword184;
	_DWORD dword188;
	_DWORD dword18C;
	char dword190;
	char field_5BD;
	bool m_bBumpPlayer;
	bool m_bSlopeFlippedX;
	float m_fTop;
	float m_fBottom;
	_DWORD dword19C;
	_DWORD dword1A0;
	bool m_bTookDamage;
	bool m_bUpKeyDown;
	bool m_bUpKeyPressed;
	char field_5D3;
	char dword1A8;
	char field_5D5;
	char field_5D6;
	char field_5D7;
	int m_nUnkSeed;
	int m_nUnkRand;
	_DWORD dword1B4;
	_DWORD dword1B8;
	double m_dYAccel;
	bool m_bOnSlope;
	bool m_bWasOnSlope;
	float m_fSlopeYVelocity;
	bool m_bFlyMode;
	bool m_bBirdMode;
	bool m_bRollMode;
	bool m_bDartMode;
	bool m_bRobotMode;
	bool m_bSpiderMode;
	bool m_bGravity;
	bool m_bTouchedRing;
	bool m_bCanJump;
	bool m_bDashing;
	char field_602;
	char field_603;
	float m_fPlayerScale;
	float m_fTimeMod;
	cocos2d::CCPoint m_obLastPos;
	cocos2d::CCPoint m_onPortalPos;
	cocos2d::CCLayer* m_pGameLayer;
	bool m_bOnGround;
	bool m_bJumping;
	bool m_bLocked;
	cocos2d::CCPoint m_obLastGroundPos;
	cocos2d::CCArray* m_pTouchedRings;
	GameObject* m_pLastActivatedPortal;
	bool m_bHasJumped;
	bool m_bHasRingJumped;
	cocos2d::ccColor3B m_cColour;
	cocos2d::ccColor3B m_cColour2;
	cocos2d::CCPoint m_obRealPlayerPos;
	bool m_bIsSecondPlayer;
	bool m_bTwoPlayer;
	double m_dTime;
	char m_bDisableEffects;
	float m_fMeteringValue;
	float m_fGroundHeight;
	float m_fLastYVelocity;
	cocos2d::CCPoint m_obPosition;
	_DWORD dword23C;
	_DWORD dword240;
	_DWORD dword244;
	_DWORD dword248;
	_DWORD dword24C;
	_DWORD dword250;
	_DWORD dword254;
	_DWORD dword258;
	_DWORD dword25C;
	_DWORD dword260;
	_DWORD dword264;
	_DWORD dword268;
	_DWORD dword26C;
	_DWORD dword270;
	_DWORD dword274;
	_DWORD dword278;
	_DWORD dword27C;
	_DWORD dword280;
	_DWORD dword284;
	_DWORD dword288;
	_DWORD dword28C;
	_DWORD dword290;
	_DWORD dword294;
	_DWORD dword298;
	_DWORD dword29C;
	_DWORD dword2A0;
	_DWORD dword2A4;
	_DWORD dword2A8;
	_DWORD dword2AC;
	_DWORD dword2B0;
	_DWORD dword2B4;
	_DWORD dword2B8;
	_DWORD dword2BC;
	_DWORD dword2C0;
	_DWORD dword2C4;
	_DWORD dword2C8;
	_DWORD dword2CC;
	_DWORD dword2D0;
	_DWORD dword2D4;
	_DWORD dword2D8;
	_DWORD dword2DC;
	_DWORD dword2E0;
	_DWORD dword2E4;
	_DWORD dword2E8;
	_DWORD dword2EC;
	_DWORD dword2F0;
	_DWORD dword2F4;
	_DWORD dword2F8;
	_DWORD dword2FC;
	_DWORD dword300;
	_DWORD dword304;
	_DWORD dword308;
	_DWORD dword30C;
	_DWORD dword310;
	_DWORD dword314;
	_DWORD dword318;
	_DWORD dword31C;
	_DWORD dword320;
	_DWORD dword324;
	_DWORD dword328;
	_DWORD dword32C;
	_DWORD dword330;
	_DWORD dword334;
	_DWORD dword338;
	_DWORD dword33C;
	_DWORD dword340;
	_DWORD dword344;
	_DWORD dword348;
	_DWORD dword34C;
	_DWORD dword350;
	_DWORD dword354;
	_DWORD dword358;
	_DWORD dword35C;
	_DWORD dword360;
	_DWORD dword364;
	_DWORD dword368;
	_DWORD dword36C;
	_DWORD dword370;
	_DWORD dword374;
	_DWORD dword378;
	_DWORD dword37C;
	_DWORD dword380;
	_DWORD dword384;
	_DWORD dword388;
	_DWORD dword38C;
	_DWORD dword390;
	_DWORD dword394;
	_DWORD dword398;
	_DWORD dword39C;
	_DWORD dword3A0;
	_DWORD dword3A4;
	_DWORD dword3A8;
	_DWORD dword3AC;
	_DWORD dword3B0;
	_DWORD dword3B4;
	_DWORD dword3B8;
	_DWORD dword3BC;
	_DWORD dword3C0;
	_DWORD dword3C4;
	_DWORD dword3C8;
	_DWORD dword3CC;
	_DWORD dword3D0;
	_DWORD dword3D4;
	_DWORD dword3D8;
	_DWORD dword3DC;
	_DWORD dword3E0;
	_DWORD dword3E4;
	_DWORD dword3E8;
	_DWORD dword3EC;
	_DWORD dword3F0;
	_DWORD dword3F4;
	_DWORD dword3F8;
	_DWORD dword3FC;
	_DWORD dword400;
	_DWORD dword404;
	_DWORD dword408;
	_DWORD dword40C;
	_DWORD dword410;
	_DWORD dword414;
	_DWORD dword418;
	_DWORD dword41C;
	_DWORD dword420;
	_DWORD dword424;
	_DWORD dword428;
	_DWORD dword42C;
	_DWORD dword430;
	_DWORD dword434;
	_DWORD dword438;
	_DWORD dword43C;
	_DWORD dword440;
	_DWORD dword444;
	_DWORD dword448;
	_DWORD dword44C;
	_DWORD dword450;
	_DWORD dword454;
	_DWORD dword458;
	_DWORD dword45C;
	_DWORD dword460;
	_DWORD dword464;
	_DWORD dword468;
	_DWORD dword46C;
	_DWORD dword470;
	_DWORD dword474;
	_DWORD dword478;
	_DWORD dword47C;
	_DWORD dword480;
	_DWORD dword484;
	_DWORD dword488;
	_DWORD dword48C;
	_DWORD dword490;
	_DWORD dword494;
	_DWORD dword498;
	_DWORD dword49C;
	_DWORD dword4A0;
	_DWORD dword4A4;
	_DWORD dword4A8;
	_DWORD dword4AC;
	_DWORD dword4B0;
	_DWORD dword4B4;
	_DWORD dword4B8;
	_DWORD dword4BC;
	_DWORD dword4C0;
	_DWORD dword4C4;
	_DWORD dword4C8;
	_DWORD dword4CC;
	_DWORD dword4D0;
	_DWORD dword4D4;
	_DWORD dword4D8;
	_DWORD dword4DC;
	_DWORD dword4E0;
	_DWORD dword4E4;
	_DWORD dword4E8;
	_DWORD dword4EC;
	_DWORD dword4F0;
	_DWORD dword4F4;
	_DWORD dword4F8;
	_DWORD dword4FC;
	_DWORD dword500;
	_DWORD dword504;
	_DWORD dword508;
	_DWORD dword50C;
	_DWORD dword510;
	_DWORD dword514;
	_DWORD dword518;
	_DWORD dword51C;
	_DWORD dword520;
	_DWORD dword524;
	_DWORD dword528;
	_DWORD dword52C;
	_DWORD dword530;
	_DWORD dword534;
	_DWORD dword538;
	_DWORD dword53C;
	_DWORD dword540;
	_DWORD dword544;
	_DWORD dword548;
	_DWORD dword54C;
	_DWORD dword550;
	_DWORD dword554;
	_DWORD dword558;
	int m_nStateBlockDash;
	_DWORD dword560;
	int m_nStateBlockJump;
	int m_nStateBlockWave;
	int m_nStateBlockHead;
	_DWORD dword570;
};

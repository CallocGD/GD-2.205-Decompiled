#include "includes.h"

class CCNodeContainer;
class OBB2D;
class GJEffectManager;
class PlayerObject;
class LevelSettingsObject;
class TriggerEffectDelegate;

// size is 0x2CC
class GJBaseGameLayer : public cocos2d::CCLayer, TriggerEffectDelegate
{
public:
    OBB2D* m_pOBB2D;
    GJEffectManager* m_pEffectManager;
    cocos2d::CCLayer* m_pObjectLayer;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddTop4;
    cocos2d::CCSpriteBatchNode* m_pEffectBatchNodeAddTop4;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeTop3;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddTop3;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddGlowTop3;
    CCNodeContainer* m_pBatchNodeTop3Container;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeTextTop3;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddTextTop3;
    cocos2d::CCSpriteBatchNode* m_pEffectBatchNodeTop3;
    cocos2d::CCSpriteBatchNode* m_pEffectBatchNodeAddTop3;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeTop2;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddTop2;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddGlowTop2;
    CCNodeContainer* m_pBatchNodeTop2Container;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeTextTop2;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddTextTop2;
    cocos2d::CCSpriteBatchNode* m_pEffectBatchNodeTop2;
    cocos2d::CCSpriteBatchNode* m_pEffectBatchNodeAddTop2;
    cocos2d::CCSpriteBatchNode* m_pBatchNode;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAdd;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddGlow;
    CCNodeContainer* m_pBatchNodeTop1Container;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeTextTop1;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddTextTop1;
    cocos2d::CCSpriteBatchNode* m_pEffectBatchNodeTop1;
    cocos2d::CCSpriteBatchNode* m_pEffectBatchNodeAddTop1;
    cocos2d::CCSpriteBatchNode* m_pBatchNodePlayer;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddPlayer;
    cocos2d::CCSpriteBatchNode* m_pBatchNodePlayerGlow;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddMid;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeBot;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddBot;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddBotGlow;
    CCNodeContainer* m_pBatchNodeBot1Container;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeText;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddText;
    cocos2d::CCSpriteBatchNode* m_pEffectBatchNode;
    cocos2d::CCSpriteBatchNode* m_pEffectBatchNodeAdd;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeBot2;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddBot2;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddBot2Glow;
    CCNodeContainer* m_pBatchNodeBot2Container;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeTextBot2;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddTextBot2;
    cocos2d::CCSpriteBatchNode* m_pEffectBatchNodeBot2;
    cocos2d::CCSpriteBatchNode* m_pEffectBatchNodeAddBot2;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeBot3;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddBot3;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddBot3Glow;
    CCNodeContainer* m_pBatchNodeBot3Container;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeTextBot3;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddTextBot3;
    cocos2d::CCSpriteBatchNode* m_pEffectBatchNodeBot3;
    cocos2d::CCSpriteBatchNode* m_pEffectBatchNodeAddBot3;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeBot4;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddBot4;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddBot4Glow;
    CCNodeContainer* m_pBatchNodeBot4Container;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeTextBot4;
    cocos2d::CCSpriteBatchNode* m_pBatchNodeAddTextBot4;
    cocos2d::CCSpriteBatchNode* m_pEffectBatchNodeBot4;
    cocos2d::CCSpriteBatchNode* m_pEffectBatchNodeAddBot4;
    PlayerObject* m_pPlayer1;
    PlayerObject* m_pPlayer2;
    LevelSettingsObject* m_pLevelSettings;
    cocos2d::CCDictionary* m_pDisabledGroupsDictMaybe;
    cocos2d::CCArray* m_pObjects;
    cocos2d::CCArray* m_pSectionObjectsArray;
    cocos2d::CCArray* m_pSections;
    cocos2d::CCArray* m_pCollisionBlocksArray;
    cocos2d::CCArray* m_pSpawnObjectsArray;
    cocos2d::CCArray* m_pUnkArr4;
    cocos2d::CCNode* m_pGroupNodes;
    std::vector<GameObject*> m_pGameObjects;
    std::vector<GameObject*> m_pDisabledObjects;
    cocos2d::CCDictionary* m_pGroupDict;
    cocos2d::CCDictionary* m_pStaticGroupDict;
    cocos2d::CCDictionary* m_pOptimisedGroupDict;
    std::vector<cocos2d::CCArray*> m_pGroups;
    std::vector<cocos2d::CCArray*> m_pStaticGroups;
    std::vector<cocos2d::CCArray*> m_pOptimisedGroups;
    cocos2d::CCArray* m_pBatchNodeArray;
    cocos2d::CCArray* m_pProcessedGroups;
    cocos2d::CCDictionary* m_pCounterDict;
    cocos2d::CCDictionary* m_pSpawnedGroups;
    bool m_bUpdatedNormalCapacity;
    bool m_bTwoPlayer;
    int m_nUnk;
    bool m_bActiveDualTouch;
    int m_nPushedButtons;
    int m_nCurrentSection;
    int m_nOldSection;
    bool m_bDisabledObjects;
    bool m_bBlending;
    BYTE PAD2[10];

    GJBaseGameLayer();
    void enableHighCapacityMode();
    std::string getCapacityString();
    int atlasValue(int _batchNodeCapacity);
    cocos2d::CCArray* getGroup(int _idx);
    cocos2d::CCArray* getStaticGroup(int _idx);
    cocos2d::CCArray* getOptimizedGroup(int _idx);
    void updateLegacyLayerCapacity(int _top, int _topBlending, int _bot, int _botBlending);
    void updateLayerCapacity(std::string _capacityString);
    void createTextLayers();
    void setupLayers();
    void updateOBB2D(cocos2d::CCRect);
    void collectItem(int, int);
    void updateCounters(int, int);
};

#ifndef __INCLUDES_H__
#define __INCLUDES_H__

// External Resources
#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#endif
#include <fmt/format.h>
#include <string>
#include <cstdlib>
#include <cocos2d.h>
#include "enums.h"

// unorganised,  TODO: Organizing all of these A-Z would be better :)
#include "custom.h"
#include "GJRewardItem.h"
#include "GJRewardObject.h"
#include "GJObjectDecoder.h"
#include "GJChallengeItem.h"
#include "delegates.h"
#include "DialogObject.h"
#include "GJMapPack.h"
#include "GJGameLevel.h"
#include "GJHttpResult.h"
#include "LevelSettingsObject.h"
#include "ObjectToolbox.h"
#include "GameObject.h"
#include "LoadingCircle.h"
#include "EffectGameObject.h"
#include "CCTextInputNode.h"
#include "CheckpointObject.h"
#include "PlayerCheckpoint.h"
#include "SimplePlayer.h"
#include "GJComment.h"
#include "SongObject.h"
#include "GJUserScore.h"
#include "SongInfoObject.h"
#include "GJUserMessage.h"
#include "PlayerObject.h"
#include "GhostTrailEffect.h"
#include "UndoObject.h"
#include "GJSearchObject.h"
#include "AchievementBar.h"
#include "AchievementNotifier.h"
#include "GJStoreItem.h"
#include "ButtonSprite.h"
#include "MultilineBitmapFont.h"
#include "ColoredSection.h"
#include "InstantSection.h"
#include "DelaySection.h"
#include "LevelPage.h"
#include "OBB2D.h"
#include "rtsha1.h"
#include "GameToolbox.h"
#include "ShaderLayer.h"
#include "TextArea.h"
#include "TextStyleSection.h"
#include "FontObject.h"
#include "CCSpritePlus.h"
#include "FLAlertLayer.h"
#include "CCMenuSpriteExtra.h"
#include "InfoAlertButton.h"
#include "CCMenuItemToggler.h"
#include "CCMenuSpriteExtra.h"
#include "LevelTools.h"
#include "CCCircleWave.h"
#include "CCScrollLayerExt.h"
#include "TableView.h"
#include "GameToolbox.h"
#include "AdToolBox.h"
#include "GJFriendRequest.h"
#include "GJLevelList.h"
#include "DailyLevelNode.h"
#include "DailyLevelPage.h"
#include "UploadActionPopup.h"
#include "PlatformToolbox.h"
#include "GJValueTween.h"
#include "GJSpriteColor.h"
#include "CCLightStrip.h"


// Layer Related Classes

#include "Layers/AccountLayer.h"
#include "Layers/AccountHelpLayer.h"
#include "Layers/AccountLoginLayer.h"
#include "Layers/AccountRegisterLayer.h"
#include "Layers/DialogLayer.h"
#include "Layers/DrawGridLayer.h"
#include "Layers/EditorUI.h"
#include "Layers/GJBaseGameLayer.h"
#include "Layers/GJDropDownLayer.h"
#include "Layers/GJGarageLayer.h"
#include "Layers/GJGroundLayer.h"
#include "Layers/InfoLayer.h"
#include "Layers/LevelEditorLayer.h"
#include "Layers/LevelSelectLayer.h"
#include "Layers/LevelSettingsLayer.h"
#include "Layers/MenuLayer.h"
#include "Layers/NumberInputLayer.h"
#include "Layers/PauseLayer.h"
#include "Layers/PlayLayer.h"
#include "Layers/SecretLayer.h"
#include "Layers/SetGroupIDLayer.h"
#include "Layers/SetIDLayer.h"
#include "Layers/UILayer.h"
#include "Layers/ShareLevelLayer.h"
#include "Layers/ShareCommentLayer.h"
#include "Layers/ShaderLayer.h"
#include "Layers/BoomScrollLayer.h"
#include "Layers/LikeItemLayer.h"
#include "Layers/RewardUnlockLayer.h"
#include "Layers/GJListLayer.h"
#include "Layers/EndLevelLayer.h"
#include "Layers/MultiplayerLayer.h"
/* This one might possibly one of Robtop's Secret tools */
#include "Layers/LevelFeatureLayer.h"
#include "Layers/DialogLayer.h"
#include "Layers/CCBlockLayer.h"


// Manager related classes

#include "Managers/AchievementManager.h"
#include "Managers/GameLevelManager.h"
#include "Managers/GJAccountManager.h"
#include "Managers/GJEffectManager.h"
#include "Managers/GameManager.h"
#include "Managers/GManager.h"
#include "Managers/GJMultiplayerManager.h"
#include "Managers/LocalLevelManager.h"
#include "Managers/GameStatsManager.h"
#include "Managers/FileSaveManager.h"


// Cell related classes

#include "Cells/AchievementCell.h"
#include "Cells/ArtistCell.h"
#include "Cells/BoomListView.h"
#include "Cells/CommentCell.h"
#include "Cells/CustomSongCell.h"
#include "Cells/GameCell.h"
#include "Cells/GJLevelScoreCell.h"
#include "Cells/GJMessageCell.h"
#include "Cells/GJRequestCell.h"
#include "Cells/GJScoreCell.h"
#include "Cells/GJUserCell.h"
#include "Cells/LevelCell.h"
#include "Cells/ListCell.h"
#include "Cells/MapPackCell.h"
#include "Cells/SongCell.h"
#include "Cells/StatsCell.h"
#include "Cells/TableViewCell.h"


// UI Related Classes

#include "UI/UIButtonConfig.h"
#include "UI/GJUINode.h"


/* TODO: Move GJHttpType to enums.h */

enum GJHttpType
{
    kGJHttpTypeUploadLevel = 0x1,
    kGJHttpTypeGetOnlineLevels = 0x2,
    kGJHttpTypeGetMapPacks = 0x3,
    kGJHttpTypeDownloadLevel = 0x4,
    kGJHttpTypeUpdateLevel = 0x5,
    kGJHttpTypeRateStars = 0x6,
    kGJHttpTypeDeleteServerLevel = 0x7,
    kGJHttpTypeSetLevelStars = 0x8,
    kGJHttpTypeSetLevelFeatured = 0x9,
    kGJHttpTypeUpdateUserScore = 0xA,
    kGJHttpTypeGetLeaderboardScores = 0xB,
    kGJHttpTypeGetLevelComments = 0xC,
    kGJHttpTypeUploadComment = 0xD,
    kGJHttpTypeDeleteComment = 0xE,
    kGJHttpTypeLikeItem = 0xF,
    kGJHttpTypeRestoreItems = 0x10,
    kGJHttpTypeSubmitUserInfo = 0x11,
    kGJHttpTypeReportLevel = 0x12,
    kGJHttpTypeGetSongInfo = 0x13,
    kGJHttpTypeBackupAccount = 0x14,
    kGJHttpTypeSyncAccount = 0x15,
    kGJHttpTypeRegisterAccount = 0x16,
    kGJHttpTypeLoginAccount = 0x17,
    kGJHttpTypeUpdateDescription = 0x18,
    kGJHttpTypeGetAccountComments = 0x19,
    kGJHttpTypeUpdateAccountSettings = 0x1A,
    kGJHttpTypeGetGJUserInfo = 0x1B,
    kGJHttpTypeGetFriendRequests = 0x1C,
    kGJHttpTypeUploadFriendRequest = 0x1D,
    kGJHttpTypeDeleteFriendRequest = 0x1E,
    kGJHttpTypeAcceptFriendRequest = 0x1F,
    kGJHttpTypeReadFriendRequest = 0x20,
    kGJHttpTypeRemoveFriend = 0x21,
    kGJHttpTypeBlockUser = 0x22,
    kGJHttpTypeUnblockUser = 0x23,
    kGJHttpTypeGetUserList = 0x24,
    kGJHttpTypeGetUserMessages = 0x25,
    kGJHttpTypeDownloadUserMessage = 0x26,
    kGJHttpTypeDeleteUserMessages = 0x27,
    kGJHttpTypeUploadUserMessage = 0x28,
    kGJHttpTypeGetUsers = 0x29,
    kGJHttpTypeBanUser = 0x2A,
    kGJHttpTypeRequestUserAccess = 0x2B,
    kGJHttpTypeGetLevelSaveData = 0x2C,
    kGJHttpTypeSuggestLevelStars = 0x2D,
    kGJHttpTypeGetGJRewards = 0x2E,
    kGJHttpTypeGetGJChallenges = 0x2F,
    kGJHttpTypeGetGJDailyLevelState = 0x30,
    kGJHttpTypeUnknown49 = 0x31,
    kGJHttpTypeRateDemon = 0x32,
    kGJHttpTypeGetLevelLeaderboard = 0x33,
    kGJHttpTypeGetGauntlets = 0x34,
    kGJHttpTypeGetTopArtists = 0x35,
    kGJHttpTypeGetAccountBackupURL = 0x36,
    kGJHttpTypeGetAccountSyncURL = 0x37,


    kGJHTTPTypejoinLobby = 0x39,
    kGJHTTPTypeExitMPLobby = 0x3a,
    
    kGJHTTPTypeDeleteServerLevelList = 0x3e,
};

#endif // __INCLUDES_H__

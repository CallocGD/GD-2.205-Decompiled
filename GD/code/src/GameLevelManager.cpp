/* Simple rewrite of the GameLevelManager's code in alphabetical order... */

#include "../headers/includes.h"
#include "cocos2d/cocos-headers/cocos2dx/support/zip_support/ZipUtils.h"
#include <cocos-ext.h>
#include "GameToolbox.h"
#include "custom.h"
#include "rtsha1.h"


/* To make things less Confusing and make the code more condensed... */
#define Wmfd2893gb7 cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfd", "2893", 'g', 'b', "7")->getCString()
#define xI25fpAapCQg cocos2d::CCString::createWithFormat("%c%s%s%c%c%s",'x',"I25","fpAa",'p','C',"Qg")->getCString()


/* Robtop does not like to handle server stuff as far as I have been aware 
 * thanks to some knowlege of some other people so I wrote this Macro to help 
 * with formatting some of these http requests off without loosing any of the 
 * compiled information and keeping this file as condensed as possible without 
 * losing the Readability of the original code */
#define FORMAT_HTTP_REQUEST(FORMAT, ...) getBasePostString() + cocos2d::CCString::createWithFormat(FORMAT, __VA_ARGS__)->getCString()


void GameLevelManager::acceptFriendRequest(int targetAccountID, int requestID)
{
    if (0 < targetAccountID && 0 < requestID)
    {
        auto key = cocos2d::CCString::createWithFormat("accFriendReq_%i_%i", targetAccountID, requestID)->getCString();
        m_friendReqAndUserBlocks->setObject(cocos2d::CCNode::create(),key);
        ProcessHttpRequest(
            "https://www.boomlings.com/database/acceptGJFriendRequest20.php", 
            FORMAT_HTTP_REQUEST("&targetAccountID=%i&requestID=%i&secret=%s", targetAccountID, requestID, Wmfd2893gb7), key, kGJHttpTypeAcceptFriendRequest);
    }
}



int GameLevelManager::accountIDForUserID(int userID)
{
    return m_accountIDtoUserIDDict->valueForKey(userID)->intValue();
}


void GameLevelManager::addDLToActive(const char *tag)
{
    m_downloadObjects->setObject(cocos2d::CCNode::create(), tag);
}

/* Beleive an overload function exists as well... - Calloc */
void GameLevelManager::addDLToActive(cocos2d::CCNode *obj, const char *_tag)
{
    m_downloadObjects->setObject(obj, _tag);
}



bool GameLevelManager::areGauntletsLoaded()
{
    return m_gauntletLevels->count() > 0;
}



void GameLevelManager::banUser(int p0)
{
    return;
}


void GameLevelManager::blockUser(int accountID)
{
    if (accountID > 0)
    {
        /* If the user is now blocked in our blacklist do this...*/
        auto blockedUserKey = cocos2d::CCString::createWithFormat("blockUser_%i", accountID)->getCString();
        if (m_friendReqAndUserBlocks->objectForKey(blockedUserKey) == nullptr)
        {
            /* Set the user as being blocked... */
            m_friendReqAndUserBlocks->setObject(cocos2d::CCNode::create(), blockedUserKey);
            ProcessHttpRequest(
                "https://www.boomlings.com/database/blockGJUser20.php", 
                FORMAT_HTTP_REQUEST("&targetAccountID=%i&secret=%s", accountID, Wmfd2893gb7) , 
                blockedUserKey, 
                kGJHttpTypeBlockUser
            );
        }
    }
}


void GameLevelManager::cleanupDailyLevels()
{
    auto array = this->m_dailyLevels->allKeys();
    /* There's some unknown names so I'm going to use these letters for the time being... */
    unsigned int a = 0, b = 0, c, d, e;
    for (unsigned int i= 0; i < array->count(); i++) {
        unsigned int count = array->count(); 
        const char* key = reinterpret_cast<cocos2d::CCString *>(array->objectAtIndex(i))->getCString();
        GJGameLevel* level= reinterpret_cast<GJGameLevel*>(m_dailyLevels->objectForKey(key));
        auto dailyID = level->m_dailyID_Random - level->m_dailyID_Seed;
        if (dailyID < 0x186a1) {
            e = dailyID;
            d = b;
            c = a;
        }
        if (dailyID < c) {
            level->m_levelNotDownloaded = true;
            level->m_dontSave = true;
            if (level->m_newNormalPercent_Random - level->m_newNormalPercent_Seed < 1) {
                this->m_dailyLevels->removeObjectForKey(key);
            }
            e = a;
            d = b;
        }
        a = e;
        b = d;
    }
}



cocos2d::CCArray * splittoCCArray(std::string str,char *delimiter)
{
    cocos2d::CCArray *array;
    size_t pos;
    size_t npos;
    size_t start = 0;
    array = cocos2d::CCArray::create();
    pos = str.find(delimiter,0);
    npos = str.size();
    while( true ) {
        auto substr = str.substr(start, pos - start);
        if (substr != "" || start != npos) {
            array->addObject(cocos2d::CCString::create(substr));
        }
        if (pos == 0xffffffff) break;
        start = pos + 1;
        pos = str.find(delimiter, start);
    }
    return array;
}


cocos2d::CCArray* GameLevelManager::createAndGetAccountComments(std::string commentData, int accountID)
{
    return createAndGetCommentsFull(commentData, accountID, true);
}


cocos2d::CCArray* GameLevelManager::createAndGetCommentsFull(std::string data, int ID, bool profileComment)
{   
    GJComment* comment;
    GJUserScore* user;
    cocos2d::CCArray* comments = cocos2d::CCArray::create();
    cocos2d::CCArray* raw_comments = splittoCCArray(data, "|");

    for (unsigned int i = 0; i < raw_comments->count(); i++) {
        std::string s = reinterpret_cast<cocos2d::CCString*>(raw_comments->objectAtIndex(i))->getCString();
        if (profileComment){
             comment = GJComment::create(responseToDict(s, true));
            if (comment != nullptr){
                comment->m_accountID = ID;
                comments->addObject(comment);
            }
        } else {
            auto UserAndComment = splittoCCArray(s,":");
            if (UserAndComment->count() > 1){
                comment = GJComment::create(responseToDict(UserAndComment->stringAtIndex(0)->getCString()));
                user = GJUserScore::create(responseToDict(UserAndComment->stringAtIndex(1)->getCString()));
                if (user != nullptr) {
                    if (comment->m_userScore != user) {
                        user->retain();
                        if (comment->m_userScore != nullptr) {
                            comment->m_userScore->release();
                        }
                        comment->m_userScore = user;
                    }
                }
                storeUserName(comment->m_userID,comment->m_accountID, user->m_userName);
            }
            if (comment != nullptr){
                comment->m_levelID = ID;
                comments->addObject(comment);
            }
        }
    }
    return comments;
}


cocos2d::CCArray* GameLevelManager::createAndGetLevelComments(std::string commentData, int levelID)
{
    return createAndGetCommentsFull(commentData, levelID, false);
}


cocos2d::CCArray* GameLevelManager::createAndGetLevelLists(std::string response)
{
    auto lists = cocos2d::CCArray::create();
    cocos2d::CCArray* array = splittoCCArray(response,"|");
    for (unsigned int i = 0; i < array->count(); i++) {
        GJLevelList* obj = GJLevelList::create(responseToDict(reinterpret_cast<cocos2d::CCString*>(array->objectAtIndex(i))->getCString(),false));
        if (obj != nullptr) {
            lists->addObject(obj);
        }
    }
    return lists;
}



cocos2d::CCArray * GameLevelManager::createAndGetLevels(std::string response)
{
    cocos2d::CCArray* array = cocos2d::CCArray::create();
    cocos2d::CCArray* raw_levels = splittoCCArray(response, "|");
    for (unsigned int i = 0; i < raw_levels->count(); i++) {
        GJGameLevel* obj = GJGameLevel::create(responseToDict(reinterpret_cast<cocos2d::CCString *>(raw_levels->objectAtIndex(i))->getCString(), false), true);
        if (obj != nullptr) {
            array->addObject(obj);
        }
    }
    return array;
}


cocos2d::CCArray * GameLevelManager::createAndGetMapPacks(std::string resp)
{
    cocos2d::CCArray* mappacks = cocos2d::CCArray::create();
    cocos2d::CCArray* array = splittoCCArray(resp, "|");
    for (unsigned int i = 0; i < array->count(); i++) {
        dict = responseToDict(cocos2d::CCString::getCString(cocos2d::CCArray::objectAtIndex(array,uVar2)),false);
        GJMapPack* mappack = GJMapPack::create(dict);
        if (mappack != nullptr) {
            cocos2d::CCArray::addObject(mappacks, mappack);
        }
    }
    return mappacks;
}



cocos2d::CCArray * GameLevelManager::createAndGetScores(std::string response, GJScoreType scoreType)
{
    cocos2d::CCArray* scores = cocos2d::CCArray::create();
    cocos2d::CCArray* raw_scores = splittoCCArray(response,"|");
    for (unsigned int i = 0; i < raw_scores->count(); i++) {
        GJUserScore* score = GJUserScore::create(
            responseToDict(reinterpret_cast<cocos2d::CCString*>(raw_scores->objectAtIndex(i))->getCString(),false)
        );
        if (score != nullptr) {
            score->m_scoreType = (int)scoreType;
            scores->addObject(score);
            storeUserName(score->m_userID,score->m_accountID, score->m_userName);
        }
    }
    return scores;
}

GJGameLevel* GameLevelManager::createNewLevel()
{
    bool limit;
    cocos2d::CCObject* obj;
    auto newLevel = GJGameLevel::create();
    newLevel->m_levelType = (GJLevelType)2 /* TODO */;
    newLevel->m_isEditable = true;
    newLevel->m_creatorName = GameManager::sharedState()->m_playerUDID;
    auto dict = LocalLevelManager::sharedState()->getAllLevelsInDict();
    unsigned int unamedId = 0;

    while (obj != nullptr && limit) {
        const char* name = cocos2d::CCString::createWithFormat("Unnamed %i", unamedId)->getCString();
        obj = dict->objectForKey(name);
        /* Pretty weird that robtop would stop at 999 levels I wonder if he thought people wouldn't make more than that... - Calloc */
        limit = unamedId < 999;
        if (obj == nullptr || !limit) {
            newLevel->m_tempName = name;
        }
        unamedId++;
    }
    LocalLevelManager::sharedState()->m_localLevels->insertObject(newLevel, 0);
    return newLevel;
}

/* TODO: "createNewLevelList()" It's a little bit bigger than I expected at the moment but it will be done 
 * unless someone else would like a shot at it... */
GJLevelList* GameLevelManager::createNewLevelList()
{
    return;
}



std::string GameLevelManager::createPageInfo(int Requested, int pageSum, int CurrentPage)
{
    return cocos2d::CCString::createWithFormat("%i%s%i%s%i", Requested, ":", pageSum, ":", CurrentPage)->getCString();
}


GJSmartTemplate* GameLevelManager::createSmartTemplate()
{
    return;
}

/* TODO: This one is a Bigass Maze of 500+ lines */
bool GameLevelManager::dataLoaded(DS_Dictionary* dsdict)
{

}


void GameLevelManager::deleteAccountComment(int ID, int commentID)
{
    return deleteComment(commentID, kCommentTypeAccountType, ID);
}


void GameLevelManager::deleteComment(int commentID, CommentType Ctype, int ID)
{
    const char *key = getDeleteCommentKey(ID, commentID, Ctype);
    
    if (m_friendReqAndUserBlocks->objectForKey(key) == NULL)
    {
        m_friendReqAndUserBlocks->setObject(cocos2d::CCNode::create(), key);
        std::string postStr = FORMAT_HTTP_REQUEST("&commentID=%i&secret=%s", commentID, Wmfd2893gb7);
        if (Ctype == kCommentTypeLevelType) {
            postStr += "&levelID=";
        } else {
            postStr += "&cType=";
            postStr += cocos2d::CCString::createWithFormat("%i", Ctype)->getCString();
            postStr += "&targetAccountID=";
        }
        postStr += cocos2d::CCString::createWithFormat("%i", ID)->getCString();
        ProcessHttpRequest((Ctype) ?"https://www.boomlings.com/database/deleteGJComment20.php" : "https://www.boomlings.com/database/deleteGJAccComment20.php", postStr, key, kGJHttpTypeDeleteComment);
    }
}


unsigned int GameLevelManager::deleteFriendRequests(int targetAccountID, cocos2d::CCArray *selectedFriendRequests, bool isSender)
{
    GJFriendRequest* friendReq;
    std::string postData;
    /* TODO: Get rid of goto part if possible... */
    if (selectedFriendRequests == nullptr) {
      postData = "";
      if (0 < targetAccountID)
        goto DELETE_FRIEND_REQUESTS;

    } else { 
        if (selectedFriendRequests->count() == 1) {
            friendReq = reinterpret_cast<GJFriendRequest *>(selectedFriendRequests->objectAtIndex(0));
            targetAccountID = friendReq->m_fromAccountID;
            if (0 < targetAccountID) {
                selectedFriendRequests = nullptr;
            }
            DELETE_FRIEND_REQUESTS: 
                auto key = cocos2d::CCString::createWithFormat("delFriendReq_%i_%i", targetAccountID, isSender)->getCString();
                if (m_friendReqAndUserBlocks->objectForKey(key) == nullptr) {
                    m_friendReqAndUserBlocks->setObject(cocos2d::CCNode::create(), key);
                    postData = FORMAT_HTTP_REQUEST("&targetAccountID=%i&isSender=%i&secret=%s",targetAccountID, isSender, Wmfd2893gb7);
                    
                    /* "DDOS Prevention, Smart stuff Robtop" - Calloc */
                    if (selectedFriendRequests != nullptr){
                        postData += "&accounts=";
                        for (unsigned int i = 0; i < selectedFriendRequests->count(); i++) {
                            friendReq = reinterpret_cast<GJFriendRequest *>(selectedFriendRequests->objectAtIndex(i));
                            if (selectedFriendRequests->count() != 0) {
                                postData += ",";
                            }
                            postData += cocos2d::CCString::createWithFormat("%i", friendReq->m_fromAccountID)->getCString();             
                        }
                    }
                    ProcessHttpRequest(
                        "https://www.boomlings.com/database/deleteGJFriendRequests20.php", postData, key, 
                        kGJHttpTypeDeleteFriendRequest);
                }
        }
    }
}

void GameLevelManager::deleteLevel(GJGameLevel *level)
{
    /* is the level local or online? */
    if (level->m_levelType == 2) {
        LocalLevelManager::sharedState()->m_localLevels->removeObject(level, true);
    }
    else {
        const char* key = getLevelKey(level->m_levelID_Random - level->m_levelID_Seed);
        GJGameLevel *onlineLevel = reinterpret_cast<GJGameLevel *>(m_onlineLevels->objectForKey(key)); 
        if (
            (onlineLevel == nullptr) || (
                (onlineLevel->getNormalPercent() < 1) &&
                (onlineLevel->m_practicePercent < 1) && 
                (onlineLevel->m_bestTime < 1) &&
                (onlineLevel->m_bestPoints == 0) && 
                (onlineLevel->m_levelFavorited == false)
            )
        ) {
            m_onlineLevels->removeObjectForKey(getLevelKey(level->m_levelID_Random - level->m_levelID_Seed));
        } else {
            onlineLevel->m_levelString = "";
            onlineLevel->m_levelNotDownloaded = true;
        }
    }
}


void GameLevelManager::deleteLevelComment(int levelID,int commentID)
{
    deleteComment(commentID, kCommentTypeLevelType, levelID);
}



void GameLevelManager::deleteLevelList(GJLevelList* list)
{
    if (list->m_listType == 2) {
        LocalLevelManager::sharedState()->m_localLevelLists->removeObject(list,true);
    }
    else {
        m_GLM21->removeObjectForKey(getLevelListKey(list->m_listID));
    }
}



void __thiscall GameLevelManager::deleteSentFriendRequest(int sentID)
{
    deleteFriendRequests(sentID, nullptr, true);
}



void GameLevelManager::deleteServerLevel(int levelID)
{
    const char *key = getLevelKey(levelID);
    if (m_friendReqAndUserBlocks->objectForKey(key) == nullptr)
    {
        std::string postStr = getBasePostString();
        m_friendReqAndUserBlocks->setObject(cocos2d::CCNode::create(), key);
        postStr += cocos2d::CCString::createWithFormat("&levelID=%i&secret=%s", levelID, Wmfd2893gb7)->getCString();
        ProcessHttpRequest("https://www.boomlings.com/database/deleteGJLevelUser20.php", postStr, key, kGJHttpTypeDeleteServerLevel);
    }
}


void __thiscall GameLevelManager::deleteServerLevelList(int listID)
{
    if (m_unkLevelLists.find(GameToolbox::intToString(listID)) == m_unkLevelLists.end()) {
        m_unkLevelLists[GameToolbox::intToString(listID)] = listID;
        ProcessHttpRequest(
            "https://www.boomlings.com/database/deleteGJLevelList.php", 
            FORMAT_HTTP_REQUEST("&listID=%i&secret=%s",listID, Wmfd2893gb7), 
            GameToolbox::intToString(listID), kGJHTTPTypeDeleteServerLevelList
        );
    }
}

void GameLevelManager::deleteSmartTemplate(GJSmartTemplate* template)
{
    return;
}


void GameLevelManager::deleteUserMessages(GJUserMessage* message, cocos2d::CCArray* messages, bool isSender)
{
    return;
}

/* Robtop? Why did you repeat the Same Function from GameToolbox over here? it makes no sense :/ */

std::string gen_random(int size){
    std::string rs = "";
    for (int i = 0; i < size; i++) 
        rs += "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"[rand() % 0x3e];
    return rs;
}

void GameLevelManager::downloadLevel(int levelID, bool _isGaunlet)
{
    const char *key = getLevelDownloadKey(levelID, _isGaunlet);
    if (!isDLActive(key))
    {   
        int inc = hasDownloadedLevel(levelID);
        addDLToActive(key);
        std::string postData = FORMAT_HTTP_REQUEST("&levelID=%i&inc=%i&secret=%s", levelID, inc, Wmfd2893gb7);
        if (inc){
            auto rs = gen_random(10);
            postData += "&rs="; postData += rs;
            auto AM = GJAccountManager::sharedState();
            auto GM = GameManager::sharedState();
            /* I would think this is it?... */
            auto pre_chk = cocos2d::CCString::createWithFormat(
                "%i%i%s%i%s%i%s", levelID, inc, 
                rs.c_str() , 
                AM->m_accountID - AM->m_unkInt1,
                GM->m_playerUserID_Random - GM->m_playerUserID_Seed, 
                xI25fpAapCQg
            )->getCString();

            unsigned char hash[41];
            char chk[21];
            rtsha1::calc(pre_chk, strlen(pre_chk), hash);
            rtsha1::toHexString(hash, chk);
            postData += "&chk=";
            postData += cocos2d::ZipUtils::base64EncodeEnc(chk, "41274");
        }
        ProcessHttpRequest("https://www.boomlings.com/database/downloadGJLevel22.php", postData, key, kGJHttpTypeDownloadLevel);
    }
}


void GameLevelManager::downloadUserMessage(int messageID, bool isSender)
{
    const char *key = getMessageKey(isSender, messageID);
    if (!isDLActive(key))
    {
        addDLToActive(key);
        ProcessHttpRequest(
            "https://www.boomlings.com/database/downloadGJMessage20.php", 
            FORMAT_HTTP_REQUEST("&messageID=%i&secret=%s", messageID, Wmfd2893gb7), 
            key, 
            kGJHttpTypeDownloadUserMessage
        );
    }
}



void GameLevelManager::encodeDataTo(DS_Dictionary* dsdict)
{
      
    dsdict->setDictForKey("GLM_01",  m_mainLevels);
    limitSavedLevels();
    purgeUnusedLevels();
    /* Robtop? why run this twice? */
    updateLevelOrders();
    updateLevelOrders();
    dsdict->setDictForKey("GLM_03", m_onlineLevels);
    cleanupDailyLevels();
    dsdict->setDictForKey("GLM_10", m_dailyLevels);
    dsdict->setIntegerForKey("GLM_11", m_weeklyTimeLeft);
    dsdict->setIntegerForKey("GLM_17", m_eventTimeLeft);
    dsdict->setDictForKey("GLM_16", m_avalibleFilters);
    auto array = cocos2d::CCArray::create();
    // if (m_GLM21 != nullptr) {
    //     auto key = m_GLM21->key;
    //     while (key != nullptr) {
    //         array->addObject();
    //         key = pbVar1;
    //         if (pbVar1 != (basic_string *)0x0) {
    //             pbVar1 = (basic_string *)pbVar1[0x11]._M_length;
    //         }
    //     }
    // }
    dsdict->setArrayForKey("GLM_22", array);
    dsdict->setBoolMapForKey("GLM_09", m_GLM9);
    auto GM = GameManager::sharedState();
    if (GM->m_new == false) {
        dsdict->setDictForKey("GLM_07", m_downloadedLevels);
        dsdict->setDictForKey("GLM_14", m_reportedLevels);
    }
    dsdict->setDictForKey("GLM_12", m_likedLevels);
    dsdict->setDictForKey("GLM_13", m_ratedLevels);
    dsdict->setDictForKey("GLM_15", m_ratedDemons);
    dsdict->setDictForKey("GLM_06", m_follwedCreators);
    dsdict->setDictForKey("GLM_08", m_searchFilters);
    dsdict->setDictForKey("GLM_18", m_onlineFolders);
    dsdict->setDictForKey("GLM_19", m_localLevelsFolders);
    dsdict->setArrayForKey("GLM_20", m_smartTemplates);
}


void GameLevelManager::firstSetup()
{
    return;
}


void GameLevelManager::followUser(int ID)
{
    return m_followedCreators->setObject(cocos2d::CCString::create("1"), cocos2d::CCString::createWithFormat("%i", ID)->getCString());
}


GJFriendRequest* GameLevelManager::friendRequestFromAccountID(int accountID)
{
    return m_friendRequests->objectForKey(accountID);
}


void GameLevelManager::friendRequestWasRemoved(int p0, bool p1)
{
    return;
}


const char *GameLevelManager::getAccountCommentKey(int accountID, int page)
{
    return cocos2d::CCString::createWithFormat("a_%i_%i", accountID, page)->getCString();
}


void GameLevelManager::getAccountComments(int accountID, int page, int total)
{
    const char *key = getAccountCommentKey(accountID, page);
    if (!isDLActive(key))
    {
        addDLToActive(key);
        ProcessHttpRequest("https://www.boomlings.com/database/getGJAccountComments20.php", getBasePostString() + cocos2d::CCString::createWithFormat("&accountID=%i&page=%i&total=%i&secret=%s", accountID, page, total, Wmfd2893gb7)->getCString(), key, kGJHttpTypeGetAccountComments);
    }
}


int GameLevelManager::getActiveDailyID(GJTimedLevelType p0)
{
    return;
}


std::string GameLevelManager::getActiveDailyID(bool p0, bool p1, bool p2, bool p3, bool p4, bool p5, bool p6, bool p7)
{
    return;
}


GJSmartTemplate* GameLevelManager::getActiveSmartTemplate()
{
    return;
}


cocos2d::CCArray* GameLevelManager::getAllSmartTemplates()
{
    return;
}


cocos2d::CCDictionary* GameLevelManager::getAllUsedSongIDs()
{
    return;
}


GJLevelList* GameLevelManager::getAllUsedSongIDs(int p0)
{
    return;
}


std::string GameLevelManager::getBasePostString()
{
    /* TODO: Rename/modernize GameManager's class member names*/
    auto GM = GameManager::sharedState();

    std::string BasePostString;
    BasePostString += cocos2d::CCString::createWithFormat(
                          "gameVersion=%i&binaryVersion=%i&udid=%s&uuid=%i", 22, 0x28, GM->m_sPlayerUDID, GM->m_nChkRand - GM->m_nChkSeed)
                          ->getCString();
    
    /* TODO: Rename/modernize GJAccountManager's class member names*/
    auto AM = GJAccountManager::sharedState();
    /* This is what it is not sure why it's this way but it is... - Calloc  */
    BasePostString += cocos2d::CCString::createWithFormat(
                          "&accountID=%i&gjp2=%s", AM->m_nPlayerAccountID - AM->m_nPlayerAccountIDRand, AM->m_sGJP2)
                          ->getCString();
    /* There is more to this function but I have yet to find all of it out...*/
    return BasePostString;
}


bool GameLevelManager::getBoolForKey(char const* key)
{
    return m_searchFilters->valueForKey(key)->boolValue();
}


std::string GameLevelManager::getCommentKey(int ID, int page, int mode, CommentKeyType keytype)
{
    return cocos2d::CCString::createWithFormat("comment_%i_%i_%i_%i", page, mode, keytype, ID)->getCString();
}



/* Unknown Return: GameLevelManager::getCompletedDailyLevels(){}; */


/* Unknown Return: GameLevelManager::getCompletedGauntletDemons(){}; */


/* Unknown Return: GameLevelManager::getCompletedGauntletLevels(){}; */


cocos2d::CCArray* GameLevelManager::getCompletedLevels(bool p0)
{
    return;
}



/* Unknown Return: GameLevelManager::getCompletedWeeklyLevels(){}; */

int GameLevelManager::getDailyID(GJTimedLevelType timedleveltype)
{
    switch(timedleveltype){
        case kGJTimedLevelTypeWeekly: return m_weeklyID;
        case kGJTimedLevelTypeEvent: return m_eventID;
        default: return m_dailyID;
    }
}


int GameLevelManager::getDailyTimer(GJTimedLevelType timedleveltype)
{
    switch(timedleveltype){
        case kGJTimedLevelTypeWeekly: return m_weeklyTimeLeft;
        case kGJTimedLevelTypeEvent: return m_eventTimeLeft;
        default: return m_dailyTimeLeft;
    }
}


char const*GameLevelManager::getDeleteCommentKey(int levelID, int commentID, int Ctype)
{
    return cocos2d::CCString::createWithFormat("delcomment_%i_%i_%i", levelID, commentID, Ctype)->getCString();
}


char const* GameLevelManager::getDeleteMessageKey(int p0, bool p1)
{
    return;
}



/* Unknown Return: GameLevelManager::getDemonLevelsString(){}; */

const char * GameLevelManager::getDescKey(int value)
{ 
    return cocos2d::CCString::createWithFormat("desc_%i", value)->getCString();
}

const char *GameLevelManager::getDiffKey(int Diff)
{
    return cocos2d::CCString::createWithFormat("Diff%i", Diff)->getCString();
}

bool __thiscall GameLevelManager::getDiffVal(int key)
{
    return m_searchFilters->valueForKey(getDiffKey(key))->boolValue();
}


std::string GameLevelManager::getFolderName(int p0, bool p1)
{
    return;
}



const char *GameLevelManager::getFriendRequestKey(bool sent, int page)
{
    return cocos2d::CCString::createWithFormat("fReq_%i_%i", (int)sent, page)->getCString();
}


void GameLevelManager::getFriendRequests(bool sent, int page, int total)
{
    const char *key = getFriendRequestKey(sent, page);
    if (!isDLActive(key))
    {
        addDLToActive(key);
        std::string poststr = FORMAT_HTTP_REQUEST("&page=%i&total=%i&secret=%s", page, total, Wmfd2893gb7);
        if (sent)
            poststr += "&getSent=1";
        ProcessHttpRequest("https://www.boomlings.com/database/getGJFriendRequests20.php", poststr, key, kGJHttpTypeGetFriendRequests);
    }
}


void GameLevelManager::getGJChallenges()
{
    return;
}


void GameLevelManager::getGJDailyLevelState(GJTimedLevelType levelType)
{
    const char *key;
    switch(levelType){
        case kGJTimedLevelTypeWeekly: { 
            key = "\xde";
            break;
        }
        case kGJTimedLevelTypeEvent: {
            key = "\xeb";
            break;
        }
        default: {
            key = "\xcc";
            break;
        }
    }
    if (!isDLActive(key))
    {
        addDLToActive(key);
        ProcessHttpRequest("https://www.boomlings.com/database/getGJDailyLevel.php", FORMAT_HTTP_REQUEST("&secret=%s&type=%i", Wmfd2893gb7, levelType), key, kGJHttpTypeGetGJDailyLevelState);
    }
}


void GameLevelManager::getGJRewards(int p0)
{
    return;
}


void GameLevelManager::getGJUserInfo(int targetAccountID)
{
    const char *key = getUserInfoKey(targetAccountID);
    if (!isDLActive(key))
    {
        addDLToActive(key);
        ProcessHttpRequest("https://www.boomlings.com/database/getGJUserInfo20.php", FORMAT_HTTP_REQUEST("&targetAccountID=%i&secret=%s", targetAccountID, Wmfd2893gb7), key, kGJHttpTypeGetGJUserInfo);
    }
}

const char *GameLevelManager::getGauntletKey(int key)
{
    return cocos2d::CCString::createWithFormat("%i", key)->getCString();
}


void GameLevelManager::getGauntletLevels(int p0)
{
    return;
}


void GameLevelManager::getGauntlets()
{
    if (!isDLActive("get_gauntlets"))
    {
        addDLToActive("get_gauntlets");
        ProcessHttpRequest("https://www.boomlings.com/database/getGJGauntlets21.php", FORMAT_HTTP_REQUEST("&secret=%s&special=1", Wmfd2893gb7), "get_gauntlets", kGJHttpTypeGetGauntlets);
    }
}


const char *GameLevelManager::getGauntletsearchKey(int searchKey)
{
    return cocos2d::CCString::createWithFormat("gaunlet_%i", searchKey)->getCString();
}


int GameLevelManager::getHighestLevelOrder()
{
    return;
}


int GameLevelManager::getIntForKey(char const* p0)
{
    return;
}


void GameLevelManager::getLeaderboardScores(char const* p0)
{
    return;
}


char const* GameLevelManager::getLenKey(int len)
{
    return cocos2d::CCString::createWithFormat("Len%i", len)->getCString();
}


bool GameLevelManager::getLenVal(int p0)
{
    return;
}


std::string GameLevelManager::getLengthStr(bool p0, bool p1, bool p2, bool p3, bool p4, bool p5)
{
    return;
}


void GameLevelManager::getLevelComments(int ID, int page, int total, int mode, CommentKeyType keytype)
{
    const char *key = getCommentKey(ID, page, mode, keytype);
    /* is the same request running for our key? if so do not run... */
    if (!isDLActive((char *)key))
    {
        /* Throw this key into our mutex... */
        addDLToActive(key);
        /* Start our HTTP Request this poststring contains
         * some of our other params like gameVersion, binaryVersion, udid, uuid , accountID , gjp and more... */
        std::string postString = getBasePostString();
        /* Wonder why Robtop wrote in his secret parameter this way? It's not really so secret... */
        const char *secret = cocos2d::CCString::createWithFormat("%c%s%s%c%c%s", 'W', "mfd", "2893", 'g', 'b', "7")->getCString();
        postString += cocos2d::CCString::createWithFormat("&page=%i&total=%i&secret=%s&mode=%i", page, total, secret, total)->getCString();
        /* set levelID or userID */
        postString.append(keytype == kCommentKeyTypeLevelType ? "&levelID=" : "&userID=");
        /* Add in our userID or levelID */
        postString += cocos2d::CCString::createWithFormat("%i", ID)->getCString();

        int count = GameManager::sharedState()->getGameVariable("0088") ? 10 : 20;
        /* The Settings to make the pages smaller is checked here */
        if (GameManager::sharedState()->getGameVariable("0094"))
            count *= 2;
        std::string endpoint = (keytype == kCommentKeyTypeLevelType) ? "https://www.boomlings.com/database/getGJComments21.php" : "https://www.boomlings.com/database/getGJCommentHistory.php";

        /* prepare for sendoff */
        ProcessHttpRequest(endpoint, postString, key, kGJHttpTypeGetLevelComments);
    }
}

/* Discovered by Capeling */
const char *GameLevelManager::getLevelDownloadKey(int levelID, bool _isGauntlet)
{
    return cocos2d::CCString::createWithFormat("%i_%i", levelID, _isGauntlet)->getCString();
}

char const* GameLevelManager::getLevelKey(int levelID)
{
    return;
}

void GameLevelManager::getLevelLeaderboard(GJGameLevel* p0, LevelLeaderboardType p1, LevelLeaderboardMode p2)
{
    return;
}


char const* GameLevelManager::getLevelLeaderboardKey(int p0, LevelLeaderboardType p1, LevelLeaderboardMode p2)
{
    return;
}


/* Discovered by Capeling */
const char *GameLevelManager::getLevelListKey(int listID)
{
    return cocos2d::CCString::createWithFormat("%i", listID)->getCString();
}


void GameLevelManager::getLevelLists(GJSearchObject *searchObject)
{
    const char *dl_key = searchObject->getKey();
    if (isDLActive(dl_key))
    {
        addDLToActive(dl_key);
        ProcessHttpRequest(
            "https://www.boomlings.com/database/getGJLevelLists.php",
            FORMAT_HTTP_REQUEST("&str=%s&type=%i&page=%i&secret=%s", searchObject->m_searchQuery, searchObject->m_searchType, searchObject->m_page, Wmfd2893gb7), 
            dl_key, 
            0x3c /* <- TODO */
        );
    }
}


void GameLevelManager::getLevelSaveData()
{
    if (!isDLActive("lvl_data"))
    {
        addDLToActive("lvl_data");
        ProcessHttpRequest("https://www.boomlings.com/database/getSaveData.php", getBasePostString() + "&secret=" + Wmfd2893gb7, "lvl_data", kGJHttpTypeGetLevelSaveData);
    }
}


char const* GameLevelManager::getLikeAccountItemKey(LikeItemType p0, int p1, bool p2, int p3)
{
    return;
}


char const* GameLevelManager::getLikeItemKey(LikeItemType p0, int p1, bool p2, int p3)
{
    return;
}


GJGameLevel* GameLevelManager::getLocalLevel(int p0)
{
    return;
}


GJGameLevel* GameLevelManager::getLocalLevelByName(std::string p0)
{
    return;
}


int GameLevelManager::getLowestLevelOrder()
{
    return;
}


GJGameLevel* GameLevelManager::getMainLevel(int p0, bool p1)
{
    return;
}


char const* GameLevelManager::getMapPackKey(int pack)
{
    return cocos2d::CCString::createWithFormat("pack_%i", pack)->getCString();
}


void GameLevelManager::getMapPacks(GJSearchObject* p0)
{
    return;
}


char const* GameLevelManager::getMessageKey(int p0)
{
    return;
}


char const* GameLevelManager::getMessagesKey(bool p0, int p1)
{
    return;
}


void GameLevelManager::getNews()
{
    return;
}


int GameLevelManager::getNextFreeTemplateID()
{
    return;
}


std::string GameLevelManager::getNextLevelName(std::string p0)
{
    return;
}


void GameLevelManager::getOnlineLevels(GJSearchObject* p0)
{
    return;
}


char const* GameLevelManager::getPageInfo(char const* p0)
{
    return;
}


char const* GameLevelManager::getPostCommentKey(int seconds_left)
{
    return cocos2d::CCString::createWithFormat("c_%i", seconds_left)->getCString();
}


const char *GameLevelManager::getRateStarsKey(int key)
{
    return cocos2d::CCString::createWithFormat("%i", key)->getCString();
}


const char *GameLevelManager::getReportKey(int levelID)
{
    return cocos2d::CCString::createWithFormat("%i", levelID)->getCString();
}



GJGameLevel* GameLevelManager::getSavedDailyLevel(int p0)
{
    return;
}


GJGameLevel* GameLevelManager::getSavedDailyLevelFromLevelID(int p0)
{
    return;
}


GJGameLevel* GameLevelManager::getSavedGauntlet(int p0)
{
    return;
}


GJGameLevel* GameLevelManager::getSavedGauntletLevel(int p0)
{
    return;
}


GJGameLevel* GameLevelManager::getSavedLevel(GJGameLevel* p0)
{
    return;
}


GJGameLevel* GameLevelManager::getSavedLevel(int p0)
{
    return;
}


GJLevelList* GameLevelManager::getSavedLevelList(int p0)
{
    return;
}


cocos2d::CCArray* GameLevelManager::getSavedLevelLists(int p0)
{
    return;
}


cocos2d::CCArray* GameLevelManager::getSavedLevels(bool p0, int p1)
{
    return;
}



/* Unknown Return: GameLevelManager::getSavedMapPack(int p0){}; */

cocos2d::CCScene* GameLevelManager::getSearchScene(char const* p0)
{
    return;
}


int GameLevelManager::getSplitIntFromKey(char const* p0, int p1)
{
    return;
}



/* Unknown Return: GameLevelManager::getStarLevelsString(){}; */


/* Unknown Return: GameLevelManager::getStoredLevelComments(char const* p0){}; */

cocos2d::CCArray* GameLevelManager::getStoredOnlineLevels(char const* p0)
{
    return;
}


cocos2d::CCArray* GameLevelManager::getStoredUserList(UserListType p0)
{
    return;
}


GJUserMessage* GameLevelManager::getStoredUserMessage(int p0)
{
    return;
}


GJUserMessage* GameLevelManager::getStoredUserMessageReply(int p0)
{
    return;
}


double GameLevelManager::getTimeLeft(char const* p0, float p1)
{
    return;
}


void GameLevelManager::getTopArtists(int page, int total)
{
    const char *key = getTopArtistsKey(page);
    if (!isDLActive(key))
    {
        addDLToActive(key);
        ProcessHttpRequest(
            "https://www.boomlings.com/database/getGJTopArtists.php", 
            FORMAT_HTTP_REQUEST("&page=%i&secret=%s&total=%i", page, Wmfd2893gb7, total), 
            key, 
            kGJHttpTypeGetTopArtists
        );
    }
};

const char *GameLevelManager::getTopArtistsKey(int page)
{
    return cocos2d::CCString::createWithFormat("topArtists_%i", page)->getCString();
}

char const* GameLevelManager::getUploadMessageKey(int p0)
{
    return;
}


const char *GameLevelManager::getUserInfoKey(int targetAccountID)
{
    return cocos2d::CCString::createWithFormat("account_%i", targetAccountID)->getCString();
}


void GameLevelManager::getUserList(UserListType listType)
{
    const char *key = (listType == kUserListTypeGetFriends) ? "get_friends" : "get_blocked";
    if (!isDLActive(key))
    {
        addDLToActive(key);
        ProcessHttpRequest("https://www.boomlings.com/database/getGJUserList20.php", FORMAT_HTTP_REQUEST("&type=%i&secret=%s", listType, Wmfd2893gb7), key, kGJHttpTypeGetUserList);
    }
}

void GameLevelManager::getUserMessages(bool getSent, int page, int total)
{
    const char *key = getMessagesKey(getSent, page);
    if (!isDLActive(key))
    {
        addDLToActive(key);
        std::string postStr = FORMAT_HTTP_REQUEST("&page=%i&total=%i&secret=%s", page, total, Wmfd2893gb7); 
        postStr += (getSent) ? "&getSent=1": "";
        ProcessHttpRequest("https://www.boomlings.com/database/getGJMessages20.php", postStr, key, kGJHttpTypeGetUserMessages);
    }
}

const char *GameLevelManager::getMessagesKey(bool getSent, int page)
{
    return cocos2d::CCString::createWithFormat("messages_%i_%i", (int)getSent, page)->getCString();
}


void GameLevelManager::getUsers(GJSearchObject *searchObject)
{
    const char *key = searchObject->getKey();
    if (!isDLActive(key))
    {
        addDLToActive(key);
        ProcessHttpRequest(
            "https://www.boomlings.com/database/getGJUsers20.php", 
            FORMAT_HTTP_REQUEST("&str=%s&total=%i&page=%i&secret=%s", searchObject->m_searchQuery, searchObject->m_total, searchObject->m_page, Wmfd2893gb7), 
            key, 
            kGJHttpTypeGetUsers
        );
    }
}


void GameLevelManager::gotoLevelPage(GJGameLevel* p0)
{
    return;
}


void GameLevelManager::handleIt(bool p0, std::string p1, std::string p2, GJHttpType p3)
{
    return;
}


void GameLevelManager::handleItDelayed(bool p0, std::string p1, std::string p2, GJHttpType p3)
{
    return;
}


void GameLevelManager::handleItND(cocos2d::CCNode* p0, void* p1)
{
    return;
}


bool GameLevelManager::hasDailyStateBeenLoaded(GJTimedLevelType p0)
{
    return;
}


bool GameLevelManager::hasDownloadedLevel(int levelID)
{
    return (bool)m_downloadedLevels->objectForKey(getLevelKey(levelID));
}


bool GameLevelManager::hasDownloadedList(int p0)
{
    return;
}


bool GameLevelManager::hasLikedAccountItem(LikeItemType p0, int p1, bool p2, int p3)
{
    return;
}


bool GameLevelManager::hasLikedItem(LikeItemType p0, int p1, bool p2, int p3)
{
    return;
}


bool GameLevelManager::hasLikedItemFullCheck(LikeItemType p0, int p1, int p2)
{
    return;
}


bool GameLevelManager::hasRatedDemon(int p0)
{
    return;
}


bool GameLevelManager::hasRatedLevelStars(int p0)
{
    return;
}


bool GameLevelManager::hasReportedLevel(int levelID)
{
    return (bool)m_reportedLevels->objectForKey(getReportKey(levelID));
}


bool GameLevelManager::init()
{
    return;
}


void GameLevelManager::invalidateMessages(bool p0, bool p1)
{
    return;
}


void GameLevelManager::invalidateRequests(bool p0, bool p1)
{
    return;
}


void GameLevelManager::invalidateUserList(UserListType p0, bool p1)
{
    return;
}


bool GameLevelManager::isDLActive(const char *tag)
{
    return m_downloadObjects->objectForKey(tag);
}


bool GameLevelManager::isFollowingUser(int ID)
{
    return (bool)m_followedCreators->objectForKey(cocos2d::CCString::createWithFormat("%i", ID)->getCString());
}


bool GameLevelManager::isTimeValid(char const* p0, float p1)
{
    return;
}


bool GameLevelManager::isUpdateValid(int p0)
{
    return;
}


int GameLevelManager::itemIDFromLikeKey(char const* p0)
{
    return;
}


bool GameLevelManager::keyHasTimer(char const* p0)
{
    return;
}


int GameLevelManager::levelIDFromCommentKey(char const* p0)
{
    return;
}


int GameLevelManager::levelIDFromPostCommentKey(char const* p0)
{
    return;
}


int GameLevelManager::likeFromLikeKey(char const* p0)
{
    return;
}


void GameLevelManager::likeItem(LikeItemType p0, int p1, bool p2, int p3)
{
    return;
}


void GameLevelManager::limitSavedLevels()
{
    return;
}


void GameLevelManager::makeTimeStamp(char const* p0)
{
    return;
}


void GameLevelManager::markItemAsLiked(LikeItemType p0, int p1, bool p2, int p3)
{
    return;
}


void GameLevelManager::markLevelAsDownloaded(int p0)
{
    return;
}


void GameLevelManager::markLevelAsRatedDemon(int p0)
{
    return;
}


void GameLevelManager::markLevelAsRatedStars(int p0)
{
    return;
}


void GameLevelManager::markLevelAsReported(int p0)
{
    return;
}


void GameLevelManager::messageWasRemoved(int p0, bool p1)
{
    return;
}


void GameLevelManager::onAcceptFriendRequestCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onBanUserCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onBlockUserCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onDeleteCommentCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onDeleteFriendRequestCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onDeleteServerLevelCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onDeleteServerLevelListCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onDeleteUserMessagesCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onDownloadLevelCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onDownloadUserMessageCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetAccountCommentsCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetFriendRequestsCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetGJChallengesCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetGJDailyLevelStateCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetGJRewardsCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetGJUserInfoCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetGauntletsCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetLeaderboardScoresCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetLevelCommentsCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetLevelLeaderboardCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetLevelListsCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetLevelSaveDataCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetMapPacksCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetNewsCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetOnlineLevelsCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetTopArtistsCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetUserListCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetUserMessagesCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onGetUsersCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onLikeItemCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onProcessHttpRequestCompleted(cocos2d::extension::CCHttpClient *client, cocos2d::extension::CCHttpResponse *response)
{
    return handleIt(true,  GameToolbox::getResponse(response), response->getHttpRequest()->getTag(), (GJHttpType)response->getHttpRequest()->get_requestTypeGJ());
}



void GameLevelManager::onRateDemonCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onRateStarsCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onReadFriendRequestCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onRemoveFriendCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onReportLevelCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onRequestUserAccessCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onRestoreItemsCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onSetLevelFeaturedCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onSetLevelStarsCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onSubmitUserInfoCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onSuggestLevelStarsCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onUnblockUserCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onUpdateDescriptionCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onUpdateLevelCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onUpdateUserScoreCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onUploadCommentCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onUploadFriendRequestCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onUploadLevelCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onUploadLevelListCompleted(std::string response, std::string tag)
{
    return;
}


void GameLevelManager::onUploadUserMessageCompleted(std::string response, std::string tag)
{
    return;
}


int GameLevelManager::pageFromCommentKey(char const* p0)
{
    return;
}


void GameLevelManager::parseRestoreData(std::string p0)
{
    return;
}


void GameLevelManager::performNetworkTest()
{
    if (!m_networkTested->getValue())
    {
        bool v = m_networkTested->getValue(); v = true;
        std::string postData = "temp";
        cocos2d::extension::CCHttpRequest *request = new cocos2d::extension::CCHttpRequest();
        request->setUrl("https://www.google.com");
        /* Unknown Field Call where variable 0x74 is set to 1 */
        request->setRequestType(cocos2d::extension::CCHttpRequest::kHttpPost);
        request->setResponseCallback(this, static_cast<cocos2d::extension::SEL_HttpResponse>(onProcessHttpRequestCompleted));
        request->setUserData(nullptr);
        retain();
        request->setRequestData(postData.c_str(), postData.size());
        request->setTag("tag");
        cocos2d::extension::CCHttpClient::getInstance()->send(request);
        request->release();
    }
};

void GameLevelManager::ProcessHttpRequest(std::string endpoint, std::string params, std::string tag, GJHttpType httpType)
{
    if (GameManager::sharedState()->getGameVariable("0055"))
    {
        /* Seems to have had a typo on Robtop's End
         * URL Should've been named: "https://www.boomlings.com/database/checkIfServerOnline.php"
         * where "databas" should've been named "database"...*/
        endpoint = "https://www.boomlings.com/databas/checkIfServerOnline.php";
    };
    cocos2d::extension::CCHttpRequest *request = new cocos2d::extension::CCHttpRequest();
    request->setUrl(endpoint.c_str());
    request->setRequestType(cocos2d::extension::CCHttpRequest::kHttpPost);
    request->setResponseCallback(this, static_cast<cocos2d::extension::SEL_HttpResponse>(onProcessHttpRequestCompleted));
    request->setUserData(NULL);
    if (this != NULL)
        retain();
    request->setRequestData(params.c_str(), params.size());
    request->setTag(tag.c_str());
    request->set_requestTypeGJ((int)httpType);
    /* Send-Off */
    cocos2d::extension::CCHttpClient::getInstance()->send(request);
    request->release();
}


void GameLevelManager::processOnDownloadLevelCompleted(std::string p0, std::string p1, bool p2)
{
    return;
}


void GameLevelManager::purgeUnusedLevels()
{
    return;
}


void GameLevelManager::rateDemon(int p0, int p1, bool p2)
{
    return;
}


void GameLevelManager::rateStars(int p0, int p1)
{
    return;
}


void GameLevelManager::readFriendRequest(int p0)
{
    return;
}


void GameLevelManager::removeDLFromActive(char const* tag)
{
    m_downloadObjects->removeObjectForKey(tag);
}



/* Unknown Return: GameLevelManager::removeDelimiterChars(std::string p0, bool p1){}; */

void GameLevelManager::removeFriend(int p0)
{
    return;
}


void GameLevelManager::removeLevelDownloadedKeysFromDict(cocos2d::CCDictionary* p0)
{
    return;
}


void GameLevelManager::removeUserFromList(int p0, UserListType p1)
{
    return;
}


void GameLevelManager::reportLevel(int levelID)
{
    if (!hasReportedLevel(levelID))
    {
        markLevelAsReported(levelID);
        ProcessHttpRequest(
            "https://www.boomlings.com/database/reportGJLevel.php", 
            cocos2d::CCString::createWithFormat("levelID=%i&secret=%s", levelID, Wmfd2893gb7)->getCString(), 
            cocos2d::CCString::createWithFormat("%i", levelID)->getCString(), 
            kGJHttpTypeReportLevel
        );
    }
}


void GameLevelManager::requestUserAccess()
{
    return;
}


void GameLevelManager::resetAccountComments(int p0)
{
    return;
}


void GameLevelManager::resetAllTimers()
{
    return;
}


void GameLevelManager::resetCommentTimersForLevelID(int p0, CommentKeyType p1)
{
    return;
}


void GameLevelManager::resetDailyLevelState(GJTimedLevelType p0)
{
    return;
}


void GameLevelManager::resetGauntlets()
{
    return;
}

void GameLevelManager::resetStoredUserInfo(int key)
{
    m_storedUserInfo->removeObjectForKey(key);
}

void GameLevelManager::resetStoredUserList(UserListType p0)
{
    return;
}


void GameLevelManager::resetTimerForKey(char const* p0)
{
    return;
}



cocos2d::CCDictionary *GameLevelManager::responseToDict(std::string response, bool snake_case)
{
    cocos2d::CCDictionary *dict = cocos2d::CCDictionary::create();
    cocos2d::CCArray *arr = Robtop::splitToCCArray(response, (snake_case ? "~" : ":"));
    cocos2d::CCString *value, *key;
    unsigned int pos = 0, size;
    /* TODO: Finish this!*/
    while (true)
    {
        size = arr->count();
        if (size <= pos + 1)
        {
            break;
        }
        key = reinterpret_cast<cocos2d::CCString*>(arr->objectAtIndex(pos));
        value = reinterpret_cast<cocos2d::CCString*>(arr->objectAtIndex(pos + 1));
        if (key != NULL && value != NULL)
        {
            dict->setObject(value, key->getCString());
        }
        pos += 2;
    }
    return dict;
}


void GameLevelManager::restoreItems()
{
    return;
}


void GameLevelManager::saveFetchedLevelLists(cocos2d::CCArray* p0)
{
    return;
}


void GameLevelManager::saveFetchedLevels(cocos2d::CCArray* p0)
{
    return;
}


void GameLevelManager::saveFetchedMapPacks(cocos2d::CCArray* p0)
{
    return;
}


void GameLevelManager::saveGauntlet(GJMapPack* p0)
{
    return;
}


void GameLevelManager::saveLevel(GJGameLevel* p0)
{
    return;
}


void GameLevelManager::saveLevelList(GJLevelList* p0)
{
    return;
}


void GameLevelManager::saveLocalScore(int p0, int p1, int p2)
{
    return;
}


void GameLevelManager::saveMapPack(GJMapPack* p0)
{
    return;
}


void GameLevelManager::setActiveSmartTemplate(GJSmartTemplate* p0)
{
    return;
}


void GameLevelManager::setBoolForKey(bool p0, char const* p1)
{
    return;
}


void GameLevelManager::setDiffVal(int p0, bool p1)
{
    return;
}


void GameLevelManager::setFolderName(int p0, std::string p1, bool p2)
{
    return;
}


void GameLevelManager::setIntForKey(int p0, char const* p1)
{
    return;
}


void GameLevelManager::setLenVal(int p0, bool p1)
{
    return;
}


void GameLevelManager::setLevelFeatured(int p0, int p1, bool p2)
{
    return;
}


void GameLevelManager::setLevelStars(int p0, int p1, bool p2)
{
    return;
}


GameLevelManager* GameLevelManager::sharedState()
{
    return;
}


int GameLevelManager::specialFromLikeKey(char const* p0)
{
    return;
}


void GameLevelManager::storeCommentsResult(cocos2d::CCArray* p0, std::string p1, char const* p2)
{
    return;
}


void GameLevelManager::storeDailyLevelState(int p0, int p1, GJTimedLevelType p2)
{
    return;
}


void GameLevelManager::storeFriendRequest(GJFriendRequest* p0)
{
    return;
}


void GameLevelManager::storeSearchResult(cocos2d::CCArray* levels, std::string pageInfo, char const* searchKey)
{
    return;
}


void GameLevelManager::storeUserInfo(GJUserScore* p0)
{
    return;
}


void GameLevelManager::storeUserMessage(GJUserMessage* p0)
{
    return;
}


void GameLevelManager::storeUserMessageReply(int p0, GJUserMessage* p1)
{
    return;
}


void GameLevelManager::storeUserName(int userID, int accountID, std::string userName)
{
    if (0 < userID) {
        m_knownUsers->setObject(cocos2d::CCStringMake(userName), cocos2d::CCString::createWithFormat("%i",userID)->getCString());
        if (0 < accountID) {
            m_userIDtoAccountIDDict->setObject(cocos2d::CCString::createWithFormat("%i", accountID), userID);
            m_accountIDtoUserIDDict->setObject(cocos2d::CCString::createWithFormat("%i", userID), accountID);
        }
    }
}


void GameLevelManager::storeUserNames(std::string usernameString)
{
    return;
}


void GameLevelManager::submitUserInfo()
{
    return;
}


void GameLevelManager::suggestLevelStars(int p0, int p1, int p2)
{
    return;
}


std::string GameLevelManager::tryGetUsername(int p0)
{
    return;
}


CommentType GameLevelManager::typeFromCommentKey(char const* p0)
{
    return;
}


LikeItemType GameLevelManager::typeFromLikeKey(char const* p0)
{
    return;
}


void GameLevelManager::unblockUser(int p0)
{
    return;
}


void GameLevelManager::unfollowUser(int p0)
{
    return;
}


void GameLevelManager::updateDescription(int p0, std::string p1)
{
    return;
}


void GameLevelManager::updateLevel(GJGameLevel* p0)
{
    return;
}


void GameLevelManager::updateLevelOrders()
{
    return;
}


void GameLevelManager::updateLevelRewards(GJGameLevel* level)
{
  if (GameStatsManager::sharedState()->hasCompletedLevel(level)) {
    level->setNormalPercent(100);
    if (level->m_demon_Random - level->m_demon_Seed == 1) {
      GameStatsManager::sharedState()->completedDemonLevel(level);
    }
    if (0 < level->m_stars_Random - level->m_stars_Seed) {
      GameStatsManager::sharedState()->completedStarLevel(level);
    }
    GameStatsManager::sharedState()->checkCoinsForLevel(level);
  }
  if (0 < level->m_stars_Random - level->m_stars_Seed) {
       GameStatsManager::sharedState()->awardCurrencyForLevel(level);
  }
}



void GameLevelManager::updateSavedLevelList(GJLevelList* p0)
{
    return;
}


void GameLevelManager::updateUserScore()
{
    return;
}


void GameLevelManager::updateUsernames()
{
    return;
}


void GameLevelManager::uploadAccountComment(std::string p0)
{
    return;
}



// Requested from CNSL, I do not have the time that I used to to work on this but here is my best guess. 
// Still derusting as is. Pull requests apperciated. - Calloc
// void GameLevelManager::uploadComment(std::string comment, kCommentType commentType, int ID, int percent)
// {

  
//     comment = LevelTools::base64EncodeString(comment);
//     const char* postCommentKey =  (commentType == kCommentTypeLevelType) ? getPostCommentKey(ID) : "acc_comment";
//     // cocos2d::CCNode* object = m_friendReqAndUserBlocks->objectForKey(postCommentKey);
//     // if (object != (CCObject *)0x0){
//     //     return;
//     // }
//     m_friendReqAndUserBlocks->setObject(cocos2d::CCNode::create() , postCommentKey);
//     // makeTimeStamp(postCommentKey);
//     std::string m_playerName = removeDelimiterChars(GameManager::sharedState()->m_playerName, 0);
//     std::string m_playerUDID = removeDelimiterChars(GameManager::sharedState()->m_playerUDID, 1);
//     std::string postData = getBasePostString() + cocos2d::CCString::createWithFormat("&userName=%s&comment=%s&secret=%s",m_playerName, comment, Wmfd2893gb7)->getCString();

//     if (commentType == kCommentTypeLevelType) {
//       postData += "&levelID=";
//       postData += cocos2d::CCString::createWithFormat("%i",ID)->getCString();
//       if (0 < percent) {
//         postData += "&percent=";
//         postData += cocos2d::CCString::createWithFormat("%i", percent)->getCString();
//       }
//     }
//     else {
//       postData += "&cType=";
//       postData += cocos2d::CCString::createWithFormat("%i",cType)->getCString();
//     }

//     std::string raw_chk = cocos2d::CCString::createWithFormat("%s%s%i%i%i",m_playerName, comment , ID,percent,commentType)->getCString() + xI25fpAapCQg;
//     std::string hexString;
//     unsigned char* hash;
//     rtsha1::calc(raw_chk, raw_chk.len(), hash);

//     rtsha1::toHexString(hash, hexString);
//     cocos2d::ZipUtils::base64EncodeEnc(  , "29481");
//     std::basic_string::~basic_string(&bStack_88);
//     std::basic_string::~basic_string(&bStack_8c);
//     std::basic_string::operator+=(&local_98,"&chk=");
//     std::basic_string::operator+=(&local_98,&bStack_90);
//     this_00 = &bStack_78;
//     if (commentType == kCommentTypeLevelType) {
//       std::basic_string::basic_string
//                 (&bStack_84,"https://www.boomlings.com/database/uploadGJComment21.php");
//       std::basic_string::basic_string(&bStack_80,(char *)local_98._M_data);
//       std::basic_string::basic_string(&bStack_7c,postCommentKey);
//       ProcessHttpRequest(this,&bStack_84,&bStack_80,&bStack_7c,0xd);
//       std::basic_string::~basic_string(&bStack_7c);
//       std::basic_string::~basic_string(&bStack_80);
//       this_00 = &bStack_84;
//     }
//     else {
//       std::basic_string::basic_string
//                 (this_00,"https://www.boomlings.com/database/uploadGJAccComment20.php");
//       std::basic_string::basic_string(&bStack_74,(char *)local_98._M_data);
//       std::basic_string::basic_string(&bStack_70,postCommentKey);
//       ProcessHttpRequest(this,this_00,&bStack_74,&bStack_70,0xd);
//       std::basic_string::~basic_string(&bStack_70);
//       std::basic_string::~basic_string(&bStack_74);
//     }
//     std::basic_string::~basic_string(this_00);
//     std::basic_string::~basic_string(&bStack_90);
//     std::basic_string::~basic_string(&local_94);
//     std::basic_string::~basic_string(&local_98);
//     std::basic_string::~basic_string(&m_playerUDID);
//     std::basic_string::~basic_string(&m_playerName);

//     if (local_2c != _const char* postCommentKeytack_chk_guard) {
//       func_0x002b616c();
//       return;
//     }
//     return;
// }


void GameLevelManager::uploadFriendRequest(int p0, std::string p1)
{
    return;
}


void GameLevelManager::uploadLevel(GJGameLevel* p0)
{
    return;
}


void GameLevelManager::uploadLevelComment(int p0, std::string p1, int p2)
{
    return;
}


void GameLevelManager::uploadLevelList(GJLevelList* p0)
{
    return;
}


void GameLevelManager::uploadUserMessage(int p0, std::string p1, std::string p2)
{
    return;
}


int GameLevelManager::userIDForAccountID(int p0)
{
    return;
}


GJUserScore* GameLevelManager::userInfoForAccountID(int p0)
{
    return;
}


std::string GameLevelManager::userNameForUserID(int p0)
{
    return;
}



/* Unknown Return: GameLevelManager::verifyContainerOnlyHasLevels(cocos2d::CCDictionary* p0){}; */

void GameLevelManager::verifyLevelState(GJGameLevel* p0)
{
    return;
}


std::string GameLevelManager::writeSpecialFilters(GJSearchObject* p0)
{
    return;
}




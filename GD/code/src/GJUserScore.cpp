#include "includes.h"

GJUserScore *GJUserScore::create()
{
    GJUserScore *score = new GJUserScore();
    if (score != nullptr || score->init())
    {
        score->autorelease();
        return score;
    }
    CC_SAFE_DELETE(score);
    return nullptr;
}

// I will Expand these macros later...
#ifndef GETINT
#define GETINT(KEY) dict->valueForKey(KEY)->intValue()
#endif
#ifndef GETSTR
#define GETSTR(KEY) dict->valueForKey(KEY)->getCString()
#endif

#ifndef GETBOOL
#define GETBOOL(KEY) dict->valueForKey(KEY)->boolValue()
#endif

GJUserScore *GJUserScore::create(cocos2d::CCDictionary *dict)
{

    if (dict != nullptr)
    {
        auto score = GJUserScore::create();
        score->m_userName = dict->valueForKey("1")->getCString();
        // score->m_accountHighLight = dict->valueForKey("7")->intValue();
        score->m_userID = dict->valueForKey("2")->intValue();
        score->m_stars = dict->valueForKey("3")->intValue();
        score->m_demons = dict->valueForKey("4")->intValue();
        score->m_playerRank = dict->valueForKey("6")->intValue();
        score->m_creatorPoints = dict->valueForKey("8")->intValue();
        score->m_secretCoins = dict->valueForKey("13")->intValue();
        score->m_userCoins = dict->valueForKey("17")->intValue();
        score->m_diamonds = dict->valueForKey("46")->intValue();
        score->m_moons = dict->valueForKey("53")->intValue();
        score->m_iconID = dict->valueForKey("9")->intValue();
        score->m_color1 = dict->valueForKey("10")->intValue();
        /* Got tired of writing the longer version */
        score->m_color2 = GETINT("11");
        score->m_color3 = GETINT("51");
        score->m_iconType = static_cast<IconType>(GETINT("14"));
        score->m_special = GETINT("15");
        score->m_accountID = GETINT("16");
        score->m_newFriendRequest = GETINT("41");
        score->m_messageState = GETINT("18");
        score->m_accountAge = GETSTR("42");

        /* Registered Account?*/
        if (GETBOOL("29"))
        {
            score->m_userID = GETINT("19");
            // TODO: Finish this, it's just reptative and annoying...
            //             this = (basic_string *)(auStack_ac + 4);
            //       std::basic_string::basic_string(this,"50");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,this);
            //       stars = cocos2d::CCString::intValue(_dict);
            //      this);
            //       pbVar3 = (basic_string *)(auStack_a4 + 4);
            //       "20");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,pbVar3);
            //       pcVar1 = cocos2d::CCString::getCString(_dict);
            //       std::basic_string::basic_string((basic_string *)auStack_ac,pcVar1);
            //      pbVar3);
            //       std::basic_string::basic_string((basic_string *)auStack_a4,"44");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)auStack_a4);
            //       pcVar1 = cocos2d::CCString::getCString(_dict);
            //       std::basic_string::basic_string(this,pcVar1);
            //   auStack_a4);
            //       std::basic_string::basic_string((basic_string *)auStack_9c,"45");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)auStack_9c);
            //       pcVar1 = cocos2d::CCString::getCString(_dict);
            //       pcVar1);
            //       pbVar3 = (basic_string *)(auStack_9c + 4);
            //   auStack_9c);
            //       "21");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,pbVar3);
            //       demons = cocos2d::CCString::intValue(_dict);
            //      pbVar3);
            //       std::basic_string::basic_string((basic_string *)auStack_94,"22");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)auStack_94);
            //       playerRank = cocos2d::CCString::intValue(_dict);
            //   auStack_94);
            //       pbVar3 = (basic_string *)(auStack_94 + 4);
            //       "23");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,pbVar3);
            //       ball = cocos2d::CCString::intValue(_dict);
            //      pbVar3);
            //       std::basic_string::basic_string((basic_string *)auStack_8c,"24");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)auStack_8c);
            //       secretCoins = cocos2d::CCString::intValue(_dict);
            //   auStack_8c);
            //       pbVar3 = (basic_string *)(auStack_8c + 4);
            //       "25");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,pbVar3);
            //       userCoins = cocos2d::CCString::intValue(_dict);
            //      pbVar3);
            //       std::basic_string::basic_string((basic_string *)auStack_84,"26");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)auStack_84);
            //       diamonds = cocos2d::CCString::intValue(_dict);
            //   auStack_84);
            //       pbVar3 = (basic_string *)(auStack_84 + 4);
            //       "43");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,pbVar3);
            //       moons = cocos2d::CCString::intValue(_dict);
            //      pbVar3);
            //       std::basic_string::basic_string((basic_string *)auStack_7c,"48");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)auStack_7c);
            //       iconID = cocos2d::CCString::intValue(_dict);
            //   auStack_7c);
            //       std::basic_string::basic_string((basic_string *)(auStack_7c + 4),"53");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)(auStack_7c + 4));
            //       color1 = cocos2d::CCString::intValue(_dict);
            //   (auStack_7c + 4));
            //       std::basic_string::basic_string((basic_string *)auStack_74,"54");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)auStack_74);
            //       color2 = cocos2d::CCString::intValue(_dict);
            //   auStack_74);
            //       std::basic_string::basic_string((basic_string *)(auStack_74 + 4),"27");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)(auStack_74 + 4));
            //       color3 = cocos2d::CCString::intValue(_dict);
            //   (auStack_74 + 4));
            //       std::basic_string::basic_string((basic_string *)auStack_6c,"28");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)auStack_6c);
            //       newFriendRequest = cocos2d::CCString::boolValue(_dict);
            //   auStack_6c);
            //       std::basic_string::basic_string((basic_string *)(auStack_6c + 4),"30");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)(auStack_6c + 4));
            //       special = cocos2d::CCString::intValue(_dict);
            //   (auStack_6c + 4));
            //       std::basic_string::basic_string((basic_string *)auStack_64,"31");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)auStack_64);
            //       accountID = cocos2d::CCString::intValue(_dict);
            //   auStack_64);
            //       std::basic_string::basic_string((basic_string *)(auStack_64 + 4),"38");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)(auStack_64 + 4));
            //       messageState = cocos2d::CCString::intValue(_dict);
            //   (auStack_64 + 4));
            //       std::basic_string::basic_string((basic_string *)auStack_5c,"39");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)auStack_5c);
            //       friendReqCount = cocos2d::CCString::intValue(_dict);
            //   auStack_5c);
            //       std::basic_string::basic_string((basic_string *)(auStack_5c + 4),"40");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)(auStack_5c + 4));
            //       newFriendCount = cocos2d::CCString::intValue(_dict);
            //   (auStack_5c + 4));
            //       std::basic_string::basic_string((basic_string *)auStack_54,"49");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)auStack_54);
            //       iVar2 = cocos2d::CCString::intValue(_dict);
            //   auStack_54);
            //       score->m_friendStatus = userID;
            //       score->m_commentHistoryStatus = stars;
            //       std::basic_string::basic_string((basic_string *)(auStack_54 + 4),(basic_string *)auStack_ac) ;
            //       std::basic_string::operator=
            //                 ((basic_string *)&score->m_youtubeURL,(basic_string *)(auStack_54 + 4));
            //   (auStack_54 + 4));
            //       std::basic_string::basic_string((basic_string *)auStack_4c,(basic_string *)(auStack_ac + 4)) ;
            //       std::basic_string::operator=((basic_string *)&score->m_twitterURL,(basic_string *)auStack_4c );
            //   auStack_4c);
            //       std::basic_string::basic_string
            //                 ((basic_string *)(auStack_4c + 4),(basic_string *)(auStack_a4 + 4));
            //       std::basic_string::operator=
            //                 ((basic_string *)&score->m_twitchURL,(basic_string *)(auStack_4c + 4));
            //   (auStack_4c + 4));
            //       score->m_glowEnabled = newFriendRequest;
            //       score->m_playerCube = demons;
            //       score->m_modBadge = iVar2;
            //       score->m_friendReqStatus = accountID;
            //       score->m_playerShip = playerRank;
            //       score->m_newMsgCount = messageState;
            //       score->m_newFriendCount = newFriendCount;
            //       score->m_playerBall = ball;
            //       score->m_playerUfo = secretCoins;
            //       score->m_playerWave = userCoins;
            //       score->m_playerRobot = diamonds;
            //       score->m_playerStreak = color3;
            //       score->m_playerSpider = moons;
            //       score->m_playerSwing = color1;
            //       score->m_playerJetpack = color2;
            //       score->m_playerExplosion = iconID;
            //       score->m_globalRank = special;
            //       score->m_friendReqCount = friendReqCount;
            //       std::basic_string::basic_string((basic_string *)auStack_44,"55");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)auStack_44);
            //       pcVar1 = cocos2d::CCString::getCString(_dict);
            //       pbVar3 = (basic_string *)(auStack_44 + 4);
            //       pcVar1);
            //       std::basic_string::operator=((basic_string *)&score->m_55,pbVar3);
            //      pbVar3);
            //   auStack_44);
            //       std::basic_string::basic_string((basic_string *)auStack_3c,"56");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)auStack_3c);
            //       pcVar1 = cocos2d::CCString::getCString(_dict);
            //       pbVar3 = (basic_string *)(auStack_3c + 4);
            //       pcVar1);
            //       std::basic_string::operator=((basic_string *)&score->m_56,pbVar3);
            //      pbVar3);
            //   auStack_3c);
            //       std::basic_string::basic_string((basic_string *)&__stack,"57");
            //       _dict = cocos2d::CCDictionary::valueForKey(dict,(basic_string *)&__stack);
            //       pcVar1 = cocos2d::CCString::getCString(_dict);
            //       std::basic_string::basic_string((basic_string *)&stack0xffffffd0,pcVar1);
            //       std::basic_string::operator=((basic_string *)&score->m_57,(basic_string *)&stack0xffffffd0) ;
            //   &stack0xffffffd0);
            //   &__stack);
            //   (auStack_a4 + 4));
            //   (auStack_ac + 4));
            //   auStack_ac);
            //     }
            // (auStack_114 + 4));
            // auStack_114);
            //   }
            //   if (___stack != __stack_chk_guard) {
            //                     /* WARNING: Subroutine does not return */
            //     __stack_chk_fail();
            //   }
        }
    }
    return;
}

    // Intellisesnse did not play nice w/me -_- moved to GJUserScore.h for now...
    // bool GJUserScore::init()
    // {
    //     m_username = "";
    //     m_iconID = 1;
    //     m_color1 = 0;
    //     m_color2 = 3;
    //     m_color3 = 0;
    //     m_iconType = 0;
    //     m_accountID = 0;
    //     return true;
    // }

    /* "member function "GJUserScore::isCurrentUser" may not be redeclared outside its class C/C++(392)"
     * I'll handle this bullshit later... -_- */
    // bool GJUserScore::isCurrentUser()
    // {
    //   bool currentUser;
    //   GJAccountManager *GJAM;
    //   GameManager *GM;
    //   GJUserScore *pGStack_18;
    //   size_t local_14;

    //   local_14 = __stack_chk_guard;
    //   pGStack_18 = this;
    //   GJAM = GJAccountManager::sharedState();
    //   if ((GJAM->m_accountID == GJAM->m_unkInt1) ||
    //      (GJAM->m_accountID - GJAM->m_unkInt1 != m_accountID)) {
    //     GM = GameManager::sharedState();
    //     std::basic_string::basic_string((basic_string *)&pGStack_18,(basic_string *)&GM->m_userUDID);
    //     currentUser = std::basic_string::operator==
    //                             ((basic_string *)&m_userUDID,(basic_string *)&pGStack_18);
    //     std::basic_string::~basic_string((basic_string *)&pGStack_18);
    //   }
    //   else {
    //     currentUser = true;
    //   }
    //   if (local_14 != __stack_chk_guard) {
    //                     /* WARNING: Subroutine does not return */
    //     __stack_chk_fail();
    //   }
    //   return currentUser;
    // }

    /* Same problem as above but it's clean enough as is, I'll optimize this down to ternaries like "a = (b > a) ? b : a" or "std::max()" later... */
void GJUserScore::mergeWithScore(GJUserScore * score)
{
    int a;
    int b;
    b = score->m_stars;
    a = m_stars;
    if (b <= a) {
        m_stars = a;
    }
    if (a < b) {
        m_stars = b;
    }
    a = m_demons;
    b = score->m_demons;
    if (b <= a) {
        m_demons = a;
    }
    if (a < b) {
        m_demons = b;
    }
    a = m_secretCoins;
    b = score->m_secretCoins;
    if (b <= a) {
        m_secretCoins = a;
    }
    if (a < b) {
        m_secretCoins = b;
    }
    a = m_creatorPoints;
    b = score->m_creatorPoints;
    if (b <= a) {
        m_creatorPoints = a;
    }
    if (a < b) {
        m_creatorPoints = b;
    }
    a = m_diamonds;
    b = score->m_diamonds;
    if (b <= a) {
        m_diamonds = a;
    }
    if (a < b) {
        m_diamonds = b;
    }
    a = m_moons;
    b = score->m_moons;
    if (b <= a){
        m_moons = a;
    }
    if (a < b){
        m_moons = b;
    }
}

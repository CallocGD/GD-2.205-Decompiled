#include "includes.h"
#include "cocos2d\cocos-headers\cocos2dx\support\zip_support\ZipUtils.h"



std::vector<std::string>splitToVector(std::string str, const char* delim){
    std::vector<std::string>vect;
    size_t __pos = 0;
    size_t place = str.find(delim, 0);
    size_t end = str.length();
    std::string sub;
    while (true) {
        sub = str.substr(__pos, place - __pos);
        if (sub.length() != 0 || __pos != end){
            vect.emplace_back(sub);
        }
        if (place == std::string::npos) break;
        __pos = place + 1;
        place = str.find(delim,__pos);
    }
    return vect;
}


void SongInfoObject::addTags(std::string tagData){
    if (tagData.length() != 0) {

        /* I don't know exactly what is going on here, this is my best guess. 
         * I am not familiar with these tags...*/
        if (tagData == "."){
            auto vect = splitToVector(tagData, ".");
            for (size_t i = 0; i < vect.size(); i++){
                int maybeKey = atoi(vect[i].c_str());
                if (maybeKey > 0){
                    m_tags[i] = vect;
                }
            }
        }
    }
};


bool SongInfoObject::canEncode()
{
    return true;
}

SongInfoObject* SongInfoObject::create(
		int songID, 
		std::string songName, 
		std::string artistName, 
		int artistID, 
		float filesize, 
		std::string youtubeVideo, 
		std::string youtubeChannel, 
		std::string url, 
		int priority
	){
    
    auto song = new SongInfoObject;
    if (song != nullptr && song->init(
        songID, songName, artistName, artistID, filesize,
        youtubeVideo, youtubeChannel, url, priority)){
        song->autorelease();
        return song;
    }
    CC_SAFE_DELETE(song);
    return nullptr;
}







void SongInfoObject::encodeWithCoder(DS_Dictionary *dsdict)

{

  bool NoYoutube;
// TODO: Name GameManager class Member 
//   NoYoutube = GameManager::sharedState()->m_new;
    dsdict->setIntegerForKey("kCEK",6);
    dsdict->setIntegerForKey("1",m_songID);
    dsdict->setStringForKey("2", m_songName);
    dsdict->setStringForKey("4", m_artistName);
    dsdict->setIntegerForKey("3",m_artistID);
    dsdict->setFloatForKey("5",m_fileSize);
    if (NoYoutube == false) {
        if (m_youtubeVideo.length() != 0) {
            dsdict->setStringForKey("6", m_youtubeVideo);
        }
        if (m_youtubeChannel.length() != 0) {
        dsdict->setStringForKey("7", m_youtubeChannel);
        }
        dsdict->setStringForKey("10", m_songUrl);
    }
    dsdict->setIntegerForKey("9",m_priority);
    return;
}


SongInfoObject* SongInfoObject::create(cocos2d::CCDictionary *dict){
    return create(
        dict->valueForKey("1")->intValue(),
        dict->valueForKey("2")->getCString(),
        dict->valueForKey("4")->getCString(), 
        dict->valueForKey("3")->intValue(),
        dict->valueForKey("5")->floatValue(),
        dict->valueForKey("6")->getCString(),
        dict->valueForKey("7")->getCString(),
        cocos2d::ZipUtils::urlDecode(dict->valueForKey("10")->getCString()),
        dict->valueForKey("9")->intValue()
    );
}

SongInfoObject* SongInfoObject::create(int songID){
    auto info =  create(songID, "Unknown", "", 0, 0.0, "", "", "", -1);
    info->m_UnknownSong = true;
    return info;
}

SongInfoObject* SongInfoObject::createWithCoder(DS_Dictionary* dsdict){
    return create(
        dsdict->getIntegerForKey("1"),
        dsdict->getStringForKey("2"),
        dsdict->getStringForKey("4"),
        dsdict->getIntegerForKey("3"),
        dsdict->getFloatForKey("5"),
        dsdict->getStringForKey("6"),
        dsdict->getStringForKey("7"),
        dsdict->getStringForKey("10"),     
        dsdict->getIntegerForKey("9")
    );
}

/* Skipped: Unsolved functions */
/* basic_string * __thiscall SongInfoObject::getTagsString(SongInfoObject *this) */

bool SongInfoObject::containsTag(int tagID){
    return m_tags.find(tagID) != m_tags.end();
}


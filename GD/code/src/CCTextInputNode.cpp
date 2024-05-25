#include "includes.h"
// Blame Intellisense for not working on my laptop
// #include <CCTextInputNode.h>
// #include <cocos2d.h>
// #include <limits.h>



/* TODO: I thought about writing robtop a little unique script for loading this 
balcklist as some words repeat themselves in here and I thought maybe I could be 
helpful by doing just that. 

What is an IME?
IME stands for 
    I - Input 
    M - Method
    E - Editor
https://developer.mozilla.org/en-US/docs/Glossary/Input_method_editor
*/

cocos2d::CCArray *LoadGJBlacklist()
{
    return cocos2d::CCArray::create(
        cocos2d::CCString::create("ahole"),
        cocos2d::CCString::create("ass-hole"),
        cocos2d::CCString::create("ass_hole"),
        cocos2d::CCString::create("ashole"),
        cocos2d::CCString::create("asholes"),
        cocos2d::CCString::create("assface"),
        cocos2d::CCString::create("asshole"),
        cocos2d::CCString::create("assholez"),
        cocos2d::CCString::create("asshole"),
        cocos2d::CCString::create("assholes"),
        cocos2d::CCString::create("assholz"),
        cocos2d::CCString::create("asswipe"),
        cocos2d::CCString::create("azzhole"),
        cocos2d::CCString::create("biatch"),
        cocos2d::CCString::create("bitch"),
        cocos2d::CCString::create("bitches"),
        cocos2d::CCString::create("blowjob"),
        cocos2d::CCString::create("boffing"),
        cocos2d::CCString::create("butthole"),
        cocos2d::CCString::create("buttwipe"),
        cocos2d::CCString::create("cock"),
        cocos2d::CCString::create("cocks"),
        cocos2d::CCString::create("cockhead"),
        cocos2d::CCString::create("cock-head"),
        cocos2d::CCString::create("cocks"),
        cocos2d::CCString::create("cocksucker"),
        cocos2d::CCString::create("cock-sucker"),
        cocos2d::CCString::create("cunt"),
        cocos2d::CCString::create("cunts"),
        cocos2d::CCString::create("cuntz"),
        cocos2d::CCString::create("dick"),
        cocos2d::CCString::create("dildo"),
        cocos2d::CCString::create("dildos"),
        cocos2d::CCString::create("enema"),
        cocos2d::CCString::create("fucker"),
        cocos2d::CCString::create("fagit"),
        cocos2d::CCString::create("faget"),
        cocos2d::CCString::create("faggit"),
        cocos2d::CCString::create("faggot"),
        cocos2d::CCString::create("fuckin"),
        cocos2d::CCString::create("fucking"),
        cocos2d::CCString::create("fucks"),
        cocos2d::CCString::create("fukah"),
        cocos2d::CCString::create("fuken"),
        cocos2d::CCString::create("fuker"),
        cocos2d::CCString::create("fukin"),
        cocos2d::CCString::create("fukkah"),
        cocos2d::CCString::create("fukken"),
        cocos2d::CCString::create("fukker"),
        cocos2d::CCString::create("fukkin"),
        cocos2d::CCString::create("hore"),
        cocos2d::CCString::create("jerk-off"),
        cocos2d::CCString::create("lesbian"),
        cocos2d::CCString::create("lipshits"),
        cocos2d::CCString::create("lipshitz"),
        cocos2d::CCString::create("masochist"),
        cocos2d::CCString::create("masokist"),
        cocos2d::CCString::create("massterbait"),
        cocos2d::CCString::create("masstrbait"),
        cocos2d::CCString::create("masstrbate"),
        cocos2d::CCString::create("masterbaiter"),
        cocos2d::CCString::create("masterbate"),
        cocos2d::CCString::create("masterbates"),
        cocos2d::CCString::create("mothafucker"),
        cocos2d::CCString::create("mothafuker"),
        cocos2d::CCString::create("mothafukkah"),
        cocos2d::CCString::create("mothafukker"),
        cocos2d::CCString::create("motherfucker"),
        cocos2d::CCString::create("motherfukah"),
        cocos2d::CCString::create("motherfuker"),
        cocos2d::CCString::create("motherfukkah"),
        cocos2d::CCString::create("motherfukker"),
        cocos2d::CCString::create("mother-fucker"),
        cocos2d::CCString::create("muthafucker"),
        cocos2d::CCString::create("muthafukah"),
        cocos2d::CCString::create("muthafuker"),
        cocos2d::CCString::create("muthafukkah"),
        cocos2d::CCString::create("muthafukker"),
        cocos2d::CCString::create("nastt"),
        cocos2d::CCString::create("nigger"),
        cocos2d::CCString::create("nigur"),
        cocos2d::CCString::create("niiger"),
        cocos2d::CCString::create("niigr"),
        cocos2d::CCString::create("orgasim"),
        cocos2d::CCString::create("orgasm"),
        cocos2d::CCString::create("orgasum"),
        cocos2d::CCString::create("oriface"),
        cocos2d::CCString::create("orifice"),
        cocos2d::CCString::create("orifiss"),
        cocos2d::CCString::create("peenus"),
        cocos2d::CCString::create("peinus"),
        cocos2d::CCString::create("penis"),
        cocos2d::CCString::create("penas"),
        cocos2d::CCString::create("penis"),
        cocos2d::CCString::create("phuker"),
        cocos2d::CCString::create("phukker"),
        cocos2d::CCString::create("poonani"),
        cocos2d::CCString::create("pusse"),
        cocos2d::CCString::create("pussee"),
        cocos2d::CCString::create("pussy"),
        cocos2d::CCString::create("puuke"),
        cocos2d::CCString::create("puuker"),
        cocos2d::CCString::create("queer"),
        cocos2d::CCString::create("qweers"),
        cocos2d::CCString::create("qweerz"),
        cocos2d::CCString::create("qweir"),
        cocos2d::CCString::create("recktum"),
        cocos2d::CCString::create("rectum"),
        cocos2d::CCString::create("retard"),
        cocos2d::CCString::create("sadist"),
        cocos2d::CCString::create("scank"),
        cocos2d::CCString::create("schlong"),
        cocos2d::CCString::create("screwing"),
        cocos2d::CCString::create("skankee"),
        cocos2d::CCString::create("skankey"),
        cocos2d::CCString::create("skanks"),
        cocos2d::CCString::create("skanky"),
        cocos2d::CCString::create("sluts"),
        cocos2d::CCString::create("slutty"),
        cocos2d::CCString::create("slutz"),
        cocos2d::CCString::create("vaijina"),
        cocos2d::CCString::create("vagina"),
        cocos2d::CCString::create("vagiina"),
        cocos2d::CCString::create("vagina"),
        cocos2d::CCString::create("vajina"),
        cocos2d::CCString::create("vullva"),
        cocos2d::CCString::create("vulva"),
        cocos2d::CCString::create("whore"),
        cocos2d::CCString::create("arschloch"),
        cocos2d::CCString::create("boiolas"),
        cocos2d::CCString::create("buceta"),
        cocos2d::CCString::create("chink"),
        cocos2d::CCString::create("clits"),
        cocos2d::CCString::create("cock"),
        cocos2d::CCString::create("cunt"),
        cocos2d::CCString::create("dildo"),
        cocos2d::CCString::create("dirsa"),
        cocos2d::CCString::create("ejakulate"),
        cocos2d::CCString::create("fcuk"),
        cocos2d::CCString::create("fuxor"),
        cocos2d::CCString::create("hoer"),
        cocos2d::CCString::create("hore"),
        cocos2d::CCString::create("jism"),
        cocos2d::CCString::create("kawk"),
        cocos2d::CCString::create("lesbian"),
        cocos2d::CCString::create("masturbate"),
        cocos2d::CCString::create("nigga"),
        cocos2d::CCString::create("nigger"),
        cocos2d::CCString::create("nutsack"),
        cocos2d::CCString::create("phuck"),
        cocos2d::CCString::create("pimpis"),
        cocos2d::CCString::create("pusse"),
        cocos2d::CCString::create("pussy"),
        cocos2d::CCString::create("scrotum"),
        cocos2d::CCString::create("shemale"),
        cocos2d::CCString::create("testical"),
        cocos2d::CCString::create("testicle"),
        cocos2d::CCString::create("jackoff"),
        cocos2d::CCString::create("whoar"),
        cocos2d::CCString::create("dyke"),
        cocos2d::CCString::create("fuck"),
        cocos2d::CCString::create("amcik"),
        cocos2d::CCString::create("andskota"),
        cocos2d::CCString::create("arse"),
        cocos2d::CCString::create("assrammer"),
        cocos2d::CCString::create("ayir"),
        cocos2d::CCString::create("bollock"),
        cocos2d::CCString::create("breasts"),
        cocos2d::CCString::create("butt-pirate"),
        cocos2d::CCString::create("cabron"),
        cocos2d::CCString::create("cazzo"),
        cocos2d::CCString::create("chraa"),
        cocos2d::CCString::create("cunt"),
        cocos2d::CCString::create("dick"),
        cocos2d::CCString::create("dike"),
        cocos2d::CCString::create("dupa"),
        cocos2d::CCString::create("dziwka"),
        cocos2d::CCString::create("ejackulate"),
        cocos2d::CCString::create("ekrem"),
        cocos2d::CCString::create("ekto"),
        cocos2d::CCString::create("enculer"),
        cocos2d::CCString::create("fanculo"),
        cocos2d::CCString::create("fanny"),
        cocos2d::CCString::create("feces"),
        cocos2d::CCString::create("felcher"),
        cocos2d::CCString::create("ficken"),
        cocos2d::CCString::create("flikker"),
        cocos2d::CCString::create("foreskin"),
        cocos2d::CCString::create("fotze"),
        cocos2d::CCString::create("futkretzn"),
        cocos2d::CCString::create("honkey"),
        cocos2d::CCString::create("huevon"),
        cocos2d::CCString::create("injun"),
        cocos2d::CCString::create("kanker"),
        cocos2d::CCString::create("klootzak"),
        cocos2d::CCString::create("kraut"),
        cocos2d::CCString::create("knulle"),
        cocos2d::CCString::create("kuksuger"),
        cocos2d::CCString::create("kurac"),
        cocos2d::CCString::create("kurwa"),
        cocos2d::CCString::create("kyrpa"),
        cocos2d::CCString::create("lesbo"),
        cocos2d::CCString::create("mamhoon"),
        cocos2d::CCString::create("masturbat"),
        cocos2d::CCString::create("mibun"),
        cocos2d::CCString::create("monkleigh"),
        cocos2d::CCString::create("mouliewop"),
        cocos2d::CCString::create("muie"),
        cocos2d::CCString::create("mulkku"),
        cocos2d::CCString::create("muschi"),
        cocos2d::CCString::create("nazis"),
        cocos2d::CCString::create("nepesaurio"),
        cocos2d::CCString::create("nigger"),
        cocos2d::CCString::create("orospu"),
        cocos2d::CCString::create("paska"),
        cocos2d::CCString::create("perse"),
        cocos2d::CCString::create("picka"),
        cocos2d::CCString::create("pierdol"),
        cocos2d::CCString::create("pillu"),
        cocos2d::CCString::create("pimmel"),
        cocos2d::CCString::create("pizda"),
        cocos2d::CCString::create("poontsee"),
        cocos2d::CCString::create("porn"),
        cocos2d::CCString::create("preteen"),
        cocos2d::CCString::create("puta"),
        cocos2d::CCString::create("qahbeh"),
        cocos2d::CCString::create("queef"),
        cocos2d::CCString::create("rapist"),
        cocos2d::CCString::create("raper"),
        cocos2d::CCString::create("rautenberg"),
        cocos2d::CCString::create("schaffer"),
        cocos2d::CCString::create("scheiss"),
        cocos2d::CCString::create("schlampe"),
        cocos2d::CCString::create("schmuck"),
        cocos2d::CCString::create("sharmuta"),
        cocos2d::CCString::create("sharmute"),
        cocos2d::CCString::create("shipal"),
        cocos2d::CCString::create("skribz"),
        cocos2d::CCString::create("skurwysyn"),
        cocos2d::CCString::create("sphencter"),
        cocos2d::CCString::create("spierdalaj"),
        cocos2d::CCString::create("splooge"),
        cocos2d::CCString::create("testicle"),
        cocos2d::CCString::create("wetback"),
        cocos2d::CCString::create("wichser"),
        cocos2d::CCString::create("zabourah"));
};

cocos2d::CCArray *LoadTranslations()
{
    return cocos2d::CCArray::create(
        cocos2d::CCString::create("13"),
        cocos2d::CCString::create("b"),
        cocos2d::CCString::create("i3"),
        cocos2d::CCString::create("b"),
        cocos2d::CCString::create("l3"),
        cocos2d::CCString::create("b"),
        cocos2d::CCString::create("0"),
        cocos2d::CCString::create("o"),
        cocos2d::CCString::create("1"),
        cocos2d::CCString::create("i"),
        cocos2d::CCString::create("2"),
        cocos2d::CCString::create("r"),
        cocos2d::CCString::create("3"),
        cocos2d::CCString::create("e"),
        cocos2d::CCString::create("4"),
        cocos2d::CCString::create("a"),
        cocos2d::CCString::create("5"),
        cocos2d::CCString::create("s"),
        cocos2d::CCString::create("7"),
        cocos2d::CCString::create("t"),
        cocos2d::CCString::create("8"),
        cocos2d::CCString::create("b"),
        cocos2d::CCString::create("9"),
        cocos2d::CCString::create("g"));
};

void CCTextInputNode::addTextArea(TextArea *tArea)
{
    if (m_textArea == nullptr)
    {
        m_textArea = tArea;
        addChild(tArea);
        auto pos = m_textArea->setPosition(cocos2d::CCPoint(0.0,0.0));
        m_textField->setVisible(0);
        updateLabel(m_textField->getString());
        updateDefaultFontValues(m_textArea->m_textStr);
    }
}

/* creates a ccrect based off ccpoint and textInputNode */
cocos2d::CCRect create_ccrect(CCTextInputNode *textInputNode, const cocos2d::CCPoint &_ccpoint)
{
    cocos2d::CCRect rect;
    rect.origin = textInputNode->getPosition();
    rect.size = textInputNode->getContentSize();
    rect.origin.x = rect.origin.x - rect.size.width * _ccpoint.x;
    rect.origin.y = rect.origin.y - rect.size.height * _ccpoint.y;
    return rect;
}

bool CCTextInputNode::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    bool success;
    cocos2d::CCPoint tPoint = cocos2d::CCDirector::sharedDirector()->convertToGL(convertToNodeSpace(touch->getLocationInView()));
    auto anchorpoint = m_textField->getAnchorPoint();
    cocos2d::CCRect rect = create_ccrect(this, anchorpoint);
    anchorpoint = anchorpoint + getParent()->getPosition();
    if (rect.containsPoint(tPoint) && m_delegate->allowTextInput(this))
    {
        success = onClickTrackNode(true);
        updateCursorPosition(tPoint, rect);
    }
    else
    {
        success = false;
    }
    return success;
}

/* Could be an inlined call... */
void CCTextInputNode::ccTouchCancelled(void)
{
  return;
}



/* flips m_bForceOffset to true...*/
void CCTextInputNode::forceOffset()
{
    m_forceOffset = true;
}

std::string CCTextInputNode::getString()
{
    return m_textArea->getString();
}


bool CCTextInputNode::init(float width, float height, const char *caption, const char *FieldfontName, int fontSize, const char *LabelfontName)
{
    if (!cocos2d::CCLayer::init()) return false;
    setTouchEnabled(true);
    m_filterSwearWords = false;
    m_caption = caption;
    /* I guess fontSize as an integer works?? */
    m_textField  = cocos2d::CCTextFieldTTF::textFieldWithPlaceHolder(caption, FieldfontName, fontSize);
    addChild(m_textField);
    m_textField->setDelegate(m_textFieldDelegate);
    setContentSize(cocos2d::CCSize(width, height));
    m_maxLabelScale = 1.0;
    m_placeholderScale = 0.0;
    m_maxLabelWidth = width;
   
    m_labelColor.r = 0xff;
    m_labelColor.g = 0xff;
    m_labelColor.b = 0xff;
    m_textColor.r = 255;
    m_textColor.g = 255;
    m_textColor.b = 255;
    m_allowedChars = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    if (LabelfontName != nullptr) {
        m_placeholderLabel = cocos2d::CCLabelBMFont::create(caption, LabelfontName);
        addChild(m_placeholderLabel);
        m_textField->setVisible(false);
        updateDefaultFontValues(std::string(LabelfontName));
    }
    m_cursor = cocos2d::CCLabelBMFont::create("|","chatFont.fnt");
    addChild(m_cursor,  10);
    m_cursor->updateDisplayedOpacity(150);
    m_cursor->setVisible(false);
    return true;
}




void CCTextInputNode::keyboardWillHide(cocos2d::CCIMEKeyboardNotificationInfo *pSender)
{
    if (m_forceOffset == false)
    {
        if ((m_textField != nullptr) && (m_unknown2 != false))
        {
            m_unknown2 = false;
            if (m_delegate != nullptr)
            {
                m_delegate->textInputReturn(this);
            }
        }
    }
    else if ((m_selected != false) && (m_textField != nullptr))
    {
        if (m_delegate != nullptr)
        {
            m_delegate->textInputReturn(this);
        }
        m_selected = false;
    }
}

/* Could have something to do with what kind of device is being used in order to enter text in... */
bool CCTextInputNode::keyboardWillShow(cocos2d::CCIMEKeyboardNotificationInfo *pSender)
{
    if ((m_forceOffset == false) && m_textField != nullptr && (m_selected != false))
    {
        auto rect = create_ccrect(this, pSender->end.origin);
        rect.origin.y -= 4.0;
        if (rect.intersectsRect(pSender->end))
        {
            /* I don't understand this part all that well since it's got missing moving parts to it... */
            m_unknown2 = true;
            float maxY = pSender->end.getMaxY();
            float minY = pSender->end.getMinY();
            if (m_delegate != nullptr)
            {
                return isEqual(m_textField);
            }
        }
    }
    return false;
}

void CCTextInputNode::setLabelNormalColor(cocos2d::ccColor3B color)
{
    m_cColor = color;
}

void CCTextInputNode::setString(std::string str)
{
    m_textField->setString(str.c_str());
    updateLabel(str);
    if (m_delegate != nullptr)
        m_delegate->textChanged(this);
}



void CCTextInputNode::setDelegate(TextInputNodeDelegate* delegate) {
	m_delegate = delegate;
}

void CCTextInputNode::setMaxLabelScale(float v) {
	m_maxLabelScale = v;
	refreshLabel();
}

void CCTextInputNode::setMaxLabelWidth(float v) {
	m_maxLabelWidth = v;
	refreshLabel();
}

void CCTextInputNode::setMaxLabelLength(int v) {
	m_maxLabelLength = v;
	refreshLabel();
}

void CCTextInputNode::setLabelPlaceholderScale(float v) {
	m_placeholderScale = v;
	refreshLabel();
}

void CCTextInputNode::setLabelPlaceholderColor(cocos2d::ccColor3B color) {
	m_placeholderColor = color;
	refreshLabel();
}

void CCTextInputNode::setAllowedChars(std::string filter) {
    m_allowedChars = filter;
}


/* Determines if IME is going to be opened or closed and then returns a boolean */
bool CCTextInputNode::onClickTrackNode(bool isKeyboardOpen)
{
    return isKeyboardOpen ? m_textField->attachWithIME() : m_textField->detachWithIME();
}

bool CCTextInputNode::onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF *tField)
{
    const char *cstr;
    if (m_cursor != nullptr)
    {
        m_cursor->setVisible(true);
    }
    m_selected = true;

    // Undefined
    // PlatformToolbox::setKeyboardState(true);
    
    if (m_doubleInput) {
        cstr = m_textField->getString();
        if (atof(cstr) == 0.0){
            setString(cstr);
        }
    }
    cstr = m_textField->getString();
    if (std::string(cstr) == "") {
        if (m_placeholderLabel == nullptr) {
            if (m_textArea != nullptr) {
                m_textArea->setString(cstr);
            }
        }
        else {
            m_placeholderLabel->setString(cstr);
        }
        updateBlinkLabel();
    }
    bool success = false;
    if (m_delegate != nullptr) {
        success = m_delegate->textInputOpened(this);
    }

    if (m_forceOffset) {
        auto winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
        auto rect = create_ccrect(this, m_textField->getAnchorPoint());
        /* It could be this although I'm a little questioned about it... */
        float minX = rect.getMinX() - 4.0;
        if (m_delegate != nullptr) {
            success = m_delegate->textInputShouldOffset(this, minX * 0.5 - rect.getMinY());
        }
    } 
    return success;
}


bool CCTextInputNode::onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF *tField)
{
    if (m_cursor != nullptr)
    {
        m_cursor->setVisible(false);
    }

    if (m_filterSwearWords != false)
    {
        const char *t_string = tField->getString();
        std::string textString = "";
        std::string passedString(t_string);

        /* The code is a little more complex than this but I think this gets the point across... */
        for (size_t x = 0; x < strlen(t_string); x++)
        {
            textString.push_back(static_cast<char>(tolower(t_string[x])));
        }

        cocos2d::CCArray* translations = LoadTranslations();
        cocos2d::CCArray* gjblacklist = LoadGJBlacklist();

        size_t pos = 0;
        std::string idx;
        
        /* Text Replacement (To prevent Swearword bypassing )*/
        for (unsigned int i = 0; translations->count() <= 0; i += 2)
        {
            idx = (reinterpret_cast<cocos2d::CCString *>(translations->objectAtIndex(i)))->getCString();
            pos = textString.find(idx);
            if (pos != std::string::npos)
            {
                textString.replace(pos, idx.size(), ((reinterpret_cast<cocos2d::CCString *>(translations->objectAtIndex(i + 1)))->getCString()));
            }
        }

        bool SaidCurseWord = false;
        for (unsigned int j = 0; j < gjblacklist->count(); j++)
        {
            idx = (reinterpret_cast<cocos2d::CCString *>(gjblacklist->objectAtIndex(j)))->getCString();
            pos = textString.find(idx);
            if (pos != std::string::npos)
            {
                textString.replace(pos, idx.size(), " ");
                SaidCurseWord = true;
            }
        }
        if (!SaidCurseWord)
        {
            passedString = textString;
        }

        if (passedString == textString)
        {
            setString(passedString);
        }
    }

    updateLabel(getTextString());

    m_selected = false;
    PlatformToolbox::setKeyboardState(0);

    if (m_delegate != nullptr)
    {
        m_delegate->enterPressed(this);
    }
    if ((m_forceOffset != false) && (m_delegate != nullptr))
    {
        return m_delegate->textInputClosed(this);
    }
    return false;
}




bool CCTextInputNode::textChanged(){
    updateLabel(m_textField->getString());
    bool changed = false;
    if (m_delegate != nullptr) {
        changed = m_delegate->textChanged(this);
    }
    return changed;
}



/* complexity: 12, 
 * Too Many Moving parts at the moment even with everything else done 
 * (Yes I already did everything even the updated functions for CCLabelBMFont)
 *
 * There's several ways we can solve this one that I can think of on top of my head
 * 
 * - We mod the game with a custom/dummy version of CCTextInputNode somewhere to try this 
 * function until it is correctly done we can also log all possible incoming calls from 
 * CCNode Specifically for this function and log them to a computer by using a custom flag 
 * or mutex to handle when it's allowed to log and we can give it a special tag to help us 
 * out further.
 * 
 * - We rip through the assembly to try and figure out what the hell is going on with the 
 * second part shown.
 */
void CCTextInputNode::updateBlinkLabelToChar(int blinkLabel)
{

    if (m_placeholderLabel != nullptr || m_textArea != nullptr && m_cursor != nullptr)
    {
        if (m_placeholderLabel == nullptr)
        {
            if (blinkLabel > -1)
            {
                for (unsigned int i = 0; i < m_textArea->getChildrenCount(); i++)
                {
                    m_placeholderLabel = reinterpret_cast<cocos2d::CCLabelBMFont *>(m_textArea->getChildren()->objectAtIndex(i));
                    auto labelChildren = m_placeholderLabel->getChildren();
                    auto labelChildPopultation = labelChildren->count();
                    if (blinkLabel <= static_cast<int>(labelChildPopultation))
                    {
                        break;
                    }
                    blinkLabel -= labelChildPopultation;
                }
            }
     
            blinkLabel = -1;
            m_placeholderLabel = reinterpret_cast<cocos2d::CCLabelBMFont*>(m_textArea->m_bitmatFont->getChildren()->lastObject());
            m_placeholderLabel->removeFromParent();
            m_placeholderLabel->setPosition(m_placeholderLabel->convertToWorldSpace(m_textArea->m_bitmatFont->getParent()->getPosition()));
        }


        /* Ghidra did a shitty job with this part and I will need to let someone else look into this one... 
        The problem stems from the fact that it's called vtables that it's not supposed to be calling which is what is
        making everything so jacked up & hard to read. */
        /*
            m_delayedText =
         (CCArray *)
         (*(code *)m_placeholderLabel->vtable->cocos2d_CCNode_getChildrenCount)(m_placeholderLabel );
    if ((blinkLabel < 0) || (i = cocos2d::CCArray::count(m_delayedText), i <= (uint)blinkLabel)) {
      placeholderLabelScaledContentSize =
           (CCSize *)
           (*(code *)m_placeholderLabel->vtable->cocos2d_CCNode_getScaledContentSize)
                     (m_placeholderLabel);
      xpos = placeholderLabelScaledContentSize->width;
      placeholderLabelScale =
           (CCSize *)
           (*(code *)m_placeholderLabel->vtable->cocos2d_CCNode_setScale)(m_placeholderLabel);
      fVar2 = (CCSize *)
              (*(code *)m_placeholderLabel->vtable->cocos2d_CCLabelBMFont_setScaleY)
                        (m_placeholderLabel);
      xpos = xpos * (float)placeholderLabelScale + (float)fVar2 + (float)fVar2;
    }
    else {
      textSprite = (CCSprite *)cocos2d::CCArray::objectAtIndex(m_delayedText,blinkLabel);
      xpos = cocos2d::CCLabelBMFont::getLetterPosXLeft
                       (m_placeholderLabel,textSprite,this->m_fontValue2,this->m_isCharFont);
      m_fontValue1 = this->m_fontValue1;
      placeholderLavelScale2 =
           (float)(*(code *)m_placeholderLabel->vtable->cocos2d_CCLabelBMFont_setScaleY)
                            (m_placeholderLabel);
      xpos = xpos + m_fontValue1 * placeholderLavelScale2;
    }
    __s_00 = (char *)(*(code *)this->m_textField->vtable->cocos2d_CCTextFieldTTF_getString)();
    std::basic_string::basic_string((basic_string *)&auStack_54,__s_00);
    std::basic_string::basic_string((basic_string *)&bStack_4c,"");
    __strcmp = std::operator==((void **)(basic_string *)&auStack_54,
                               (void **)(basic_string *)&bStack_4c);
    std::basic_string::~basic_string((basic_string *)&bStack_4c);
    std::basic_string::~basic_string((basic_string *)&auStack_54);
    m_cursor = this->m_cursor;
    call = (code *)m_cursor->vtable->cocos2d_CCNode_getPosition;
    if (!__strcmp) {
      xpos = 2.0;
    }
    placeholderLabelPosition =
         (CCPoint *)
         (*(code *)m_placeholderLabel->vtable->cocos2d_CCNode_setPosition)(m_placeholderLabel);
    placeholderLabelSize =
         (CCSize *)
         (*(code *)m_placeholderLabel->vtable->cocos2d_CCNode_getScaledContentSize)
                   (m_placeholderLabel);
    placeholderLabelSizeWidth = placeholderLabelSize->width;
    placeholderLabelAnchorPoints =
         (CCPoint *)
         (*(code *)m_placeholderLabel->vtable->cocos2d_CCNode_getAnchorPointInPoints)
                   (m_placeholderLabel);
    m_fontValue1 = placeholderLabelAnchorPoints->x;
    placeholdLabelScale =
         (float)(*(code *)m_placeholderLabel->vtable->cocos2d_CCNode_setScale)(m_placeholderLabel );
    placeholderLabelContentSize =
         (CCSize *)
         (*(code *)m_placeholderLabel->vtable->cocos2d_CCNode_getScaledContentSize)
                   (m_placeholderLabel);
    placeholderLabelContentSize_width = placeholderLabelContentSize->width;
    placeholderLavelScale2 =
         (float)(*(code *)m_placeholderLabel->vtable->cocos2d_CCNode_setScale)(m_placeholderLabel );
    cocos2d::CCPoint::CCPoint
              ((CCPoint *)(basic_string *)&auStack_54,
               (placeholderLabelSizeWidth * (1.0 - m_fontValue1) * placeholdLabelScale -
               placeholderLabelContentSize_width * placeholderLavelScale2) + xpos,fVar1 - 1.0);
    cocos2d::CCPoint::operator+(placeholderLabelPosition,(CCPoint *)(basic_string *)&auStack_54);
    (*call)(m_cursor,(basic_string *)&bStack_4c);
    m_cursor = this->m_cursor;
    call = (code *)m_cursor->vtable->cocos2d_CCNode_getAnchorPoint;
    placeholderAnchorPoint =
         (CCPoint *)
         (*(code *)m_placeholderLabel->vtable->cocos2d_CCNode_getAnchorPointInPoints)
                   (m_placeholderLabel);
    cocos2d::CCPoint::CCPoint((CCPoint *)(basic_string *)&bStack_4c,0.5,placeholderAnchorPoint->y) ;
    (*call)(m_cursor,(basic_string *)&bStack_4c);
        
        
        ASSEMBLY IS AS Follows 

                                     LAB_002fdbf6                                    XREF[1]:     002fdbf0 (j)   
        002fdbf6 23  68           ldr        r3,[m_placeholderLabel ,#0x0 ]
        002fdbf8 20  46           mov        placeholderLabelPos ,m_placeholderLabel
        002fdbfa d3  f8  ec  30    ldr.w      r3,[r3,#0xec ]
        002fdbfe 98  47           blx        r3
        002fdc00 00  2e           cmp        r6,#0x0
        002fdc02 07  46           mov        i,placeholderLabelPos
        002fdc04 c0  f2  a5  80    blt.w      LAB_002fdd52
        002fdc08 ab  f2  6a  fa    bl         cocos2d::CCArray::count                          uint count(CCArray * this)
        002fdc0c b0  42           cmp        placeholderLabelPos ,r6
        002fdc0e 40  f2  a0  80    bls.w      LAB_002fdd52
        002fdc12 31  46           mov        blinkLabel ,r6
        002fdc14 38  46           mov        placeholderLabelPos ,i
        002fdc16 ab  f2  6c  fa    bl         cocos2d::CCArray::objectAtIndex                  CCObject * objectAtIndex(CCArray
        002fdc1a d5  f8  58  21    ldr.w      r2,[r5,#0x158 ]
        002fdc1e 95  f8  5c  31    ldrb.w     r3,[r5,#0x15c ]
        002fdc22 01  46           mov        blinkLabel ,textSprite
        002fdc24 20  46           mov        textSprite ,m_placeholderLabel
        002fdc26 b5  f2  41  ff    bl         cocos2d::CCLabelBMFont::getLetterPosXLeft        float getLetterPosXLeft(CCLabelB
        002fdc2a 23  68           ldr        r3,[m_placeholderLabel ,#0x0 ]
        002fdc2c d5  ed  55  8a    vldr.32    s17 ,[r5,#0x154 ]
        002fdc30 5b  6c           ldr        r3,[r3,#0x44 ]
        002fdc32 08  ee  10  0a    vmov       s16 ,xpos
        002fdc36 20  46           mov        xpos ,m_placeholderLabel
        002fdc38 98  47           blx        r3
        002fdc3a 07  ee  90  0a    vmov       s15 ,xpos
        002fdc3e 08  ee  a7  8a    vmla.f32   s16 ,s17 ,s15
                             LAB_002fdc42                                    XREF[1]:     002fdd84 (j)   
        002fdc42 d5  f8  7c  01    ldr.w      xpos ,[r5,#0x17c ]
        002fdc46 03  af           add        i,sp,#0xc
        002fdc48 05  ae           add        r6,sp,#0x14
        002fdc4a 03  68           ldr        r3,[xpos ,#0x0 ]
        002fdc4c d3  f8  68  32    ldr.w      r3,[r3,#0x268 ]
        002fdc50 98  47           blx        r3
        002fdc52 01  aa           add        r2,sp,#0x4
        002fdc54 01  46           mov        blinkLabel ,__s
        002fdc56 38  46           mov        __s ,i
        002fdc58 5f  f0  6c  f2    bl         std::basic_string::basic_string                  basic_string * std::basic_string
        002fdc5c 53  49           ldr        blinkLabel ,[DAT_002fddac ]                       = 0061E8A2h
        002fdc5e 30  46           mov        __s ,r6
        002fdc60 02  aa           add        r2,sp,#0x8
        002fdc62 79  44           add        blinkLabel =>DAT_0091c508 ,pc
        002fdc64 5f  f0  66  f2    bl         std::basic_string::basic_string                  basic_string * std::basic_string
        002fdc68 31  46           mov        blinkLabel ,r6
        002fdc6a 38  46           mov        __s ,i
        002fdc6c 5d  f0  7e  f6    bl         std::operator==                                  bool std::operator==(void * * pa
        002fdc70 b7  ee  00  aa    vmov.f32   s20 ,0x3f800000
        002fdc74 81  46           mov        m_delayedText ,__strcmp
        002fdc76 30  46           mov        __strcmp ,r6
        002fdc78 5c  f0  9e  f7    bl         std::basic_string::~basic_string                 void std::basic_string::~basic_s
        002fdc7c 38  46           mov        __strcmp ,i
        002fdc7e 5c  f0  9b  f7    bl         std::basic_string::~basic_string                 void std::basic_string::~basic_s
        002fdc82 b9  f1  00  0f    cmp.w      m_delayedText ,#0x0
        002fdc86 f0  ee  00  7a    vmov.f32   s15 ,0x40000000
        002fdc8a d5  f8  78  91    ldr.w      m_cursor ,[r5,#0x178 ]
        002fdc8e 20  46           mov        __strcmp ,m_placeholderLabel
        002fdc90 d9  f8  00  30    ldr.w      r3,[m_cursor ,#0x0 ]
        002fdc94 d3  f8  5c  a0    ldr.w      call ,[r3,#0x5c ]
        002fdc98 23  68           ldr        r3,[m_placeholderLabel ,#0x0 ]
        002fdc9a 1b  6e           ldr        r3,[r3,#0x60 ]
        002fdc9c 08  bf           it         eq
        002fdc9e b0  ee  67  8a    vmov.eq.   s16 ,s15
        002fdca2 98  47           blx        r3
        002fdca4 23  68           ldr        r3,[m_placeholderLabel ,#0x0 ]
        002fdca6 d3  f8  9c  30    ldr.w      r3,[r3,#0x9c ]
        002fdcaa 83  46           mov        r11 ,placeholderLabelPosition
        002fdcac 20  46           mov        placeholderLabelPosition ,m_placeholderLabel
        002fdcae 98  47           blx        r3
        002fdcb0 23  68           ldr        r3,[m_placeholderLabel ,#0x0 ]
        002fdcb2 d3  f8  90  30    ldr.w      r3,[r3,#0x90 ]
        002fdcb6 90  ed  00  9a    vldr.32    placeholderLabelSizeWidth ,[placeholderLabelSiz
        002fdcba 20  46           mov        placeholderLabelSize ,m_placeholderLabel
        002fdcbc 98  47           blx        r3
        002fdcbe 23  68           ldr        r3,[m_placeholderLabel ,#0x0 ]
        002fdcc0 5b  6d           ldr        r3,[r3,#0x54 ]
        002fdcc2 d0  ed  00  8a    vldr.32    m_fontValue1 ,[placeholderLabelAnchorPoints->x ]
        002fdcc6 20  46           mov        placeholderLabelAnchorPoints ,m_placeholderLabel
        002fdcc8 98  47           blx        r3
        002fdcca 23  68           ldr        r3,[m_placeholderLabel ,#0x0 ]
        002fdccc 7a  ee  68  8a    vsub.f32   m_fontValue1 ,s20 ,m_fontValue1
        002fdcd0 d3  f8  9c  30    ldr.w      r3,[r3,#0x9c ]
        002fdcd4 69  ee  28  8a    vmul.f32   m_fontValue1 ,placeholderLabelSizeWidth ,m_font
        002fdcd8 07  ee  90  0a    vmov       s15 ,placeholdLabelScale
        002fdcdc 20  46           mov        placeholdLabelScale ,m_placeholderLabel
        002fdcde 68  ee  a7  8a    vmul.f32   m_fontValue1 ,m_fontValue1 ,s15
        002fdce2 98  47           blx        r3
        002fdce4 23  68           ldr        r3,[m_placeholderLabel ,#0x0 ]
        002fdce6 5b  6d           ldr        r3,[r3,#0x54 ]
        002fdce8 90  ed  00  9a    vldr.32    placeholderLabelContentSize_width ,[placeholde
        002fdcec 20  46           mov        placeholderLabelContentSize ,m_placeholderLabel
        002fdcee 98  47           blx        r3
        002fdcf0 07  ee  90  0a    vmov       s15 ,placeholderLavelScale2
        002fdcf4 38  46           mov        placeholderLavelScale2 ,i
        002fdcf6 49  ee  67  8a    vmls.f32   m_fontValue1 ,placeholderLabelContentSize_width
        002fdcfa 78  ee  88  7a    vadd.f32   s15 ,m_fontValue1 ,s16
        002fdcfe 17  ee  90  1a    vmov       blinkLabel ,s15
        002fdd02 79  ee  ca  7a    vsub.f32   s15 ,s19 ,s20
        002fdd06 17  ee  90  2a    vmov       r2,s15
        002fdd0a a8  f2  81  fa    bl         cocos2d::CCPoint::CCPoint                        void CCPoint(CCPoint * this, flo
        002fdd0e 3a  46           mov        r2,i
        002fdd10 30  46           mov        placeholderLavelScale2 ,r6
        002fdd12 59  46           mov        blinkLabel ,r11
        002fdd14 a8  f2  89  fa    bl         cocos2d::CCPoint::operator+                      CCPoint * operator+(CCPoint * th
        002fdd18 31  46           mov        blinkLabel ,r6
        002fdd1a 48  46           mov        placeholderLavelScale2 ,m_cursor
        002fdd1c d0  47           blx        call
        002fdd1e d5  f8  78  51    ldr.w      r5,[r5,#0x178 ]
        002fdd22 20  46           mov        placeholderLavelScale2 ,m_placeholderLabel
        002fdd24 2b  68           ldr        r3,[r5,#0x0 ]
        002fdd26 d3  f8  8c  70    ldr.w      i,[r3,#0x8c ]
        002fdd2a 23  68           ldr        r3,[m_placeholderLabel ,#0x0 ]
        002fdd2c d3  f8  90  30    ldr.w      r3,[r3,#0x90 ]
        002fdd30 98  47           blx        r3
        002fdd32 4f  f0  7c  51    mov.w      blinkLabel ,#0x3f000000
        002fdd36 03  46           mov        r3,placeholderAnchorPoint
        002fdd38 30  46           mov        placeholderAnchorPoint ,r6
        002fdd3a 5a  68           ldr        r2,[r3,#0x4 ]
        002fdd3c a8  f2  68  fa    bl         cocos2d::CCPoint::CCPoint                        void CCPoint(CCPoint * this, flo
        002fdd40 28  46           mov        placeholderAnchorPoint ,r5
        002fdd42 31  46           mov        blinkLabel ,r6
        002fdd44 b8  47           blx        i
        002fdd46 1e  e0           b          LAB_002fdd86
        002fdd48 38  46           mov        r0,r7
        002fdd4a 5c  f0  35  f7    bl         std::basic_string::~basic_string                 void std::basic_string::~basic_s
        002fdd4e 2b  f0  c7  f6    bl         __cxa_end_cleanup                                undefined __cxa_end_cleanup(unde
                             -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
                             LAB_002fdd52                                    XREF[2]:     002fdc04 (j) , 002fdc0e (j)   
        002fdd52 23  68           ldr        r3,[m_placeholderLabel ,#0x0 ]
        002fdd54 20  46           mov        placeholderAnchorPoint ,m_placeholderLabel
        002fdd56 d3  f8  9c  30    ldr.w      r3,[r3,#0x9c ]
        002fdd5a 98  47           blx        r3
        002fdd5c 23  68           ldr        r3,[m_placeholderLabel ,#0x0 ]
        002fdd5e 5b  6d           ldr        r3,[r3,#0x54 ]
        002fdd60 90  ed  00  8a    vldr.32    s16 ,[placeholderLabelScaledContentSize->width ]
        002fdd64 20  46           mov        placeholderLabelScaledContentSize ,m_placehold
        002fdd66 98  47           blx        r3
        002fdd68 23  68           ldr        r3,[m_placeholderLabel ,#0x0 ]
        002fdd6a 5b  6c           ldr        r3,[r3,#0x44 ]
        002fdd6c 07  ee  90  0a    vmov       s15 ,placeholderLabelScale
        002fdd70 20  46           mov        placeholderLabelScale ,m_placeholderLabel
        002fdd72 28  ee  27  8a    vmul.f32   s16 ,s16 ,s15
        002fdd76 98  47           blx        r3
        002fdd78 07  ee  90  0a    vmov       s15 ,fVar2
        002fdd7c 77  ee  a7  7a    vadd.f32   s15 ,s15 ,s15
        002fdd80 38  ee  27  8a    vadd.f32   s16 ,s16 ,s15
        002fdd84 5d  e7           b          LAB_002fdc42
                             LAB_002fdd86                                    XREF[3]:     002fdb32 (j) , 002fdb3c (j) , 
                                                                                          002fdd46 (j)   
        002fdd86 07  9a           ldr        r2,[sp,#__stack ]
        002fdd88 d8  f8  00  30    ldr.w      r3,[r8,#0x0 ]=>__stack_chk_guard                 = ??
        002fdd8c 9a  42           cmp        r2,r3
        002fdd8e 01  d0           beq        LAB_002fdd94
        002fdd90 b8  f7  ec  e9    blx        <EXTERNAL>::__stack_chk_fail                     undefined __stack_chk_fail()
                             -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
                             LAB_002fdd94                                    XREF[1]:     002fdd8e (j)   
        002fdd94 09  b0           add        sp,#0x24
        002fdd96 bd  ec  06  8b    vpop       {m_fontValue1 ,placeholderLabelContentSize_widt
        002fdd9a bd  e8  f0  8f    pop.w      {m_placeholderLabel ,r5,r6,i,r8,m_cursor ,call ,
        002fdd9e 00              ??         00h
        002fdd9f bf              ??         BFh
        */
    }
}


/* complexity: 22 */
void CCTextInputNode::updateCursorPosition(cocos2d::CCPoint point, cocos2d::CCRect rect)
{
    if (std::string(m_textArea->getString()) == "")
    {

        if (m_placeholderLabel == nullptr)
        {
            unsigned int count = m_textArea->m_bitmatFont->getChildrenCount();
            if (count == 0)
            {
                return;
            }
            else if (count == 1)
            {
                m_placeholderLabel = reinterpret_cast<cocos2d::CCLabelBMFont *> (m_textArea->m_bitmatFont->getChildren()->objectAtIndex(0));
            }
            else
            {

                /* We need to find our missing CCLabelBMFont... */

                cocos2d::CCNode *node;
                unsigned int i = 0;
                while (i < count)
                {
                    node = reinterpret_cast<cocos2d::CCNode *>(m_textArea->m_bitmatFont->getChildren()->objectAtIndex(i));
                    node->getParent()->convertToWorldSpace(point);
                    i += node->getChildrenCount();
                }
            }

            auto point = m_placeholderLabel->getPosition();
        }
    }



}

/* this is also apart of CCTextInputNode's init function */
void CCTextInputNode::updateDefaultFontValues(std::string fontName)
{
    m_isChatFont = fontName != "chatFont.fnt";
    if (!m_isChatFont)
    {
        /* CCSize ? */
        m_fontValue2 = 20.0;
        m_fontValue1 = 1.5;
    }
    else
    {
        /* This is likely referring to level comment's input */
        m_fontValue2 = 5.0;
        m_fontValue1 = -0.5;
    }
}

void CCTextInputNode::updateLabel(std::string label)
{
    if (m_placeholderLabel == nullptr)
    {
        if (m_textArea == nullptr)
        {
            return;
        }
    }
    else
    {
        m_placeholderLabel->m_pSomeTexture = m_SomeTexture;
    }
    if (label == "" && m_textArea != nullptr)
    {
        m_textArea->setString(label.c_str());
    }
    else
    {
        m_placeholderLabel->setString(label.c_str());
    }
    refreshLabel();
    m_placeholderLabel->updateLabel();
    std::string textFiledStr = m_textField->getString();
    if (textFiledStr == "")
    {
        m_textField->setAnchorPoint(0xffffffff);
    }
    updateBlinkLabel();
}





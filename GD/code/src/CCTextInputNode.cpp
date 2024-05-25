#include "includes.h"
// Blame Intellisense for not working on my laptop
// #include <CCTextInputNode.h>
// #include <cocos2d.h>
// #include <limits.h>




/* TODO: I thought about writing robtop a little unique script for loading this 
balcklist as some words repeat themselves in here and I thought maybe I could be 
helpful by doing just that. 

What is an IME?
IME stands for:
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

/* Might still exist as an inlined function... */
void CCTextInputNode::setProfanityFilter(bool value)
{
    m_filterProfanity = value;
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

    PlatformToolbox::setKeyboardState(true);
    
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
    /* IME Is closing so hide cursor... */
    if (m_cursor != nullptr)
    {
        m_cursor->setVisible(false);
    }

    /* Should we filter Profanity? */
    if (m_filterSwearWords)
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
            if (pos != std::string::npos) {
                textString.replace(pos, idx.size(), " ");
                SaidCurseWord = true;
            }
        }

        if (SaidCurseWord == false)
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
    PlatformToolbox::setKeyboardState(false);

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


void CCTextInputNode::refreshLabel(){

    if ((m_placeholderLabel == nullptr) && (m_textArea == nullptr)){
        return;
    }
    
    bool has_text = std::basic_string(m_textField->getString()) == "";


    if (m_placeholderLabel == nullptr) {
        if (m_textArea != nullptr) {
            m_textArea->colorAllLabels((has_text) ? m_labelColor : m_textColor);
        }
        return;
    }

    float label;

    if (has_text) {
        SET_COLOR: {
            m_placeholderLabel->setScale();

            label = m_maxLabelWidth / m_placeholderLabel->getContentSize().width;

            if (m_maxLabelWidth == label || m_maxLabelWidth < label != (m_maxLabelWidth || label)) {
                label = m_maxLabelWidth;
                label = label / m_placeholderLabel->getContentSize().width;
            }
            m_placeholderLabel->setScale(label);

            /* If there was no goto, this part wouldn't make very much sense.. */
            if (!has_text) {
                m_placeholderLabel->setColor(m_textColor);
                return;
            }

            m_placeholderLabel->setColor(m_labelColor);
        }
    }

    else {
        label = m_placeholderScale;
        if (label == 0.0 || label < 0.0 != label) 
            goto SET_COLOR;
        m_placeholderLabel->setScale(label);
    }
}


void CCTextInputNode::registerWithTouchDispatcher(){
    cocos2d::CCDirector::sharedDirector()->getTouchPadDispatcher()->addPrioTargetedDelegate(this,-500,false);
}


bool CCTextInputNode::textChanged(){
    updateLabel(m_textField->getString());
    bool changed = false;
    if (m_delegate != nullptr) {
        changed = m_delegate->textChanged(this);
    }
    return changed;
}

void CCTextInputNode::updateBlinkLabel()
{
    /* note: pLens is the blink label... */
    updateBlinkLabelToChar(m_textField->m_pLens);
}

void CCTextInputNode::updateBlinkLabelToChar(int blinkLabel)
{
    
    if (m_placeholderLabel != nullptr || m_textArea != nullptr && m_cursor != nullptr){

        float xpos, ypos;

        /* We need to find our placeholder label and update the blinkLabel depending on it's frame */
        
        if (m_placeholderLabel == nullptr) {
            if (blinkLabel > -1) {
                for (unsigned int i = 0; i < m_textArea->getChildrenCount(); i++) {
                    m_placeholderLabel = reinterpret_cast<cocos2d::CCLabelBMFont *>(m_textArea->getChildren()->objectAtIndex(i));
                    auto labelChildPopultation = m_placeholderLabel->getChildren()->count();
                    if (blinkLabel <= labelChildPopultation){
                        blinkLabel = -1;
                        break;
                    }
                    
                    blinkLabel -= labelChildPopultation;
                }
            } else {
                blinkLabel = -1;
            }

            m_placeholderLabel = reinterpret_cast<cocos2d::CCLabelBMFont*>(m_textArea->m_bitmatFont->getChildren()->lastObject());
            m_placeholderLabel->removeFromParent();
            auto LabelPos1 = m_placeholderLabel->convertToWorldSpace(m_textArea->m_bitmatFont->getParent()->getPosition());
            m_placeholderLabel->setPosition(LabelPos1);
            auto LabelPos2 = m_placeholderLabel->convertToWorldSpace(cocos2d::CCPointZero);
            ypos = (LabelPos2.x - LabelPos2.y) - LabelPos1.y;
        } else {
            ypos = 0.0;
        }
        auto delayed_text = m_placeholderLabel->getChildren();

        /* Solved by Making a Geode-mod that watchdogs this function so I could fix CCLabelBMFont's vtable, 
        I'll make tools in python that can generate watchdog code in the future */

        /* are we in a blink frame and if so reposition X to that position */
        if ((blinkLabel < 0) || (delayed_text->count() <= blinkLabel)){
        
            xpos = m_placeholderLabel->getContentSize().width * m_placeholderLabel->getScale() + m_placeholderLabel->getScaleX() + m_placeholderLabel->getScaleX();
        } else {
            /* Had to use a little bit of hacky ram-watch with this function */
            xpos = m_placeholderLabel->getLetterPosXLeft(reinterpret_cast<cocos2d::CCSprite>(cocos2d::CCArray::objectAtIndex(m_delayedText, blinkLabel)), m_fontValue2, m_isCharFont);
            xpos += m_fontValue1 * m_placeholderLabel->getContentSize().width;
        }

        if (m_textField->getString() == std::string("")){
            xpos = 2.0;
        }

        /* === set cursor === 
        *             v
        *  hello world|
        */
        m_cursor->setPosition(m_cursor->getPosition() + CCPointMake(
            /* x */
            (m_placeholderLabel->getContentSize().width * (1.0 - m_fontValue1) *  m_placeholderLabel->getScaleX() - 
            (m_placeholderLabel->getContentSize().width + m_placeholderLabel->getScaleX())) + xpos, 
            /* y */
            space - 1.0));
    }
}


void CCTextInputNode::updateCursorPosition(cocos2d::CCPoint point, cocos2d::CCRect rect /* rect maybe unused...*/  )
{
    /* A Little Sloppy but it will do for now, I'll optimize and modernize this code later... */
    int char_population, character_count;
    int label_count;
    unsigned int visible, j;
    float posX, xpos;

    if (std::string(m_textArea->getString()) == "")
    {
        point = cocos2d::CCPointZero;
        
        /* find m_placeholderLabel */
        if (m_placeholderLabel == nullptr)
        {
            
            cocos2d::CCArray* delayedText = m_textArea->m_label->m_delayedText;
           
            if (delayedText->count() == 0) {
                m_textField->m_pLens = -1;
                return updateBlinkLabel();
            }
            else if (delayedText->count() == 1) {
                label_count = 0;
                m_placeholderLabel = reinterpret_cast<cocos2d::CCLabelBMFont *>(delayedText->objectAtIndex(0));
                char_population = 0;
            }
            else {                
                label_count = delayedText->count(); 
                visible = 0; 
                posX = -1.0;
                for (j = 0; j < delayedText->count(); j++){
                    auto node = reinterpret_cast<cocos2d::CCLabelBMFont*>(delayedText->objectAtIndex(j));
                    auto pos = node->getParent()->convertToNodeSpace(node->getPosition());
                    auto size = node->getContentSize();
                    xpos = (std::string(m_textField->getString()).length() + size.height * 0.5 * node->getScale()) - pos.y;
                    character_count = visible;
                    if (xpos < posX) {
                        char_population = (posX < 0.0) << 0x1f;
                        if (char_population > -1){
                            node = m_placeholderLabel;
                            xpos = posX;
                        }
                        character_count = j;
                        if (char_population < 0){
                            character_count = visible;
                        }
                    }
                    m_placeholderLabel = node;
                    j = character_count;
                    posX = xpos;
                }
            }
            if (j == 0){
                char_population = 0;
            }            
            else {
                visible = 0;
                char_population = 0;
                /* Do headcount of character population */
                while (visible < j){
                    character_count = reinterpret_cast<cocos2d::CCNode*>(delayedText->objectAtIndex(visible))->getChildren()->count();
                    visible += 1;
                    char_population += character_count;
                }
            }
        }
        point = m_placeholderLabel->getPosition();
    } else {
        label_count = 0;
        char_population = 0;
        point = m_placeholderLabel->getPosition();
    }
    posX = point.x;
    cocos2d::CCNode* labelParent = m_placeholderLabel->getParent();
    cocos2d::CCPoint labelPos = m_placeholderLabel->getPosition();
    labelParent->convertToWorldSpace(labelPos);
    cocos2d::CCArray* labels = m_placeholderLabel->getChildren();
    visible = j = 0;

    /* count up our currently visible labels again */
    for (j = 0; j < labels->count(); j++){
        if (reinterpret_cast<cocos2d::CCNode*>(labels->objectAtIndex(j))->isVisible()){
            visible += 1;
        }
    }
    
    if (visible != 0){
        j = 0;
        bool skipBlink;
        cocos2d::CCSprite* sprite = reinterpret_cast<cocos2d::CCSprite*>(labels->objectAtIndex(visible - 1));
        xpos = m_placeholderLabel->getLetterPosXRight(sprite, 0.0, false);
        cocos2d::CCPoint anchorPoint = m_placeholderLabel->getAnchorPoint();
        skipBlink = false;
        while (j < visible){
            sprite = reinterpret_cast<cocos2d::CCSprite*>(labels->objectAtIndex(visible - 1));
            if (sprite->isVisible()){
                float xPosRight = m_placeholderLabel->getLetterPosXRight(sprite, m_fontValue2, m_isChatFont);
                xPosRight += xpos;
                if (xPosRight >= posX){
                    float xPosLeft = m_placeholderLabel->getLetterPosXLeft(sprite, m_fontValue2, m_isChatFont);
                    if (xPosRight - posX < posX - ((xPosLeft + xpos) << 0x1f) < 0){
                        j += 1;
                    }
                    if (j < visible){
                        m_textField->m_pLens = j + char_population;
                        return updateBlinkLabel();
                    }
                    break;
                }
                if ((j == visible - 1) && (label_count > 1)){
                    m_textField->m_pLens = visible + char_population;
                    updateBlinkLabel();
                    skipBlink = true;
                }
            }
            j += 1;
        }
        if (skipBlink){
            return;
        }
    }
    m_textField->m_pLens = -1;
    return updateBlinkLabel();
}

/* this is also apart of CCTextInputNode's init function */
void CCTextInputNode::updateDefaultFontValues(std::string fontName)
{
    m_isChatFont = fontName != "chatFont.fnt";
    if (!m_isChatFont)
    {
        /* Level text */
        m_fontValue2 = 20.0;
        m_fontValue1 = 1.5;
    }
    else
    {
        /* Level Comments */
        m_fontValue2 = 5.0;
        m_fontValue1 = -0.5;
    }
}

void CCTextInputNode::updateLabel(std::string label)
{
    if ((m_placeholderLabel == nullptr) && (m_textArea == nullptr))
    {
        return;
    } 
    else {
        m_placeholderLabel->m_pSomeTexture = m_SomeTexture;
    }
    
    if (label == "" && m_textArea != nullptr) {
        m_textArea->setString(label.c_str());
    }
    else {
        m_placeholderLabel->setString(label.c_str());
    }
    
    refreshLabel();
    if (m_textField->getString() == std::string("")) {
        m_textField->m_pLens = -1;
    }
    updateBlinkLabel();
}


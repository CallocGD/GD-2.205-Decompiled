#include "includes.h"





CCIndexPath * CCIndexPath::CCIndexPathWithSectionRow(int _x, int _y)
{
    /* Dear Robtop: why didn't you use a create() method? -_- */

    CCIndexPath *idxp = new CCIndexPath;
    idxp->m_y = _y;
    idxp->m_x = _x;
    idxp->autorelease();
    return idxp;
}

void CCIndexPath::operator=(CCIndexPath *other)
{
    m_nLuaID = other->m_nLuaID;
    m_nTag = other->m_nTag;
    m_uReference = other->m_uReference;
    m_uAutoReleaseCount = other->m_uAutoReleaseCount;
    m_eObjType = other->m_eObjType;
    m_uObjectIdxInArray = other->m_uObjectIdxInArray;
    // 4 Unknown Fields...
    //   field9_0x24 = other->field9_0x24;
    //   field10_0x28 = other->field10_0x28;
    //   field11_0x2c = other->field11_0x2c;
    //   field12_0x30 = other->field12_0x30;
    m_y = other->m_y;
    m_x = other->m_x;
}



/* TODO: Optimize */

void TableViewCell::updateVisibility()
{
    float parent_pos_y;
    float cell_hieght;
    float height;
    
    if (m_tableView != nullptr) {
        cocos2d::CCSize cell_size = getContentSize();
        cell_hieght = cell_size.height;
        auto table_size = m_tableView->getContentSize();
        height = table_size.height;
        auto parent_pos = getParent()->getPosition();
        parent_pos_y = parent_pos.y;
        auto cell_pos = getPosition();
        parent_pos_y = parent_pos_y + cell_pos.y;
        if (
            parent_pos_y == height || 
            parent_pos_y < height != parent_pos_y || 
            height && (-1 <  (parent_pos_y < -cell_hieght) << 0x1f)) 
        {
           setVisible(true);
        }
    } else {
        setVisible(false);
    }
}





// If Anyone Wants In and wants this function reversed, Feel free to reverse it 
// and send me a pull request. - Calloc 
TableView::TableView(cocos2d::CCRect rect){}



TableView * TableView::create(
        TableViewDelegate* viewDelegate, 
        TableViewDataSource* source, 
        TableViewCellDelegate* delegate, 
        cocos2d::CCRect rect)
{
    TableView *tv = new TableView(rect);
    tv->m_tableDelegate = viewDelegate;
    tv->m_dataSource = source;
    tv->m_cellDelegate = delegate;
    tv->setPosition(CCPointMake(0.0f, 0.0f));
    tv->autorelease();
    return tv;
}




void TableView::cancelAndStoleTouch(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    cocos2d::CCSet* set = new cocos2d::CCSet;
    set->addObject(touch);
    set->autorelease();
    m_cancellingTouches = true;
    cocos2d::CCDirector::sharedDirector()->getKeyboardDispatcher();
    cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->touchesCancelled(set, event);
    m_cancellingTouches = false;
    claimTouch(touch);
}



bool TableView::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    if (CCScrollLayerExt::ccTouchBegan(touch , event)) {
        m_touchStart = touch;
        m_touchStartPosition2 = m_touchPosition2 = cocos2d::CCDirector::sharedDirector()->convertToGL(m_touchStart->getLocationInView());
        if (m_touchOutOfBoundary) {
            schedule(static_cast<cocos2d::SEL_SCHEDULE>(checkBoundaryOfContent));
            m_touchOutOfBoundary = true;
        }
        m_touchLastY = m_touchPosition2.y;
        return true;
 
    }
    return false;
}


void TableView::ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    if (m_touchMoved == true) {
        CCScrollLayerExt::ccTouchCancelled(touch, event);
        touchFinish(touch);
        if (m_touchOutOfBoundary != false) {
            unschedule(static_cast<cocos2d::SEL_SCHEDULE>(checkBoundaryOfContent));
            m_touchOutOfBoundary = false;
        }
    }
}


void TableView::ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCScrollLayerExt::ccTouchEnded(touch, event);
    touchFinish(touch);
    if (m_cancellingTouches != false) {
        unschedule(static_cast<cocos2d::SEL_SCHEDULE>(checkBoundaryOfContent));
        m_cancellingTouches = false;
    }
    return;
}

void TableView::ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
{
    CCScrollLayerExt::ccTouchMoved(touch, event);
    m_touchMoved = true;
    auto touchPoint = cocos2d::CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
    if (touch == m_touchStart) {
        m_touchPosition2 = m_touchPosition2 - touchPoint;
    }
    if (touchPoint.y - m_touchLastY <= 10.0) {
        m_touchLastY = touchPoint.y;
        cancelAndStoleTouch(touch, event);
    }
}


int TableView::checkBoundaryOfCell(TableViewCell *cell)
{
    /* NOTE: I've Optimized some portions because of how shitty this was for me to read... 
    * How many Redbulls did you have Robtop? */
    int i;
    cocos2d::CCPoint cellpos;
    cocos2d::CCSize cellsize;
    cellpos = cell->getPosition();
    cellsize = cell->getContentSize();
    float y = ((cellpos.y + cellsize.height) - m_contentLayer->getContentSize().height) + m_contentLayer->getPosition().y;
    cocos2d::CCSize contentSize = m_contentLayer->getContentSize();
    float contentY = m_contentLayer->getPosition().y;
    auto size = getContentSize();
    if ((size.height < y) || (y < 0.0 != y)) {
        contentY = (cellpos.y - contentSize.height) + cellsize.height;
        if ((size.height < contentY) || (contentY < 0.0 != cellsize.height)) {
            return 1;
        }
    }
    return 2;
}

int TableView::checkBoundaryOfCell(cocos2d::CCPoint& bounds, float posY)
{
    /* Seems I Optimized this one correctly */

    cocos2d::CCSize size = m_contentLayer->getContentSize();
    cocos2d::CCPoint pos = m_contentLayer->getPosition();
    float height = ((posY + bounds.y) - size.height) + pos.y;
    if ((size.height < height) || (height < 0.0)) {
        float Y = (bounds.y - size.height) + pos.y;
        if ((size.height < Y) || (Y < 0.0 != Y)) {
            return 1;
        }
    }
    return 2;
}



TableViewCell * TableView::cellForRowAtIndexPath(CCIndexPath &idx)
{
    TableViewCell *cell;
    unsigned int i = 0;
    while(true) {
        if (m_cellArray->count() <= i) {
          return nullptr;
        }
        cell = reinterpret_cast<TableViewCell *>(m_cellArray->objectAtIndex(i));
        if (((cell != nullptr) && (cell->m_x == idx.m_x)) && (cell->m_y == idx.m_y))
            break;
        i++;
    }
    return cell;
}


/* Not sure how accurate cellForTouch Is. Feel free to send a pull request is something isn't right... */

TableViewCell * TableView::cellForTouch(cocos2d::CCTouch *touch)
{
    TableViewCell* cell;
    auto Tpoint = cocos2d::CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
    if ((m_cellArray != nullptr) && m_cellArray->count()){
        for (unsigned int i = 0; i < m_cellArray->count(); i++) {
            cell = reinterpret_cast<TableViewCell *>(m_cellArray->objectAtIndex(i));
            if (cell != nullptr) {
                auto point = cocos2d::CCNode::convertToNodeSpace(Tpoint);
                auto cellX = cell->getPosition().x;
                auto cellWidth = cell->getContentSize().width;
                auto cellY = cell->getPosition().y;
                auto cellHeight = cell->getContentSize().height;
                auto anchorY = cell->getAnchorPoint().y;
                cellWidth = cellY - cellHeight * cellWidth;
                auto rect = CCRectMake(cellX - cellWidth * cell->getAnchorPoint().x , cellWidth, cellHeight, cell->getContentSize().height);
                rect.origin = cocos2d::CCPointZero;
                if (rect.containsPoint(point)) return cell;
            }
        }
    }
    return nullptr;
}





void TableView::scrollWheel(float pointX, float pointY)
{
    if (pointX != 0.0) {
        CCScrollLayerExt::scrollLayer(pointX);
    }
}



/* If there's anything else you want in here, reverse engineer it and send me a pull request */

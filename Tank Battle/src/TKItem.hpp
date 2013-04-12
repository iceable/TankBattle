#pragma once

#include <atlstr.h>
#include <atlimage.h>

enum ItemTypeEnum   //描述Item的类别
{
    ITEM_TANK,
    ITEM_BULLET,
    ITEM_BACKGROUND,
    ITEM_PROP,
    ITEM_OBSTACLE               //阻挡前进的东西
};
class TKItem
{
public:
    TKItem(void);
    ~TKItem(void);
    TKItem(CString imgDir);
    POINT getPos();
    const CImage* getImg();
    virtual int getItemType() = 0;
    int getIndex();
protected:
    POINT       _position;
    CImage      _img;
    int         _index; //绘制顺序 从0开始绘制
};


TKItem::TKItem(void)
{
}


TKItem::~TKItem(void)
{
}

TKItem::TKItem(CString imgDir)
{
    _img.Load(imgDir);
}

POINT TKItem::getPos()
{
    return _position;
}
int TKItem::getIndex()
{
    return _index;
}
const CImage* TKItem::getImg()
{
    return &_img;
}
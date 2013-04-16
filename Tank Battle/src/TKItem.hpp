#pragma once
#include "../include/hgesprite.h"

#include <atlstr.h>
#include <atlimage.h>
#include <map>

using namespace std;
typedef map<CString,HTEXTURE> TextureRecorder;



enum ItemTypeEnum   //描述Item的类别
{
    ITEM_TANK,
    ITEM_BULLET,
    ITEM_BACKGROUND,
    ITEM_PROP,
    ITEM_OBSTACLE               //阻挡前进的东西
};
class TKItem
    : public hgeSprite
{
public:
    
    TKItem(HTEXTURE tex, float x, float y, float w, float h);
    ~TKItem(void);

    int                             getIndex();
    void                            addTexture(CString texName, HTEXTURE hTex);
    HTEXTURE                        getTexture(CString texName);    
    HTEXTURE                        getCurrentTexture();

    hgeVector                       getPos() const;
    void                            setPos(float x, float y);

    virtual int                     getItemType() const = 0;


protected:
    int                     _index;             //绘制顺序 从0开始绘制
    TextureRecorder         _textures;
    hgeVector               _position;
    HTEXTURE                _hCurrentTex;

    bool                            setCurrentTexture(HTEXTURE hTex);
    bool                            setCurrentTexture(CString texName);
};


TKItem::TKItem(HTEXTURE tex, float x, float y, float w, float h):hgeSprite(tex,  x,  y,  w,  h)
{

}


TKItem::~TKItem(void)
{
}

int TKItem::getIndex()
{
    return _index;
}
void TKItem::addTexture(CString texName, HTEXTURE hTex)
{
    auto i = _textures.find(texName);
    if (i != _textures.end())
    {
        i->second = hTex;
    }
    else
    {
        _textures.insert(TextureRecorder :: value_type(texName,hTex));
    }
}

HTEXTURE TKItem::getTexture(CString texName)
{
    auto i = _textures.find(texName);
    if (i != _textures.end())
    {
        return i->second;
    }
    else
    {
        return 0;
    }
}

hgeVector TKItem::getPos() const
{
    return _position;
}

void TKItem::setPos(float x, float y)
{
    _position.x = x;
    _position.y = y;
}

HTEXTURE TKItem::getCurrentTexture()
{
    return _hCurrentTex;
}

bool TKItem::setCurrentTexture(HTEXTURE hTex)
{
    _hCurrentTex = hTex;
    return true;
}

bool TKItem::setCurrentTexture(CString texName)
{
    auto i = _textures.find(texName);
    if (i != _textures.end())
    {
        _hCurrentTex = i->second;
        return true;
    }
    return false;
}
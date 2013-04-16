#pragma once
#include "../include/hge.h"
#include "ItemsLogic.h"

class TKRender
{
public:
    
    ~TKRender(void);
    void paint();

private:
    HDC _hDC;
    HDC _hBufDC;
    HBITMAP _hBufBmp;
    HGE* _hge;

public:
    static TKRender& GetInstance()
    {
        static TKRender theInstance;
        return theInstance;
    }
private:
    TKRender(void);
    TKRender(const TKRender&);
    TKRender& operator= (const TKRender);
};


TKRender::TKRender(void)
{
     _hge = hgeCreate(HGE_VERSION);
}

TKRender::~TKRender(void)
{
    _hge->Release();
}

void TKRender::paint()
{
    ItemsLogic& logic = ItemsLogic::GetInstance();
    TKList& items = logic.getItems();
    _hge->Gfx_Clear(ARGB(255,255,255,255));
    _hge->Gfx_BeginScene();


    
    for (int i = 0; i < 3; i++)
    {
        TKItem* item = items.first();
        while ( item )
        {
            if (item->getIndex() == i) //°´ÕÕ»æÖÆË³Ðò »æÖÆ
            {
                hgeVector pt (0.0,0.0);
                item->SetTexture( item->getCurrentTexture() );
                pt = item->getPos();
                item->Render(pt.x, pt.y);
            }
            item = items.next();
        }
    }

    _hge->Gfx_EndScene();
}
#pragma once
#include "ItemsLogic.h"

class TKPainter
{
public:
    
    ~TKPainter(void);
    void paint(TKList& items);
    void init(HWND hWnd);
private:
    HDC _hDC;
    HDC _hBufDC;
    HBITMAP _hBufBmp;

public:
    static TKPainter& GetInstance()
    {
        static TKPainter theInstance;
        return theInstance;
    }
private:
    TKPainter(void);
    TKPainter(const TKPainter&);
    TKPainter& operator= (const TKPainter);
};


TKPainter::TKPainter(void)
{
}

TKPainter::~TKPainter(void)
{

}
void TKPainter::init(HWND hWnd)
{
    _hDC = GetDC(hWnd);
    _hBufDC = CreateCompatibleDC(_hDC);
    _hBufBmp = CreateCompatibleBitmap(_hDC, 800, 600);
    SelectObject(_hBufDC, _hBufBmp);
}
void TKPainter::paint(TKList& items)
{
    RECT rt = {0, 0, 800, 600};
    FillRect(_hBufDC, &rt, (HBRUSH)GetStockObject(WHITE_BRUSH));

    
    for (int i = 0; i < 3; i++)
    {
        TKItem* item = items.first();
        while ( item )
        {
            if (item->getIndex() == i) //°´ÕÕ»æÖÆË³Ðò »æÖÆ
            {
                POINT pt = item->getPos();
                const CImage* img = item->getImg();
                img->Draw(_hBufDC, pt.x, pt.y);
            }
            item = items.next();
        }
    }

    BitBlt(_hDC, 0, 0, 800, 600, _hBufDC, 0, 0, SRCCOPY);
}
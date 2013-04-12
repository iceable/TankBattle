#pragma once
#include "TKList.hpp"
#include "TKPainter.hpp"
#include "TKTank.hpp"
class ItemsLogic
{
public:
    
    ~ItemsLogic(void);
    void KeyProc();                               //按键处理
    void LogicProc();                             //逻辑处理
    void Start(HWND hWnd);                        //初始化

private:
    TKList              _items;
    TKTank*             _tank1;

public:
    static ItemsLogic& GetInstance()
    {
        static ItemsLogic theInstance;
        return theInstance;
    }

private:
    ItemsLogic(void);
    ItemsLogic(const ItemsLogic&);
    ItemsLogic& operator= (const ItemsLogic);
};

ItemsLogic::ItemsLogic(void)
{
}


ItemsLogic::~ItemsLogic(void)
{
    _items.clear();
}

void ItemsLogic::KeyProc()                     //按键处理
{

}
void ItemsLogic::Start(HWND hWnd)
{
    _tank1 = new TKTank("img\\p2tankU.gif");
    POINT pt = {300,300};
    _tank1->setPos(pt);
    _items.push_back(_tank1);
    TKPainter::GetInstance().init(hWnd);
}
void ItemsLogic::LogicProc()                   //逻辑处理
{
    static int time = GetTickCount();

    TKPainter &painter = TKPainter::GetInstance();

    if (GetTickCount() - time >= 20)
    {
        time = GetTickCount();

        _tank1->move();
    }

    painter.paint(_items);
}

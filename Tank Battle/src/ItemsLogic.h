#pragma once
#include "TKList.hpp"
#include "TKPainter.hpp"
#include "TKTank.hpp"
class ItemsLogic
{
public:
    
    ~ItemsLogic(void);
    void KeyProc();                               //��������
    void LogicProc();                             //�߼�����
    void Start(HWND hWnd);                        //��ʼ��

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

void ItemsLogic::KeyProc()                     //��������
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
void ItemsLogic::LogicProc()                   //�߼�����
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

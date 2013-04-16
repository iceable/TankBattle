#pragma once
#include "../include/hge.h"
#include "../include/hgevector.h"
#include "TKList.hpp"
#include "TKTank.hpp"
#include "TKkeys.hpp"
class ItemsLogic
{
public:
    
    ~ItemsLogic(void);
    void KeyProc(uint virKey, bool pressed);                                 //按键处理
    void LogicProc();                                                        //逻辑处理
    void Start(HGE *pHGE);                                                   //初始化
    TKList& getItems();

private:
    TKList              _items;
    TKTank*             _tank1;
    TKkeys              _keys;
    HGE*                _hge;

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

    bool isTankMove(const TKTank* tank);
    void tankDirChange(TKTank* tank);
};

ItemsLogic::ItemsLogic(void)
{
    _hge = hgeCreate(HGE_VERSION);
}


ItemsLogic::~ItemsLogic(void)
{
    _hge->Release();
    _items.clear();
}

void ItemsLogic::KeyProc(uint virKey, bool pressed)                     //按键处理
{
    if (pressed)
    {
        _keys.setPressed(virKey);
    }
    else
    {
        _keys.setReleased(virKey);
    }
}
void ItemsLogic::Start(HGE *pHGE)
{
    _tank1 = new TKTank(_hge->Texture_Load("img\\p1tankU.png"),\
        _hge->Texture_Load("img\\p1tankD.png"),\
        _hge->Texture_Load("img\\p1tankL.png"),\
        _hge->Texture_Load("img\\p1tankR.png"));

    _tank1->setPos(300, 300);
    _items.push_back(_tank1);

}
void ItemsLogic::LogicProc()                   //逻辑处理
{
    static int time = GetTickCount();



    if (GetTickCount() - time >= 16) //60帧/秒
    {
        time = GetTickCount();

        tankDirChange(_tank1);
        if( isTankMove(_tank1) )
        {
            _tank1->move();
        }
    }


}

bool ItemsLogic::isTankMove(const TKTank* tank)
{
   if(_keys.isPressed(VK_UP) && tank->getDir() == TANK_DIR_UP)
       return true;
   if(_keys.isPressed(VK_DOWN) && tank->getDir() == TANK_DIR_DOWN)
       return true;
   if(_keys.isPressed(VK_LEFT) && tank->getDir() == TANK_DIR_LEFT)
       return true;
   if(_keys.isPressed(VK_RIGHT) && tank->getDir() == TANK_DIR_RIGHT)
       return true;
   return false;
}

void ItemsLogic::tankDirChange(TKTank* tank)
{
    if (_keys.isPressed(VK_UP))
    {
        tank->setDir(TANK_DIR_UP);
    }
    else if (_keys.isPressed(VK_DOWN))
    {
        tank->setDir(TANK_DIR_DOWN);
    }
    else if (_keys.isPressed(VK_LEFT))
    {
        tank->setDir(TANK_DIR_LEFT);
    }
    else if (_keys.isPressed(VK_RIGHT))
    {
        tank->setDir(TANK_DIR_RIGHT);
    }
}

TKList& ItemsLogic::getItems()
{
    return _items;
}
#pragma once
#include "../include/hge.h"
#include "../include/hgevector.h"
#include "TKList.hpp"
#include "TKTank.hpp"
#include "TKkeys.hpp"
#include "TKShellMenu.hpp"

class ItemsLogic
{
public:
    
    ~ItemsLogic(void);
    void KeyProc(uint virKey, bool pressed);                                 //按键处理
    bool LogicProc();                                                        //逻辑处理
    void Start();                                                            //初始化
    void Pause();
    bool isPaused();
    bool isStart();
    TKList& getItems();
    TKShellMenu& getMenu();                 

private:
    TKList              _items;
    TKTank*             _myTank;
    TKkeys              _keys;
    HGE*                _hge;
    bool                _paused;
    TKShellMenu         _menu;
    bool                _start;
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
    bool MenuProc(int id);
};

ItemsLogic::ItemsLogic(void)
{
    _hge = hgeCreate(HGE_VERSION);
    _paused = true;
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
void ItemsLogic::Start()
{
    _myTank = new TKTank(_hge->Texture_Load("img\\p1tankU.png"),\
        _hge->Texture_Load("img\\p1tankD.png"),\
        _hge->Texture_Load("img\\p1tankL.png"),\
        _hge->Texture_Load("img\\p1tankR.png"));

    _myTank->setPos(300, 300);
    _items.push_back(_myTank);
    _start = false;
    _menu.Show(true);
}

void ItemsLogic::Pause()
{
    _paused = !_paused;
    _menu.Show(_paused);    
}
bool ItemsLogic::isPaused()
{
    return _paused;
}
bool ItemsLogic::LogicProc()                   //逻辑处理
{
    
    static int delta = _hge->Timer_GetTime();

    if (_keys.isPressed(VK_ESCAPE))             
    {
        if (_hge->Timer_GetTime()-delta > 1) //防止判断按键太快
        {
            delta = _hge->Timer_GetTime();
            if(!_paused) Pause();
            else return true;        //菜单状态下按下esc结束
        }
    }
    if (_paused)
    {
        int id = _menu.Update(_hge->Timer_GetDelta());
        return MenuProc(id);
    }
    tankDirChange(_myTank);
    if( isTankMove(_myTank) )
    {
        _myTank->move();
    }


    return false;
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

TKShellMenu& ItemsLogic::getMenu()
{
    return _menu;
}

bool ItemsLogic::isStart()
{
    return _start;
}

bool ItemsLogic::MenuProc(int id)
{
    static int lastid=0;
	if(id == -1)
	{
		switch(lastid)
		{
			case 1:
                _menu.Show(false);
                _paused = false;
                break;
			case 2:
                break;
			case 3:
                break;
			case 4:
                return true;
                break;
            default:
                
                break;
		}
        _menu.Enter();
	}
	else if(id) { lastid=id; _menu.Leave(); }
    return false;
}

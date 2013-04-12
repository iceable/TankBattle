#include "TKItem.hpp"
enum TankDirectEnum
{
    TANK_DIR_UP,
    TANK_DIR_DOWN,
    TANK_DIR_LEFT,
    TANK_DIR_RIGHT
};
class TKTank
    :public TKItem
{
public:
    TKTank(CString imgDir);
    ~TKTank();

    int                     getSpeed();
    POINT                   getPos();
    int                     getItemType();

    void                    setPos(POINT pt);
    void                    setSpeed(int speed);
    void                    setDir(int dir);
    void                    move();
private:
    static const int       SPEED_MAX = 100;
    int                     _speed;                         //x px per 20 ms
    int                     _dir;
};

TKTank::TKTank(CString imgDir):TKItem(imgDir)
{
    _speed = 1;
    _index = 1;
    _dir = TANK_DIR_UP;
    POINT pt = {0,0};
    _position = pt;
}

TKTank::~TKTank()
{
}

int TKTank::getItemType()
{
    return ITEM_TANK;
}

POINT TKTank::getPos()
{
    return _position;
}

void TKTank::setPos(POINT pt)
{
    _position = pt;
}
void TKTank::setDir(int dir)
{
    _dir = dir;
}

void TKTank::setSpeed(int speed)
{
    if (speed < 0 || speed > SPEED_MAX)
    {
        return;
    }
    _speed = speed;
}

void TKTank::move()
{
    if (_dir == TANK_DIR_UP)
    {
        _position.y -= _speed;
    }
    else if(_dir == TANK_DIR_DOWN)
    {
        _position.y += _speed;
    }
    else if(_dir == TANK_DIR_LEFT)
    {
        _position.x -= _speed;
    }
    else if(_dir == TANK_DIR_RIGHT)
    {
        _position.x += _speed;
    }

}
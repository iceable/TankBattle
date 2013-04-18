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
    TKTank(HTEXTURE upTex, HTEXTURE downTex, HTEXTURE leftTex, HTEXTURE rightTex);
    ~TKTank();
    

    int                     getSpeed() const;
    int                     getItemType() const;
    int                     getDir() const;

    void                    setSpeed(int speed);
    void                    setDir(int dir);
    void                    move();
private:
    static const int        SPEED_MAX = 100;
    int                     _speed;                         //x px per 16 ms
    int                     _dir;
    

};
TKTank::~TKTank()
{

}
TKTank::TKTank(HTEXTURE upTex, HTEXTURE downTex, HTEXTURE leftTex, HTEXTURE rightTex):TKItem(upTex, 0, 0, 60, 60)
{
    addTexture("TankUp", upTex);
    addTexture("TankDown", downTex);
    addTexture("TankLeft", leftTex);
    addTexture("TankRight", rightTex);
    _speed = 5;
    _index = 1;
    _dir = TANK_DIR_UP;
    setPos(0,0);
    //SetBlendMode(BLEND_ALPHAADD);
    //SetColor(0x00000000);
    setCurrentTexture("TankUp");
}


int TKTank::getItemType() const
{
    return ITEM_TANK;
}

int TKTank::getDir() const
{
    return _dir;
}

void TKTank::setDir(int dir)
{
    _dir = dir;
    if (_dir == TANK_DIR_UP)
    {
        setCurrentTexture("TankUp");
    }
    else if(_dir == TANK_DIR_DOWN)
    {
        setCurrentTexture("TankDown");
    }
    else if(_dir == TANK_DIR_LEFT)
    {
        setCurrentTexture("TankLeft");
    }
    else if(_dir == TANK_DIR_RIGHT)
    {
        setCurrentTexture("TankRight");
    }
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
#pragma once
#include "TKItem.hpp"

enum Bullet_Direct
{
    BULLET_DIR_UP,
    BULLET_DIR_DOWN,
    BULLET_DIR_LEFT,
    BULLET_DIR_RIGHT
};

class TKBullet
    :public TKItem
{
public:
    TKBullet();
    ~TKBullet();
    int getItemType();
    int getTeam();
    void setTeam(int team);
    void setSpeed(int speed);
    void setDirect(int direct);
private:
    int                 _speed;
    int                 _direct;
    int                 _team;                 
};

TKBullet::TKBullet()
{
    _speed = 6;
    _team = 1;
}

TKBullet::~TKBullet()
{
}

int TKBullet::getTeam()
{
    return _team;
}

void TKBullet::setTeam(int team)
{
    if (team > -1 && team < 2)
    {
        _team = team;
    }
}
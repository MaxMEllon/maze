#ifndef INCLUDED_CHARACTOR
#define INCLUDED_CHARACTOR

#include "env.h"
#include "window.h"

class Character
{
  public:
    Character();
    void move(int key, vector<vector<int>> map);
    int x();
    int y();
    int life();
    void decreaseLife();
    bool isSameLocation(int x, int y);
    bool isHit(int x, int y);
  protected:
    int _life;
    int _x;
    int _y;
};

#endif

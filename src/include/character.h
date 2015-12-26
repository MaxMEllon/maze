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
    void showLife();
    int life();
    void decreaseLife();
  protected:
    int _life;
    int _x;
    int _y;
};

#endif

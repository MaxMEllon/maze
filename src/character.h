#ifndef INCLUDED_CHARACTOR
#define INCLUDED_CHARACTOR

#include "env.h"

class Character
{
  public:
    Character();
    void move(int key, int **map, int width, int height);
    int x();
    int y();
  private:
    int _x;
    int _y;
};

#endif

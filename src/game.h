#ifndef INCLUDED_GAME
#define INCLUDED_GAME

#include "map.h"
#include "env.h"

class Game
{
  public:
    Game();
    void exec();
  private:
    bool judgeEnd();
    Map *map;
};

#endif


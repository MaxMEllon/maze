#ifndef INCLUDED_GAME
#define INCLUDED_GAME

#include "map.h"
#include "env.h"

class Game
{
  public:
    Game();
    ~Game();
    void exec();
    Map *map;
  private:
    bool judgeEnd();
};

#endif


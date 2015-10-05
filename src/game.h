#ifndef INCLUDED_GAME
#define INCLUDED_GAME

#include "map.h"

class Game
{
  public:
    Game();
    ~Game();
    Game& operator=(Game const& game) = default;
    void exec();
    Map *map;
  private:
    bool judgeEnd();
};

#endif


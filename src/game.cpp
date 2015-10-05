#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "game.h"

Game::Game()
{
  map = new Map();
}

void Game::exec()
{
  while ( ! this->judgeEnd() ) {
    map->print();
  }
}

bool Game::judgeEnd()
{
  int const **mp = map->maze();
  if ( mp[map->height()-2][map->width()-2] == CHARACTER ) { return true; }
}


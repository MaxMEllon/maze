#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "game.h"

Game::Game()
{
  this->map = new Map();
}

void Game::exec()
{
  while ( ! this->judgeEnd() ) {
    this->map->print();
  }
}

bool Game::judgeEnd()
{
  // TODO:
  // return mp[map->height()-2][map->width()-2] == CHARACTER;
  return 0;
}


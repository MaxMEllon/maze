#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "game.h"

Game::Game()
{
  map = new Map();
}
Game::Game(int width, int height)
{
  map = new Map(width, height);
}

void Game::exec()
{
  while ( ! this->judgeEnd() ) {
    map->print();
  }
  delete map;
  delete this;
}

bool Game::judgeEnd()
{
  return map->character->x() == map->height()-2 && map->character->y() == map->width()-2;
}


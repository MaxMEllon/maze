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
  int** mp = this->map->maze();
  return mp[map->height()-2][map->width()-2] == CHARACTER;
}

int main(int argc, char const* argv[])
{
  Game *game = new Game();
  game->exec();
  return 0;
}


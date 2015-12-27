#include "include/game.h"

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
  Title* title = new Title();
  title->show();
  while (! this->isEnd()) { map->next(); }
  delete map;
  delete this;
}

bool Game::isEnd()
{
  return map->character->life() <= 0
      || map->getMaze()[map->character->x()][map->character->y()] == GOAL;
}


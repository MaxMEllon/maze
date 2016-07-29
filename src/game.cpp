#include "include/game.h"

Game::Game()
{
  map = new Map();
}

Game::Game(int width, int height)
{
  map = new Map(width, height);
}

// @public {{{
void Game::exec()
{
  Title* title = new Title();
  title->title();
  while ( ! (this->isGameOver() || this->isGoal()) ) map->next();
  if ( this->isGameOver() ) {
    this->gameOver(title);
  } else if ( this->isGoal() ) {
    this->goal(title);
  }
  delete map;
  delete this;
}
// }}}

// @private {{{
bool Game::isGameOver()
{
  return map->character->life() <= 0;
}

bool Game::isGoal()
{
  return map->getMaze()[map->character->x()][map->character->y()] == GOAL;
}

void Game::goal(Title *titleDisplay)
{
  titleDisplay->goal();
}

void Game::gameOver(Title *titleDisplay)
{
  titleDisplay->gameOver();
}
// }}}

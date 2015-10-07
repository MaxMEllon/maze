#include "../include/env.h"
#include "../include/game.h"

int main()
{
  Game *game = new Game(30, 30);
  game->exec();
  return 0;
}

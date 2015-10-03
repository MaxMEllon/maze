#include "env.h"
#include "game.h"

int main(int argc, char const* argv[])
{
  Game *game = new Game();
  game->exec();
  return 0;
}

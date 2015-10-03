#include <cassert>
#include "../src/game.h"

void test1(void);
void test2(void);

int main(void)
{
  test1();
  test2();
  return 0;
}

void test1(void)
{
  int n = 10;
  assert(10 == n);
  std::cout << " ✔ : test1 complete" << std::endl;
}

void test2(void)
{
  Game *game = new Game();
  int const **mz = game->map->maze();
  int w = game->map->width();
  int h = game->map->height();
  assert(mz[w-2][h-2] == 2);
  std::cout << " ✔ : test2 complete" << std::endl;
}

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
  int wid = game->map->width();
  int hei = game->map->height();
  for ( int _i; _i < hei; _i++ ) {
    assert(mz[_i][0] == 1);
    assert(mz[_i][wid-1] == 1);
    for ( int _j; _j < wid; _j++ ) {
      assert(mz[0][_j] == 1);
      assert(mz[hei-1][_j] == 1);
    }
  }
  delete game;
  std::cout << " ✔ : test2 complete" << std::endl;
}

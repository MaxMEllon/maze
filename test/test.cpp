#include "../src/game.h"

#define OK_MARK "\x1b[1m\x1b[32m✔\x1b[49m\x1b[0m"
#define NG_MARK "\x1b[1m\x1b[40m✘\x1b[49m\x1b[0m"

void test1(void);
void test2(void);
void test3(void);
void testing(bool ope);

int flag = 0;

int main(void)
{
  test1();
  test2();
  // test3();
  return flag;
}

void testing(bool ope)
{
  if ( ope ) { return; }
  throw false;
}

void test1(void)
{
  int n = 10;
  try {
    testing(10 == n);
  } catch(bool e) {
    std::cout << "test1 : " << NG_MARK << std::endl;
    flag = 1;
    return;
  }
  std::cout << "test1 : " << OK_MARK  << std::endl;
}

void test2(void)
{
  Game *game = new Game();
  int const **mz = game->map->maze();
  int wid = game->map->width();
  int hei = game->map->height();
  try {
    for ( int _i; _i < hei; _i++ ) {
      testing(mz[_i][0] == 1);
      testing(mz[_i][wid-1] == 1);
      for ( int _j; _j < wid; _j++ ) {
        testing(mz[0][_j] == 1);
        testing(mz[hei-1][_j] == 1);
      }
    }
  } catch(bool e) {
    std::cout << "test2 : " << NG_MARK << std::endl;
    delete game;
    flag = 1;
    return;
  }
  delete game;
  std::cout << "test2 : " << OK_MARK << std::endl;
}

void test3(void)
{
  Game *game = new Game();
  int const **mz = game->map->maze();
  int wid = game->map->width();
  int hei = game->map->height();
  Character *character = new Character();
  int x = character->x();
  int y = character->y();
  character->move(KEY_DOWN, mz, wid, hei);
  character->move(KEY_RIGHT, mz, wid, hei);
  try {
    testing(x != character->x() || y != character->y());
  } catch (bool e) {
    std::cout << "test3 : " << NG_MARK << std::endl;
    delete game;
    flag = 1;
    return;
  }
  delete game;
  std::cout << "test3 : " << OK_MARK << std::endl;
}

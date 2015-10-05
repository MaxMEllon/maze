#include "../src/game.h"

#define OK_MARK "\x1b[1m\x1b[32m✔\x1b[49m\x1b[0m"
#define NG_MARK "\x1b[1m\x1b[40m✘\x1b[49m\x1b[0m"

void test1(void);
void test2(void);
void test3(void);

void testing(bool ope);
bool expect(bool ope);

int flag = 0;

int main(void)
{
  test1();
  test2();
  test3();
  return flag;
}

bool expect(bool ope) {
  bool f = true;
  try {
    testing(ope);
  } catch (bool e) {
    f = false;
  }
  if ( f ) {
    cout << OK_MARK;
  } else {
    cout << NG_MARK;
    flag = 1;
  }
  return f;
}

void testing(bool ope)
{
  if ( ope ) { return; }
  throw false;
}

void test1(void)
{
  cout << "test1 : ";
  int n = 10;
  expect(n == 10);
  cout << endl;
}

void test2(void)
{
  cout << "test2 : ";
  Game *game = new Game();
  int const **mz = game->map->maze();
  int wid = game->map->width();
  int hei = game->map->height();
  for ( int _i = 0; _i < hei; _i++ ) {
    expect(mz[_i][0] == 1);
    expect(mz[_i][wid-1] == 1);
    for ( int _j = 0; _j < wid; _j++ ) {
      expect(mz[0][_j] == 1);
      expect(mz[hei-1][_j] == 1);
    }
  }
  delete game;
  cout << endl;
}

void test3(void)
{
  cout << "test3 : ";
  Map *map = new Map();
  Character *character = new Character();
  int x = character->x();
  int y = character->y();
  character->move(KEY_DOWN,  map->maze(), map->width(), map->height());
  character->move(KEY_RIGHT, map->maze(), map->width(), map->height());
  expect(x != character->x() || y != character->y());
  delete map;
  delete character;
  cout << endl;
}

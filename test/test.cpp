#include "../src/include/game.h"

#define OK_MARK "\x1b[1m\x1b[32m✔\x1b[49m\x1b[0m"
#define NG_MARK "\x1b[1m\x1b[40m✘\x1b[49m\x1b[0m"

void test1(void);
void test2(void);
void test3(void);
void test4(void);

void testing(bool ope);
bool expect(bool ope);

int flag = 0;

int main(void)
{
  test1();
  test2();
  test3();
  test4();
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
  Game *game = new Game(5, 5);
  vector<vector<int>> mz = game->map->getMaze();
  int wid = game->map->width();
  int hei = game->map->height();
  for ( int _i = 0; _i < hei; _i++ ) {
    for ( int _j = 0; _j < wid; _j++ ) {
      expect(mz[0][_j] == 1 && mz[hei-1][_j] == 1 && mz[_i][0] == 1 && mz[_i][wid-1] == 1);
    }
  }
  delete game;
  cout << endl;
}

void test3(void)
{
  cout << "test3 : ";
  Map *map = new Map(15, 15);
  Character *character = new Character();
  int x = character->x();
  int y = character->y();
  character->move(KEY_DOWN,  map->getMaze(), map->width(), map->height());
  character->move(KEY_RIGHT, map->getMaze(), map->width(), map->height());
  expect(x != character->x() || y != character->y());
  delete character;
  delete map;
  cout << endl;
}

void test4(void)
{
  cout << "test4 : ";
  Map *map = new Map();
  vector<vector<int>> mz = map->getMaze();
  expect(mz[map->height()-2][map->width()-2] == GOAL);
  delete map;
  cout << endl;
}


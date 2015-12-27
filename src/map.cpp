#include "include/map.h"
#include "include/tui.h"

#define WIDTH  19
#define HEIGHT 19

Map::Map()
{
  __construct(WIDTH, HEIGHT);
}

Map::Map(int width, int height)
{
  __construct(width, height);
}

Map::~Map()
{
  Window::free();
}

/**
 * Map::width()
 * @return: map : vector<vector<int>> (2次元配列)
 * マップを取得します
 */
vector<vector<int>> Map::getMaze()
{
  return maze;
}

/**
 * Map::width()
 * @return: width : int
 * マップの横幅を取得します
 */
int Map::width()
{
  return _width;
}

/**
 * Map::height()
 * @return: height : int
 * マップの縦幅を取得します
 */
int Map::height()
{
  return _width;
}

/**
 * Map::__construct()
 * @param: width : int
 * @param: height : int
 * コンストラクタが呼び出す共通処理を行います．具体的には，
 * 座標の設定，迷路の生成，キャラクターの登録，Windowの初期化を行います．
 */
void Map::__construct(int width, int height)
{
  maze = vector<vector<int>>(width, vector<int>(height, ENPTY));
  this->_width  = width;
  this->_height = height;
  initMaze();
  character = new Character();
  enemy = new Enemy();
  enemy->spown(getMaze(), _width, _height);
  Window::initalize();
}

/**
 * Map::initMaze()
 * マップの元を生成します
 */
void Map::initMaze()
{
  for (int _i = 0; _i < height(); _i++ ) {
    maze[_i][0] = WALL;
    maze[_i][width()-1] = WALL;
    for (int _j = 0; _j < width(); _j++ ) {
      maze[0][_j] = WALL;
      maze[height()-1][_j] = WALL;
      if ( (_i%2 == 0) && (_j%2 == 0) ) { maze[_i][_j] = WALL; }
    }
  }
  createRoadOfMaze();
}

/**
 * Map::createRoadOfMaze()
 * 棒だおし法によって道を生成します
 */
void Map::createRoadOfMaze()
{
  int add[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  srand((unsigned)time(NULL));
  for (int _i = 2; _i < height()-2; _i += 2 ) {
    for (int _j = 2; _j < width()-2; _j += 2 ) {
      int dir;
      do {
        dir = rand() % 4;
      } while (maze[_i + add[dir][0]][_j + add[dir][1]] == WALL);
      maze[_i + add[dir][0]][_j + add[dir][1]] = WALL;
    }
  }
  maze[height()-2][width()-2] = GOAL;
}

/**
 * Map::next()
 * マップをワンステップ進行させます．
 * カーソルキーが入力されるまでは進行待ち状態になります
 */
void Map::next()
{
  Tui *tui = new Tui();
  tui->printCharacterLife(character->life());
  tui->printMap(this);
  character->move(Window::getKeyStroke(), getMaze());
  enemy->move(getMaze());
  if (character->isHit(enemy->x(), enemy->y())) { character->decreaseLife(); }
  delete tui;
}

/**
 * Map::__debug()
 * 現在のmapをデバッグ出力します
 * (環境変数TESTを定義すること)
 */
void Map::__debug()
{
#ifdef TEST
  for (int _i = 0; _i < height(); _i++ ) {
    for (int _j = 0; _j < width(); _j++ ) {
      cout << maze[_i][_j] << " ";
    }
    cout << endl;
  }
#endif
}


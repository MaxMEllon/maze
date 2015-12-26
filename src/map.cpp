#include "include/map.h"

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
      } while ( maze[_i + add[dir][0]][_j + add[dir][1]] == WALL );
      maze[_i + add[dir][0]][_j + add[dir][1]] = WALL;
    }
  }
  maze[height()-2][width()-2] = GOAL;
}

/**
 * TODO: Mapが持つべきでない．(?)
 * Map::print()
 * マップ全体の状態をWindowを用いて描画します
 * 各セルの描画にはMap::printChar()を用います
 * Issue: キャラとエネミーの当たり判定も行っている
 */
void Map::print()
{
  Window::eraseBuff();
  Window::moveCursol(0, 0);
  character->showLife();
  for (int _i = 0; _i < height(); _i++ ) {
    for (int _j = 0; _j < width(); _j++ ) {
      if (enemy->x()-1 <= character->x() && character->x() <= enemy->x()+1
       && enemy->y()-1 <= character->y() && character->y() <= enemy->y()+1) {
        enemy->despown();
        character->decreaseLife();
      }
      if (character->x() == _i && character->y() == _j) {
        printChar(CHARACTER);
        continue;
      }
      else if (enemy->x() == _i && enemy->y() == _j) {
        printChar(ENEMY);
        continue;
      }
      printChar(maze[_i][_j]);
    }
    Window::addString("\n");
  }
  int key = Window::getKeyStroke();
  character->move(key, getMaze());
  enemy->move(getMaze());
  Window::refreshWindow();
}

/**
 * TODO: Mapが持つべきでない．(?)
 * Map::printChar()
 * @param: _type : int
 * マップのセルをWindowに描画します
 */
void Map::printChar(int _type)
{
  switch ( _type ) {
    case WALL:
      Window::setColor(BLACK_RED);
      Window::addString("  ");
      break;
    case ENPTY:
      Window::setColor(BLACK_BLACK);
      Window::addString("  ");
      break;
    case GOAL:
      Window::setColor(BLACK_GREEN);
      Window::addString("[]");
      break;
    case CHARACTER:
      Window::setColor(BLACK_GREEN);
      Window::addString("\\/");
      break;
    case ENEMY:
      Window::setColor(BLACK_WHITE);
      Window::addString("><");
      break;
  }
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


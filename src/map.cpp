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

vector<vector<int>> Map::getMaze()
{
  return maze;
}

int Map::width()
{
  return _width;
}

int Map::height()
{
  return _width;
}

void Map::__construct(int width, int height)
{
  maze = vector<vector<int>>(width, vector<int>(height, 0));
  this->_width  = width;
  this->_height = height;
  initMaze();
  createRoadOfMaze();
  character = new Character();
  Window::initalize();
}

void Map::initMaze()
{
  int _i, _j;
  for ( _i = 0; _i < height(); _i++ ) {
    maze[_i][0] = 1;
    maze[_i][width()-1] = 1;
    for ( _j = 0; _j < width(); _j++ ) {
      maze[0][_j] = 1;
      maze[height()-1][_j] = 1;
      if ( (_i%2 == 0) && (_j%2 == 0) ) { maze[_i][_j] = 1; }
    }
  }
}

void Map::print()
{
  int _i, _j;
  int key = -1;
  Window::eraseBuff();
  Window::moveCursol(0, 0);
  for ( _i = 0; _i < height(); _i++ ) {
    for ( _j = 0; _j < width(); _j++ ) {
      if ( character->x() == _i && character->y() == _j ) {
        printChar(CHARACTER);
        continue;
      }
      printChar(maze[_i][_j]);
    }
    Window::addString("\n");
  }
  key = Window::getKeyStroke();
  character->move(key, getMaze(), width(), height());
  Window::refreshWindow();
}

void Map::printChar(int _place)
{
  switch ( _place ) {
    case WALL:
      Window::addString("@@");
      break;
    case ENPTY:
      Window::addString("  ");
      break;
    case GOAL:
      Window::addString("[]");
      break;
    case CHARACTER:
      Window::addString("<>");
      break;
  }
}

void Map::createRoadOfMaze()
{
  int _i, _j, dir;
  int add[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  srand((unsigned)time(NULL));
  for ( _i = 2; _i < height()-2; _i += 2 ) {
    for ( _j = 2; _j < width()-2; _j += 2 ) {
      do {
        dir = rand() % 4;
      } while ( maze[_i + add[dir][0]][_j + add[dir][1]] == WALL );
      maze[_i + add[dir][0]][_j + add[dir][1]] = WALL;
    }
  }
  maze[height()-2][width()-2] = GOAL;
}

void Map::__debug()
{
  int _i, _j;
  for ( _i = 0; _i < height(); _i++ ) {
    for ( _j = 0; _j < width(); _j++ ) {
      cout << maze[_i][_j] << " ";
    }
    cout << endl;
  }
}


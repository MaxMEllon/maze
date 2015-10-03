#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>

#include "map.h"

#define WIDTH  19
#define HEIGHT 19

Map::Map()
{
  this->__construct(WIDTH, HEIGHT);
}

Map::Map(int _width, int _height)
{
  this->__construct(_width, _height);
}

int const ** Map::maze()
{
  return (int const **)this->_maze;
}

int Map::width()
{
  return this->_width;
}

int Map::height()
{
  return this->_width;
}

void Map::__construct(int _width, int _height)
{
  int _i;
  this->_maze = new int*[_height];
  for ( _i = 0; _i < _height; _i++ ) { this->_maze[_i] = new int[_width]; }
  this->_width  = _width;
  this->_height = _height;
  this->initMaze();
  this->createRoadOfMaze();
  this->character = new Character();
  Window::initalize();
}

void Map::initMaze()
{
  int _i, _j;
  for ( _i = 0; _i < height(); _i++ ) {
    this->_maze[_i][0] = 1;
    this->_maze[_i][width()-1] = 1;
    for ( _j = 0; _j < width(); _j++ ) {
      this->_maze[0][_j] = 1;
      this->_maze[height()-1][_j] = 1;
      if ( (_i%2 == 0) && (_j%2 == 0) ) { this->_maze[_i][_j] = 1; }
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
        this->printChar(CHARACTER);
        continue;
      }
      this->printChar(this->_maze[_i][_j]);
    }
    Window::addString("\n");
  }
  Window::refreshWindow();
  key = Window::getKeyStroke();
  character->move(key, maze(), width(), height());
}

void Map::printChar(int _prace)
{
  switch ( _prace ) {
    case WALL:
      Window::addString("@@@");
      break;
    case ENPTY:
      Window::addString("   ");
      break;
    case GALL:
      Window::addString(" G ");
      break;
    case CHARACTER:
      Window::addString(" * ");
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
      } while ( this->_maze[_i + add[dir][0]][_j + add[dir][1]] == WALL );
      this->_maze[_i + add[dir][0]][_j + add[dir][1]] = WALL;
    }
  }
  this->_maze[height()-2][width()-2] = GALL;
}

void Map::__debug()
{
  int _i, _j;
  for ( _i = 0; _i < height(); _i++ ) {
    for ( _j = 0; _j < width(); _j++ ) {
      std::cout << this->_maze[_i][_j] << " ";
    }
    std::cout << std::endl;
  }
}


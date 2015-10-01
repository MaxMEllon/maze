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

int** Map::maze()
{
  return this->_maze;
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
  this->initScreen();
  this->createRoadOfMaze();
  this->character = new Character();
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

void Map::initScreen()
{
#ifndef WIN_OS
  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
#endif
}

void Map::print()
{
  int _i, _j;
  int key = -1;
#ifndef WIN_OS
  erase();
  move(0, 0);
#endif
  for ( _i = 0; _i < height(); _i++ ) {
    for ( _j = 0; _j < width(); _j++ ) {
      if ( character->x() == _i && character->y() == _j ) {
        this->printChar(CHARACTER);
        continue;
      }
      this->printChar(this->_maze[_i][_j]);
    }
#ifndef WIN_OS
    addstr("\n");
#endif
  }
#ifndef WIN_OS
  refresh();
  key = getch();
#endif
  character->move(key, maze(), width(), height());
}

void Map::printChar(int _prace)
{
#ifndef WIN_OS
  switch ( _prace ) {
    case WALL:
      addstr("@@@");
      break;
    case ENPTY:
      addstr("   ");
      break;
    case GALL:
      addstr(" G ");
      break;
    case CHARACTER:
      addstr(" * ");
      break;
  }
#endif
}

void Map::createRoadOfMaze()
{
  int _i, _j, dir;
  int add[4][2] = {{0,  1}, {0,  -1}, {1, 0}, {-1, 0}};
  srand((unsigned)time(NULL));
  for ( _i = 2; _i < height()-2; _i += 2 ) {
    for ( _j = 2; _j < width()-2; _j += 2 ) {
      do {
        dir = rand() % 4;
      } while ( this->_maze[_i + add[dir][0]][_j + add[dir][1]] == 1 );
      this->_maze[_i + add[dir][0]][_j + add[dir][1]] = 1;
    }
  }
  this->_maze[height()-2][width()-2] = 2;
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


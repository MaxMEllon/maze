#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include "character.h"

Character::Character()
{
  this->_x = 1;
  this->_y = 1;
}

int Character::x()
{
  return this->_x;
}

int Character::y()
{
  return this->_y;
}

void Character::move(int key, int **map, int width, int height)
{
#ifndef WIN_OS
  switch ( key ) {
    case KEY_UP:
      if ( map[_x-1][_y] == WALL ) { return; }
      if ( _x > 0 ) { this->_x--; }
      break;
    case KEY_DOWN:
      if ( map[_x+1][_y] == WALL ) { return; }
      if ( _x < width-1 ) { this->_x++; }
      break;
    case KEY_LEFT:
      if ( map[_x][_y-1] == WALL ) { return; }
      if ( _y > 0 ) { this->_y--; }
      break;
    case KEY_RIGHT:
      if ( map[_x][_y+1] == WALL ) { return; }
      if ( _y < width-1 ) { this->_y++; }
      break;
  }
#endif
}

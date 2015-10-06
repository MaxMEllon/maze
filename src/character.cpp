#include "include/character.h"

Character::Character()
{
  _x = 1;
  _y = 1;
}

int Character::x()
{
  return _x;
}

int Character::y()
{
  return _y;
}

void Character::move(int key, vector<vector<int>> map, int width, int height)
{
  switch ( key ) {
    case KEY_UP:
      if ( map[_x-1][_y] == WALL ) { return; }
      if ( _x > 0 ) { _x--; }
      break;
    case KEY_DOWN:
      if ( map[_x+1][_y] == WALL ) { return; }
      if ( _x < height-1 ) { _x++; }
      break;
    case KEY_LEFT:
      if ( map[_x][_y-1] == WALL ) { return; }
      if ( _y > 0 ) { _y--; }
      break;
    case KEY_RIGHT:
      if ( map[_x][_y+1] == WALL ) { return; }
      if ( _y < width-1 ) { _y++; }
      break;
  }
}

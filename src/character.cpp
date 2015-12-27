#include "include/character.h"

Character::Character()
{
  _x = 1;
  _y = 1;
  _life = 1;
}

int Character::x()
{
  return _x;
}

int Character::y()
{
  return _y;
}

/**
 * Character::move()
 * @param: key : int
 * @param: map : vector<vector<int>>
 * マップの横幅を取得します
 */
void Character::move(int key, vector<vector<int>> map)
{
  switch (key) {
    case KEY_UP:
      if (map[_x-1][_y] == WALL) { beep(); return; }
      if (_x > 0) { _x--; }
      break;
    case KEY_DOWN:
      if (map[_x+1][_y] == WALL) { beep(); return; }
      if (_x < (int)map.size()-1) { _x++; }
      break;
    case KEY_LEFT:
      if (map[_x][_y-1] == WALL) { beep(); return; }
      if (_y > 0) { _y--; }
      break;
    case KEY_RIGHT:
      if (map[_x][_y+1] == WALL) { beep(); return; }
      if (_y < (int)map[_x].size()-1) { _y++; }
      break;
  }
}

/**
 * Character::life()
 * キャラクタの体力を取得します
 */
int Character::life()
{
  return _life;
}

/**
 * Character::decreaseLife()
 * キャラクタの体力を取得します
 */
void Character::decreaseLife()
{
  _life--;
}

bool Character::isSameLocation(int x, int y)
{
  return _x == x && _y == y;
}

bool Character::isHit(int x, int y)
{
  return x-1 <= _x && _x < x+1
      && y-1 <= _y && _y < y+1;
}


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
  switch ( key ) {
    case KEY_UP:
      if ( map[_x-1][_y] == WALL ) { beep(); return; }
      if ( _x > 0 ) { _x--; }
      break;
    case KEY_DOWN:
      if ( map[_x+1][_y] == WALL ) { beep(); return; }
      if ( _x < (int)map.size()-1 ) { _x++; }
      break;
    case KEY_LEFT:
      if ( map[_x][_y-1] == WALL ) { beep(); return; }
      if ( _y > 0 ) { _y--; }
      break;
    case KEY_RIGHT:
      if ( map[_x][_y+1] == WALL ) { beep(); return; }
      if ( _y < (int)map[_x].size()-1 ) { _y++; }
      break;
  }
}

/**
 * TODO: Characterが持つべきでない．(?)
 * Character::showLife()
 * マップ全体の状態をWindowを用いて描画します
 * 各セルの描画にはMap::printChar()を用います
 */
void Character::showLife()
{
  Window::setColor(BLACK_WHITE);
  Window::addString("Life: ");
  for (int i = 0; i < life(); i++) {
    Window::setColor(BLACK_GREEN);
    Window::addString("   |");
  }
  Window::addString("\n");
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

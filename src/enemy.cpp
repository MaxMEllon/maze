#include "include/enemy.h"

Enemy::Enemy()
{
  _life = 1;
  _live = false;
  _name = "enemy";
}

string Enemy::name()
{
  return _name;
}

int Enemy::speed()
{
  return _speed;
}

void Enemy::spown(vector<vector<int>> map, int width, int height)
{
  _live = true;
  srand((unsigned)time(nullptr));
  _x = 0;
  _y = 0;
  while (map[_x][_y] != ENPTY) {
    _x = rand() % width;
    _y = rand() % height;
  }
}

void Enemy::despown()
{
  _live = false;
  _x = -1;
  _y = -1;
}

void Enemy::move(vector<vector<int>> map)
{
  if (! _live) { return; }
  srand((unsigned)time(NULL));
  int add[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int dir = rand() % 4;
  while (true) {
    dir = rand() % 4;
    if (map[_x + add[dir][0]][_y + add[dir][1]] == ENPTY) {
      _x += add[dir][0];
      _y += add[dir][1];
      return;
    }
  }
}


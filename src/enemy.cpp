#include "include/enemy.h"

/**
 * Enemy::Enemy()
 * Enemyの生成
 * 生成時はスポーンしません map上にスポーンさせるときは，Enemy::spown()を用いる
 */
Enemy::Enemy()
{
  _life = 1;
  _live = false;
  _name = "enemy";
}

/**
 * TODO: 現在使われていない関数
 * Enemy::name()
 * 名前の取得
 */
string Enemy::name()
{
  return _name;
}

/**
 * TODO: 現在使われていない関数
 * Enemy::speed()
 * 移動速度の取得
 */
int Enemy::speed()
{
  return _speed;
}

/**
 * Enemy::spown()
 * @param: マップ : vector<vector<int>>
 * @param: マップ横幅 : int
 * @param: マップ縦幅 : int
 * 敵をマップ上の空白スペースに発生させます
 * Issue: 2体以上spownさせた時，敵の上に敵が発生する
 */
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

/**
 * Enemy::despown()
 * 敵をデスポーンさせる．インスタンスは残っている
 * リスポーンさせるときは，再度spown()を呼び出す
 */
void Enemy::despown()
{
  _live = false;
  _x = -1;
  _y = -1;
}

/**
 * Enemy::move()
 * @param: マップ : vector<vector<int>>
 * 敵を移動させる（ランダム）
 */
void Enemy::move(vector<vector<int>> map)
{
  if (! _live) { return; }
  srand((unsigned)time(NULL));
  int add[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int dir;
  do {
    dir = rand() % 4;
  } while (map[_x + add[dir][0]][_y + add[dir][1]] != ENPTY);
  _x += add[dir][0];
  _y += add[dir][1];
}


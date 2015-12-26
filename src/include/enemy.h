#ifndef INCLUDED_ENEMY
#define INCLUDED_ENEMY

#include "character.h"

class Enemy : public Character
{
  public:
    Enemy();
    string name();
    int speed();
    void spown(vector<vector<int>> map, int width, int height);
    void despown();
    void move(vector<vector<int>> map);
  private:
    bool _live;
    string _name;
    int _speed;
};

#endif

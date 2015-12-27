#ifndef INCLUDED_MAP
#define INCLUDED_MAP

#include "character.h"
#include "enemy.h"
#include "window.h"

class Map
{
  public:
    Map();
    Map(int width, int height);
    Map& operator=(Map const& map) = default;
    ~Map();
    Character *character;
    Enemy *enemy;
    vector<vector<int>> getMaze();
    int height();
    int width();
    void __debug();
    void next();

  private:
    vector<vector<int>> maze;
    int _height;
    int _width;
    void __construct(int width, int height);
    void createRoadOfMaze();
    void initMaze();
};

#endif


#ifndef INCLUDED_MAP
#define INCLUDED_MAP

#include "character.h"
#include "window.h"

class Map
{
  public:
    Map();
    Map(int _width, int _height);
    Map& operator=(Map const& map) = default;
    ~Map();
    Character *character;
    vector<vector<int>> getMaze();
    int height();
    int width();
    void __debug();
    void print();

  private:
    std::vector<std::vector<int>> maze;
    int _height;
    int _width;
    void __construct(int _width, int _height);
    void createRoadOfMaze();
    void initMaze();
    void printChar(int _place);
};

#endif


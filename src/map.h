#include "character.h"
#include "env.h"

#ifndef INCLUDED_MAP
#define INCLUDED_MAP

class Map
{
  public:
    Map();
    Map(int _width, int _height);
    int** maze();
    int height();
    int width();
    void __debug();
    void print();

  private:
    Character *character;
    int** _maze;
    int _height;
    int _width;
    void __construct(int _width, int _height);
    void createRoadOfMaze();
    void initMaze();
    void initScreen();
    void printChar(int _prace);
};

#endif


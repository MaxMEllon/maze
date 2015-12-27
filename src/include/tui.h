#ifndef INCLUDED_TUI
#define INCLUDED_TUI

#include "map.h"
#include "character.h"
#include "enemy.h"
#include "window.h"

class Tui
{
  public:
    Tui();
    ~Tui();
    void printCharacterLife(int life);
    void printMap(Map * const maze);
  private:
    void printMapCell(int cell);
};

#endif

#include "include/tui.h"

/**
 * Tui::Tui()
 * Tuiのコンストラクタ
 * Map::next() の最初で呼ばれる必要があります
 */
Tui::Tui()
{
  Window::initalize();
  Window::eraseBuff();
  Window::moveCursol(0, 0);
}

/**
 * Tui::Tui()
 * Tuiのデスコラクタ
 * Map::next() の最後で呼ばれる必要があります
 */
Tui::~Tui()
{
  Window::refreshWindow();
}

/**
 * Tui::printCharacterLife()
 * @param: life : int
 * キャラクターのライフ をWindowに出力します
 */
void Tui::printCharacterLife(int life)
{
  Window::setColor(BLACK_WHITE);
  Window::addString("Life: ");
  for (int i = 0; i < life; i++) {
    Window::setColor(BLACK_GREEN);
    Window::addString("   |");
  }
  Window::addString("\n");
}

/**
 * Tui::printMap()
 * @param: maze : Map * const
 * 迷路をWindowに出力します
 */
void Tui::printMap(Map * const maze)
{
  for (int i = 0; i < maze->height(); i++ ) {
    for (int j = 0; j < maze->width(); j++ ) {
      int cell = maze->character->isSameLocation(i, j) ? CHARACTER
               : maze->enemy->isSameLocation(i, j) ? ENEMY
               : maze->getMaze()[i][j];
      printMapCell(cell);
    }
    Window::addString("\n");
  }
  Window::refreshWindow();
}

/**
 * Tui::printMapCell()
 * @param: cell : int
 * 迷路のCellをWindowに出力します
 */
void Tui::printMapCell(int cell)
{
  switch (cell) {
    case WALL:
      Window::setColor(BLACK_RED);
      Window::addString("  ");
      break;
    case ENPTY:
      Window::setColor(BLACK_BLACK);
      Window::addString("  ");
      break;
    case GOAL:
      Window::setColor(BLACK_GREEN);
      Window::addString("[]");
      break;
    case CHARACTER:
      Window::setColor(BLACK_GREEN);
      Window::addString("\\/");
      break;
    case ENEMY:
      Window::setColor(BLACK_WHITE);
      Window::addString("><");
      break;
  }
}

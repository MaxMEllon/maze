#ifndef INCLUDED_WINDOW
#define INCLUDED_WINDOW

#include "env.h"
#include <locale.h>

#define DEFAULT_COLOR 0
#define BLACK_RED 1
#define BLACK_BLACK 2
#define BLACK_GREEN 3
#define BLACK_WHITE 4

#define MAX_WINDOW_WIDTH 1000

struct Window
{
  static bool enable_color;
  static int  getKeyStroke();
  static void addString(const std::string string);
  static void eraseBuff();
  static void moveCursol(int x, int y);
  static void refreshWindow();
  static void insertNewLine();
  static void initalize();
  static void free();
  static void setColor(int colorID);
};

#endif

#ifndef INCLUDED_WINDOW
#define INCLUDED_WINDOW

#include "env.h"

struct Window
{
  static bool enable_color;
  static int  getKeyStroke();
  static void addString(const std::string string);
  static void eraseBuff();
  static void moveCursol(int x, int y);
  static void refreshWindow();
  static void initalize();
  static void free();
};

#endif

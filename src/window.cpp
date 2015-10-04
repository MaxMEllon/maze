#include "window.h"

void Window::initalize()
{
#ifndef TEST
  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
#endif
}

void Window::eraseBuff()
{
#ifndef TEST
  erase();
#endif
}

void Window::addString(const std::string string)
{
#ifndef TEST
  addstr(string.c_str());
#endif
}

void Window::moveCursol(int x, int y)
{
#ifndef TEST
  move(x, y);
#endif
}

void Window::refreshWindow()
{
#ifndef TEST
  refresh();
#endif
}

int Window::getKeyStroke()
{
#ifndef TEST
  return getch();
#endif
}

void Window::free()
{
#ifndef TEST
  endwin();
#endif
}

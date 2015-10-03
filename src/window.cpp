#include "window.h"

#include <ncurses.h>

void Window::initalize()
{
  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
}

void Window::eraseBuff()
{
  erase();
}

void Window::addString(const std::string string)
{
  addstr(string.c_str());
}

void Window::moveCursol(int x, int y)
{
  move(x, y);
}

void Window::refreshWindow()
{
  refresh();
}

int Window::getKeyStroke()
{
  return getch();
}

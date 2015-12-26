#include "include/window.h"

void Window::initalize()
{
#ifndef TEST
  // 画面生成
  initscr();
  cbreak();
  // キー入力を出力しない
  noecho();
  // キー入力有効
  keypad(stdscr, TRUE);
  // スクロールの有効
  scrollok(stdscr, TRUE);
  // スクロール最大行設定
  wscrl(stdscr, MAX_WINDOW_WIDTH);
  // カラー有効
  start_color();
  init_pair(BLACK_RED, COLOR_BLACK, COLOR_RED);
  init_pair(BLACK_GREEN, COLOR_BLACK, COLOR_GREEN);
  init_pair(BLACK_BLACK, COLOR_BLACK, COLOR_BLACK);
  init_pair(BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);
  setlocale(LC_ALL, "");
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
  printw(string.c_str());
#else
  cout << string.c_str();
#endif
}

void Window::insertNewLine()
{
#ifndef TEST
  (void)insertln();
#else
  cout << endl;
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
#else
  return -1;
#endif
}

void Window::free()
{
#ifndef TEST
  endwin();
#endif
}

void Window::setColor(int colorID)
{
#ifndef TEST
  attron(COLOR_PAIR(colorID));
#else
  cout << "setColor" << colorID << endl;
#endif
}

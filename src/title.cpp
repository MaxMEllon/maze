#include "include/title.h"

Title::Title()
{
  titleText =
    "---------------------------------------------------------\n"
    "                                                         \n"
    "                                                         \n"
    "                                                         \n"
    "       ##      ##                                        \n"
    "       ####  ####     ####    ######   ####              \n"
    "       ## #  # ##    ##  # #      ##  ##  ##             \n"
    "       ##  ##  ##    ##  # #    ##    ######             \n"
    "       ##      ##    ##  ##   ##      #                  \n"
    "       ##      ##     ######  ######   #####   ####      \n"
    "                                                         \n"
    "                                                         \n"
    "                                                         \n"
    "                                                         \n"
    "                                                         \n"
    "       ----  Prease key Press to start Game  ----        \n"
    "                                                         \n"
    "                                                         \n"
    "                                                         \n"
    "                                                         \n"
    "---------------------------------------------------------\n";
}

void Title::show()
{
  Window::initalize();
  Window::eraseBuff();
  Window::moveCursol(0, 0);
  Window::addString(this->titleText);
  int key = -1;
  while (key == -1) { key = Window::getKeyStroke(); }
}


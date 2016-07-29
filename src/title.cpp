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

  gameOverText = " GameOver !!! ";
  goalText = " GOAL !!! ";
}

void Title::title()
{
  this->show(this->titleText);
}

void Title::gameOver()
{
  this->show(this->gameOverText);
}

void Title::goal()
{
  this->show(this->goalText);
}

void Title::show(string const text)
{
  Window::initalize();
  Window::eraseBuff();
  Window::moveCursol(0, 0);
  Window::addString(text);
  int key = -1;
  while (key == -1) { key = Window::getKeyStroke(); }
}

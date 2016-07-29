#ifndef INCLUDED_TITLE
#define INCLUDED_TITLE

#include "window.h"

class Title
{
  public:
    Title();
    Title& operator=(Title const& title) = default;
    void title();
    void gameOver();
    void goal();
  private:
    string titleText;
    string gameOverText;
    string goalText;
    void show(string const text);
};

#endif

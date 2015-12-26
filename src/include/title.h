#ifndef INCLUDED_TITLE
#define INCLUDED_TITLE

#include "window.h"

class Title
{
  public:
    Title();
    void show();
    Title& operator=(Title const& title) = default;
  private:
    string titleText;
};

#endif

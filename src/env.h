#ifndef INCLUDED_ENV
#define INCLUDED_ENV

#include <string>
#include <sstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>

using namespace std;

template<class T> inline std::string toString(T x) {
  std::ostringstream sout;sout<<x;return sout.str();
}

typedef enum _PLACE_TYPE {
  ENPTY,
  WALL,
  GALL,
  CHARACTER
} PLACE_TYPE;

#endif

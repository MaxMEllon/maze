#ifndef INCLUDED_ENV
#define INCLUDED_ENV

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <sys/time.h>

using namespace std;

template<class T> inline std::string toString(T x) {
  std::ostringstream sout;sout<<x;return sout.str();
}

typedef enum _PLACE_TYPE {
  ENPTY = 0,
  WALL = 1,
  GOAL = 2,
  CHARACTER = 3,
  ENEMY = 4
} PLACE_TYPE;

#endif

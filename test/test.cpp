#include <cassert>
#include "../src/env.h"

void test1(void);

int main(void)
{
  test1();
  return 0;
}

void test1(void)
{
  int n = 10;
  assert(10 == n);
  std::cout << " ✔ : test1 complete" << std::endl;
}

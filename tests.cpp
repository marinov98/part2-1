#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "funcs.h"
#include "doctest.h"

TEST_CASE("Testing Test"){
  std::cout << "HELLO WORLD\n";
  CHECK(test()==22);
}

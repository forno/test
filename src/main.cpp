#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <random>
#include <string>
#include <string_view>
#include <utility>
#include <valarray>

#include <redland.h>

bool f()
{
  return 4;
}

int main(int argc, char** argv)
{
  std::cout << f() << '\n';
}

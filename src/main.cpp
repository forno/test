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

bool f();

bool f()
{
  return 4;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
  std::cout << f() << '\n';
}

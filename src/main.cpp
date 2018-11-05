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

int main(int argc, char** argv)
{
  const std::shared_ptr<int> p {new int};
  *p = 5;
  std::cout << *p << '\n';
}

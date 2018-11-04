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
  std::shared_ptr<int> p {new int};
  [](std::weak_ptr<int> s) {
    if (auto v {s.lock()})
      std::cout << "receive " << *v << '\n';
  }(p);
}

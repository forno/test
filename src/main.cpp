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

class C
  : public std::shared_ptr<int>
{
public:
  C(int* value)
    : std::shared_ptr<int>(value, [](auto p){delete p;})
  {
  }
};

int main(int argc, char** argv)
{
  C {new int};
}

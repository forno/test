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

class C
  : public std::shared_ptr<librdf_world>
{
public:
  C(librdf_world* value) noexcept
    : std::shared_ptr<librdf_world>(value, [](auto p){librdf_free_world(p);})
  {
  }

  ~C() noexcept;
};

int main(int argc, char** argv)
{
}

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include <xmaho/point/point.hpp>

template<typename T>
struct [[deprecated]] S {};

int main(int argc, char** argv)
{
  using namespace std;
  using namespace xmaho::point;

  constexpr Point p {3, 4};
  const auto euclidean_distance {norm(p)};
  static_assert(is_same_v<const double, decltype(euclidean_distance)>, "norm on ordinal 2 return floting point type");
  assert(abs(euclidean_distance - 5) < std::numeric_limits<decltype(euclidean_distance)>::epsilon());

  const auto taxicab_distance {norm<1>(p)};
  static_assert(is_same_v<const int, decltype(taxicab_distance)>, "norm on ordinal 1 return same as point value type");
  assert(taxicab_distance == 7);
 
  const auto uniform_norm {norm<numeric_limits<size_t>::max()>(p)};
  static_assert(is_same_v<const int, decltype(uniform_norm)>, "norm on ordinal max return same as point value type");
  assert(uniform_norm == 4);
}

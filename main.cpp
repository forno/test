#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <numeric>
#include <valarray>
#include <vector>

#include <xmaho/std_ext/valarray.hpp>

int main(int, char**)
{
  using namespace std;
  using namespace xmaho::std_ext;

  const valarray<int> v {1, -2, 2};
  const auto euclidean_distance {norm(v)};
  static_assert(is_same_v<const double, decltype(euclidean_distance)>, "norm on ordinal 2 return floting point type");
  assert(euclidean_distance == 3.); // It is correct operation with "==" because result is integer.
}

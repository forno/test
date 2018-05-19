#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

#include <Eigen/Dense>
#include <Eigen/Geometry>

inline constexpr auto pi {3.1415926535897932384626433832795029L};

template<typename T>
[[deprecated]]
constexpr void f(T)
{
}

template<typename T, typename... Args>
T get_input(std::basic_istream<Args...>& is);

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  const auto point {Eigen::Vector3d::UnitX()};
  const auto rotate_point {Eigen::AngleAxis{pi / 2, Eigen::Vector3d::UnitY()} * point};
  std::cout << rotate_point << '\n';
}

template<typename T, typename... Args>
T get_input(std::basic_istream<Args...>& is)
{
  T value;
  is >> value;
  return value;
}

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

  Eigen::Vector3d point {1, 2, 3};
  auto new_point {Eigen::Quaterniond::UnitRandom() * point};
  std::cout << new_point << '\n';
}

template<typename T, typename... Args>
T get_input(std::basic_istream<Args...>& is)
{
  T value;
  is >> value;
  return value;
}

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <numeric>
#include <random>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

template<typename T>
T get_value(std::istream& is)
{
  T v;
  is >> v;
  return v;
}

template<typename T>
T gcd_impl(T a, T b) {
  if (b == 0)
    return a;
  else
    return gcd_impl(b, a % b);
}

template<typename T>
T gcd(T a, T b)
{
  return a > b ? gcd_impl(a, b) : gcd_impl(b, a);
}

int main()
{
  using std::cin;
  using std::cout;

  const auto size{get_value<std::size_t>(cin)};
  auto ans{get_value<unsigned int>(cin)};
  for (auto i {size - 1}; i; --i) {
    ans = gcd(ans, get_value<unsigned int>(cin));
  }
  cout << ans << '\n';
  return 0;
}

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <locale>
#include <random>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

template<typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}


int main()
{
  using std::cin;
  using std::cout;
  using std::sort;
  using std::vector;
  using C = std::vector<int>;

  std::size_t length;
  cin >> length;

  C v(length);
  for (C::iterator it = v.begin(), end = v.end(); it != end; ++it) {
    cin >> *it;
  }

  sort(v.begin(), v.end());
  for (auto i : v)
    std::cout << i << ' ';
  std::cout << '\n';
  auto ans {v.front()};
  for (C::iterator it = v.begin(), end = v.end(); it != end; ++it) {
    ans = gcd(ans, *it);
  }
  cout << ans << '\n';
  return 0;
}

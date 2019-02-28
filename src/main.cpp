#include <iostream>

template<typename T>
inline T get_value(std::istream& is)
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
inline T gcd(T a, T b)
{
  return a > b ? gcd_impl(a, b) : gcd_impl(b, a);
}

int main()
{
  using std::cin;
  using std::cout;

  cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  const auto size{get_value<std::size_t>(cin)};
  auto ans{get_value<unsigned int>(cin)};
  for (auto i {size - 1}; i; --i) {
    ans = gcd(ans, get_value<unsigned int>(cin));
  }
  cout << ans << '\n';
  return 0;
}

#include <iostream>
#include <string>

template<typename T>
T get_value(std::istream& is);

int main()
{
  using std::cin;
  using std::cout;

  cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::cin >> std::boolalpha;
  auto ans{get_value<bool>(cin)};
  cout << ans << '\n';
}

template<typename T>
inline T get_value(std::istream& is)
{
  T v;
  is >> v;
  return v;
}

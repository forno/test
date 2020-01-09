#include <bits/stdc++.h>
using namespace std;
using namespace std::literals::string_literals;

template<typename T>
T get_value(std::istream& is);

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> cities(get_value<size_t>(cin));
  for (auto i {get_value<size_t>(cin)}; i != 0; --i) {
    const auto a {get_value<int>(cin)}, b {get_value<int>(cin)};
    ++cities[a-1];
    ++cities[b-1];
  }

  for (auto e : cities)
    cout << e << '\n';
  
  return 0;
}

template<typename T>
inline T get_value(std::istream& is)
{
  T v;
  is >> v;
  return v;
}

#include <bits/stdc++.h>
using namespace std;
using namespace std::literals::string_literals;

template<typename T>
T get_value(std::istream& is);

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);

  int A, B, C, X;
  cin >> A >> B >> C >> X;

  auto res {0u};
  for (auto a {0}; a < A; ++a) {
    const auto left {X - 500 * a};
    res += clamp(left / 100 + 1, 0, B + 1) - clamp((left - (C - 1) * 50) / 100, 0, B + 1);
  }

  cout << res << '\n';
  
  return 0;
}

template<typename T>
inline T get_value(std::istream& is)
{
  T v;
  is >> v;
  return v;
}

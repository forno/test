#include <bits/stdc++.h>
using namespace std;

template<typename T>
T get_value(std::istream& is);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int A, B, C, X;
  cin >> A >> B >> C >> X;

  auto res {0};
  for (auto a {0}; a < A; ++a) {
    auto left {X - a * 500};
    res += max(0, min(B + 1, left / 100 + 1))
             - max(0, min(B + 1, (left - (C - 1) * 50) / 100));
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

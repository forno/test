#include <bits/stdc++.h>
using namespace std;

long long cal(const vector<long long>& v, size_t index)
{
  if (index == 0)
    return v[0];
  return cal(v, index - 1) + accumulate(v.begin(), next(v.begin(), index + 1), 0ll);
}

template<typename T>
T get_value(std::istream& is);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  cin >> N;
  vector<long long> C(N);
  for (auto& e : C)
    cin >> e;

  auto res {0ll};
  for (auto i {0ll}; i < N; ++i) {
    for (auto j {0ll}; j < (i + 1); ++j) {
      const auto cost {cal(C, j)};
      res += cost;
      cout << cost << '\n';
    }
  }

  cout << (res * 2) % static_cast<long long>(1e9+7) << '\n';

  return 0;
}

template<typename T>
inline T get_value(std::istream& is)
{
  T v;
  is >> v;
  return v;
}

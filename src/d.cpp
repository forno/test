#include <bits/stdc++.h>
using namespace std;

template<typename T>
T get_value(std::istream& is);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  const auto st {chrono::system_clock::now()};
  const auto tl {chrono::milliseconds{1950}};

  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (auto& e : A)
    cin >> e;
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());

  auto res {0u};
  for (auto i {1}; i <= M; ++i) {
    auto is_miss {false};
    for (const auto& e : A) {
      const auto p {static_cast<float>(i)/e - 0.5f};
      if (p < 0 || p != floor(p)) {
        is_miss = true;
        break;
      }
    }
    if (!is_miss)
      ++res;
    if (chrono::system_clock::now() - st > tl) // timeover
      break;
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

#include <bits/stdc++.h>
using namespace std;

long long cal(const vector<long long>& v, size_t index)
{
}

template<typename T>
T get_value(std::istream& is);

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int N;
  cin >> N;
  valarray<long long> C(N);
  for (auto& e : C)
    cin >> e;

  cout << res % static_cast<long long>(1e9+7) << '\n';

  return 0;
}

template<typename T>
inline T get_value(std::istream& is)
{
  T v;
  is >> v;
  return v;
}

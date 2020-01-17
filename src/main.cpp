#include <bits/stdc++.h>
using namespace std;
using namespace std::literals::string_literals;
using ll = long long;

#define repi(i, s, n) for (ll i {s}; i##_len{n}; i < i##_len; ++i)
#define rep(i, n) repi(i, 0, n)
#define all(x) (x).begin(), (x).end()

namespace forno
{
template<typename T>
T get_value(std::istream& is);
template<typename C>
ll llsize(const C& c);
template<typename C, size_t N>
ll llsize(const C(&)[N]);
}
using namespace forno;

void task();
void task()
{
}

int main()
{
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  task();
  return 0;
}

namespace forno
{

template<typename T>
inline T get_value(std::istream& is)
{
  T v;
  is >> v;
  return v;
}

template<typename C>
ll llsize(const C& c)
{
  return static_cast<ll>(c.size());
}

template<typename C, size_t N>
ll llsize(const C(&)[N])
{
  return static_cast<ll>(N);
}

}

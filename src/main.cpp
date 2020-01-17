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
template<typename T>
T input();
template<typename C>
void cfill(C& c);
template<typename C>
void inputfill(C& c);
template<typename C>
ll llsize(const C& c);
template<typename C, size_t N>
ll llsize(const C(&)[N]);

ll llgcd(ll a, ll b);
ll lllcm(ll a, ll b);
ll lllog2p1(ll x);
}
using namespace forno;

// implementation begin

void task();
void task()
{
  vector<ll> v(get_value<size_t>(cin));
  const auto limitation {input<ll>()};
  inputfill(v);
  for (auto& e: v) {
    if (e % 2) {
      cout << "0\n";
      return;
    }
    e >>= 1; // divide 2
  }
  const auto t {lllog2p1(v[0])};
  for (auto& e: v) {
    if (t != lllog2p1(e)) {
      cout << "0\n";
      return;
    }
    e >>= t; // e /= 2^t
  }
  const auto m {limitation >> t};

  ll l {1};
  for (auto e: v) {
    l = lcm(l, e);
    if (l > m) {
      cout << "0\n";
      return;
    }
  }

  cout << m << ' ' << (m/l + 1) / 2 << '\n';
  return;
}

// implementation end

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

template<typename T>
T input()
{
  return get_value<T>(cin);
}

template<typename C>
void cfill(C& c, std::istream& is)
{
  for (auto& e: c)
    is >> e;
}

template<typename C>
void inputfill(C& c)
{
  cfill(c, cin);
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

ll llgcd(ll a, ll b)
{
  return b ? gcd(b, a%b) : a;
}

ll lllcm(ll a, ll b)
{
  return a / gcd(a, b) * b;
}

ll lllog2p1(ll x)
{
  ll res {0};
  for (;!(x % 2); ++res)
    x >>= 1;
  return res + 1;
}

}

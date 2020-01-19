#include <bits/stdc++.h>
using namespace std;
using namespace std::literals::chrono_literals;
using namespace std::literals::string_literals;
using ll = long long;

#define repi(i, s, n) for (ll i {s}; i##_len{n}; i < i##_len; ++i)
#define rep(i, n) repi(i, 0, n)
#define each(e, c) for (auto& e: c)
#define all(x) (x).begin(), (x).end()

namespace forno
{
template<typename T>
T get_value(std::istream& is);
template<typename T>
T input();
template<typename C>
void container_fill(C& c, std::istream& is);
template<typename C>
void inputfill(C& c);
template<typename C>
ll llsize(const C& c);
template<typename C, size_t N>
ll llsize(const C(&)[N]);

ll llgcd(ll a, ll b);
ll lllcm(ll a, ll b);
ll lllog2(ll x);
}
using namespace forno;

int main()
{
  return 0;
}

class initalization
{
  class custom_numpunct: public std::numpunct<char>
  {
  public:
    using numpunct::numpunct;
  protected:
    std::string do_truename() const override { return "Yes"; }
    std::string do_falsename() const override { return "No"; }
  };

public:
  initalization()
  {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::boolalpha;
    std::cout.imbue(std::locale(std::cout.getloc(), new custom_numpunct{}));
  }
} initalize;

namespace forno
{

template<typename T>
T get_value(std::istream& is)
{
  T v;
  is >> v;
  return v;
}

template<typename T>
T input()
{
  return get_value<T>(std::cin);
}

template<typename C>
void container_fill(C& c, std::istream& is)
{
  for (auto& e: c)
    is >> e;
}

template<typename C>
void inputfill(C& c)
{
  container_fill(c, std::cin);
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
  return b ? llgcd(b, a%b) : a;
}

ll lllcm(ll a, ll b)
{
  return a / llgcd(a, b) * b;
}

ll lllog2(ll x)
{
  ll res {0};
  for (;!(x % 2); ++res)
    x >>= 1;
  return res;
}

}

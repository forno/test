#include <bits/stdc++.h>
using namespace std;
using namespace std::literals::chrono_literals;
using namespace std::literals::string_literals;
using ll = long long;

#define repi(i, s, n) for (ll i {s}, i##_len{n}; i < i##_len; ++i)
#define rep(i, n) repi(i, 0, n)
#define all(x) std::begin(x), std::end(x)

namespace forno
{
template<typename T>
T get_value(std::istream& is = std::cin);
template<typename C>
C get_container(std::istream& is = std::cin, typename C::size_type length = std::numeric_limits<typename C::size_type>::max());
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
  const auto n {get_value<ll>()};
  const auto m {get_value<ll>()};
  std::vector<bool> ans(n);
  auto w {0u};
  for (auto i {m}; i != 0; --i) {
    const auto index {get_value<int>() - 1};
    const auto score {get_value<string>()};
    if (ans[index])
      break;
    if (score == "WA") {
      ++w;
    } else {
      ans[index] = true;
    }
  }
  auto sum {0u};
  for (auto e : ans)
    sum += e;
  cout << sum << ' ' << w << '\n';

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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.imbue(std::locale(std::cout.getloc(), new custom_numpunct{}));
    std::cout << std::boolalpha << std::fixed << std::setprecision(15);
  }
} initalize;

namespace forno
{

template<typename T>
T get_value(std::istream& is)
{
  T v {};
  is >> v;
  return v;
}

template<typename C>
C get_container(std::istream& is, typename C::size_type length)
{
  C v {};
  if (length != std::numeric_limits<typename C::size_type>::max())
    v.reserve(length);
  typename C::value_type e {};
  for (auto i {length}; i != 0 && is >> e; --i)
    v.push_back(std::move_if_noexcept(e));
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

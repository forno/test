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
template<typename T, typename... Args>
T get_value(std::basic_istream<Args...>& is = std::cin);
template<typename C, typename... Args>
C get_container(std::basic_istream<Args...>& is = std::cin, typename C::size_type length = std::numeric_limits<typename C::size_type>::max());
template<typename C>
ll llsize(const C& c);
template<typename C, size_t N>
ll llsize(const C(&)[N]);

ll llgcd(ll a, ll b);
ll lllcm(ll a, ll b);
ll lllog2(ll x);
}
using namespace forno;

template<typename T>
class myvec : public std::vector<T>
{
public:
  void push_back(const T& x)
  {
    cout << "myvec push_back\n";
    vector<T>::push_back(x);
  }

  void push_back(T&& x)
  {
    cout << "myvec push_back with move\n";
    vector<T>::push_back(std::move(x));
  }

  vector<T>::iterator insert(vector<T>::const_iterator it, const T& x)
  {
    cout << "myvec insert\n";
    return vector<T>::insert(it, x);
  }

  vector<T>::iterator insert(vector<T>::const_iterator it, T&& x)
  {
    cout << "myvec insert with move\n";
    return vector<T>::insert(it, std::move(x));
  }
};

int main()
{
  istringstream iss {"1 1 1 1 1 1 1 1 1 1 1 1 1 1 1"s};
  get_container<vector<int>>(cin, 5);
  get_container<myvec<int>>(cin, 5);
  get_container<unordered_set<int>>(cin, 5);
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
    std::cout << std::boolalpha;
    std::cout.imbue(std::locale(std::cout.getloc(), new custom_numpunct{}));
  }
} initalize;

namespace forno
{

template<typename T, typename... Args>
T get_value(std::basic_istream<Args...>& is)
{
  T v {};
  is >> v;
  return v;
}

namespace detail
{

template<typename T>
auto has_push_back_impl(nullptr_t) -> decltype(
  std::declval<T>().push_back(std::declval<typename T::value_type>()),
  std::true_type{});

template<typename T>
auto has_push_back_impl(...) -> std::false_type;

template<typename T>
struct has_push_back
  : decltype(has_push_back_impl<T>(nullptr))
{};

}

template<typename C, typename... Args>
C get_container(std::basic_istream<Args...>& is, typename C::size_type length)
{
  C v {};
  if (length != std::numeric_limits<typename C::size_type>::max())
    v.reserve(length);
  typename C::value_type e {};
  for (auto i {length}; i != 0 && is >> e; --i) {
    if constexpr (detail::has_push_back<C>{}) {
      v.push_back(std::move_if_noexcept(e));
    } else {
      using std::cend;
      v.insert(cend(v), std::move_if_noexcept(e));
    }
  }
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

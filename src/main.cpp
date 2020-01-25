#include <bits/stdc++.h>
using namespace std;
using namespace std::literals::chrono_literals;
using namespace std::literals::string_literals;
using ll = long long;

#define repi(i, s, n) for (long long i {s}, i##_len{n}; i < i##_len; ++i)
#define rep(i, n) repi(i, 0, n)
#define all(x) std::begin(x), std::end(x)

namespace xmaho
{
inline namespace input
{
template<typename T>
T get_value(std::istream& is = std::cin);
template<typename C>
C get_container(std::istream& is = std::cin, typename C::size_type length = std::numeric_limits<typename C::size_type>::max());
}
}
namespace xmaho
{
inline namespace integer
{
template<typename C>
constexpr auto ssize(const C& c) noexcept(noexcept(c.size()))
  -> typename std::common_type<std::ptrdiff_t, typename std::make_signed<decltype(c.size())>::type>::type;
template <class T, ptrdiff_t N>
constexpr std::ptrdiff_t ssize(const T (&)[N]) noexcept;
}
}
namespace xmaho
{
namespace math // no inline for c++17 or newer env
{
template<std::size_t modulo, typename T = long long>
class residue_system
{
  static_assert(modulo > 0, "Modulo must be over 0");
  static_assert(std::is_nothrow_default_constructible<T>::value, "T must can be make noexcept construct");
  static_assert(std::is_nothrow_move_constructible<T>::value ||
                std::is_nothrow_copy_constructible<T>::value, "T must can be maked by T");
  static_assert(noexcept(T{} + T{}), "T must can be noexcept addition by T");
  static_assert(noexcept(std::declval<T&>() -= T{}), "T must can be noexcept assign with subtraction by T");
  static_assert(noexcept(T{} % T{}), "T must can be noexcept dividion by T");
  static_assert(noexcept(T{} < T{}), "T must can be compared with T");
  static_assert(noexcept(static_cast<T>(std::size_t{})), "T must can be noexcept convation by std::size_t");
public:
  using value_type = T;
  static constexpr auto modulo_value {static_cast<T>(modulo)};
  constexpr residue_system() noexcept = default;
  constexpr residue_system(const T& value) noexcept;
  explicit constexpr operator T() const
    noexcept(std::is_nothrow_copy_constructible<T>::value);
  constexpr residue_system& operator+() const noexcept;
  constexpr residue_system operator-() const noexcept(noexcept(-T{}));
  constexpr residue_system& operator+=(const residue_system& rhs) &
    noexcept(noexcept(std::declval<T&>() += T{}));
  constexpr residue_system& operator-=(const residue_system& rhs) &
    noexcept(noexcept(std::declval<T&>() += T{}) && noexcept(T{} - T{}));
  constexpr residue_system& operator*=(const residue_system& rhs) &
    noexcept(noexcept(std::declval<T&>() *= T{}));
  constexpr residue_system& operator/=(const residue_system& rhs) &
    noexcept(noexcept(std::declval<T&>() /= T{}));
  constexpr residue_system& operator%=(const T& rhs) & // no limited rhs
    noexcept(noexcept(std::declval<T&>() %= T{}));
  constexpr residue_system& operator<<=(const T& rhs) & // no limited rhs
    noexcept(noexcept(std::declval<T&>() <<= T{}));
  constexpr residue_system& operator>>=(const T& rhs) & // no limited rhs
    noexcept(noexcept(std::declval<T&>() >>= T{}));
  constexpr residue_system operator+(const residue_system& rhs) const
    noexcept(noexcept(operator+=(rhs)));
  constexpr residue_system operator-(const residue_system& rhs) const
    noexcept(noexcept(operator-=(rhs)));
  constexpr residue_system operator*(const residue_system& rhs) const
    noexcept(noexcept(operator*=(rhs)));
  constexpr residue_system operator/(const residue_system& rhs) const
    noexcept(noexcept(operator/=(rhs)));
  constexpr residue_system operator%(const T& rhs) const // no limited rhs
    noexcept(noexcept(operator%=(rhs)));
  constexpr residue_system operator<<(const T& rhs) const // no limited rhs
    noexcept(noexcept(operator<<=(rhs)));
  constexpr residue_system operator>>(const T& rhs) const // no limited rhs
    noexcept(noexcept(operator>>=(rhs)));
  constexpr void swap(residue_system& other) noexcept;
private:
  T value_ {};
};
template<std::size_t modulo, typename T>
constexpr void swap(residue_system<modulo, T>& a, residue_system<modulo, T>& b) noexcept;
template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T> pow(residue_system<modulo, T> a, const T& b); // no limited lhs // TODO: can it noexcept?
template<std::size_t modulo, typename T>
constexpr residue_system<modulo, T> operator%(const T& lhs, const residue_system<modulo, T>& rhs) // no limited lhs
  noexcept(std::is_nothrow_constructible<residue_system<modulo, T>, T>::value);
template<std::size_t modulo, typename T>
constexpr residue_system<modulo, T> operator<<(const T& lhs, const residue_system<modulo, T>& rhs) // no limited lhs
  noexcept(noexcept(std::declval<T&>() << T{}));
template<std::size_t modulo, typename T>
constexpr residue_system<modulo, T> operator>>(const T& lhs, const residue_system<modulo, T>& rhs) // no limited lhs
  noexcept(noexcept(std::declval<T&>() >> T{}));
template<std::size_t modulo, typename T, typename... Args>
constexpr std::basic_ostream<Args...>& operator<<(std::basic_ostream<Args...>& os, const residue_system<modulo, T>& rhs)
  noexcept(noexcept(static_cast<T>(rhs)));
template<std::size_t modulo, typename T, typename... Args>
constexpr std::basic_istream<Args...>& operator>>(std::basic_istream<Args...>& is, const residue_system<modulo, T>& rhs)
  noexcept(noexcept(rhs = T{}));
}
}
using namespace xmaho;

int main()
{
  const auto n {get_value<ll>()};
  auto a {get_container<vector<ll>>(cin, n)};
  sort(a.begin(), a.end());

  using rs = math::residue_system<static_cast<std::size_t>(1e9+7)>;
  rs res {0};
  rep(i, n) {
    const auto r {n - 1 - i};
    rs now {r};
    if (r != 0)
      now <<= r - 1;
    now += 1ll << r;
    now <<= i;
    now *= a[i];
    res += std::move(now);
  }
  res <<= n;
  cout << res << '\n';
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

template<typename T>
T xmaho::input::get_value(std::istream& is)
{ T v {}; is >> v; return v; }

template<typename C>
C xmaho::input::get_container(std::istream& is, typename C::size_type length)
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
constexpr auto xmaho::integer::ssize(const C& c) noexcept(noexcept(c.size()))
  -> typename std::common_type<std::ptrdiff_t, typename std::make_signed<decltype(c.size())>::type>::type
{ return c.size(); }

template <class T, ptrdiff_t N>
constexpr std::ptrdiff_t xmaho::integer::ssize(const T (&)[N]) noexcept
{ return N; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>::residue_system(const T& value) noexcept
  : value_ {(value % modulo_value + modulo_value) % modulo_value} {}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>::operator T() const
  noexcept(std::is_nothrow_copy_constructible<T>::value)
{ return value_; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator+() const noexcept
{ return *this; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator-() const noexcept(noexcept(-T{}))
{ return {-value_}; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator+=(const residue_system& rhs) &
  noexcept(noexcept(std::declval<T&>() += T{}))
{ if (modulo_value < (value_ += rhs.value_)) value_ -= modulo_value; return *this; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator-=(const residue_system& rhs) &
  noexcept(noexcept(std::declval<T&>() += T{}) && noexcept(T{} - T{}))
{ if (modulo_value < (value_ += modulo_value - rhs.value_)) value_ -= modulo_value; return *this; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator*=(const residue_system& rhs) &
  noexcept(noexcept(std::declval<T&>() *= T{}))
{ if (modulo_value < (value_ *= rhs.value_)) value_ %= modulo_value; return *this; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator/=(const residue_system& rhs) &
  noexcept(noexcept(std::declval<T&>() /= T{}))
{ if (modulo_value < (value_ /= rhs.value_)) value_ %= modulo_value; return *this; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator%=(const T& rhs) & // no limited rhs
  noexcept(noexcept(std::declval<T&>() %= T{}))
{ value_ %= rhs; return *this; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator<<=(const T& rhs) & // no limited rhs
  noexcept(noexcept(std::declval<T&>() <<= T{}))
{ operator*=({1ll << rhs}); return *this; } // TODO: check correct

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator>>=(const T& rhs) & // no limited rhs
  noexcept(noexcept(std::declval<T&>() >>= T{}))
{ value_ >>= rhs; return *this; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator+(const residue_system& rhs) const
  noexcept(noexcept(operator+=(rhs)))
{ residue_system res {*this}; res += rhs; return res;}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator-(const residue_system& rhs) const
  noexcept(noexcept(operator-=(rhs)))
{ residue_system res {*this}; res -= rhs; return res;}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator*(const residue_system& rhs) const
  noexcept(noexcept(operator*=(rhs)))
{ residue_system res {*this}; res *= rhs; return res;}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator/(const residue_system& rhs) const
  noexcept(noexcept(operator/=(rhs)))
{ residue_system res {*this}; res /= rhs; return res;}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator%(const T& rhs) const // no limited rhs
  noexcept(noexcept(operator%=(rhs)))
{ residue_system res {*this}; res %= rhs; return res;}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator<<(const T& rhs) const // no limited rhs
  noexcept(noexcept(operator<<=(rhs)))
{ residue_system res {*this}; res <<= rhs; return res;}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator>>(const T& rhs) const // no limited rhs
  noexcept(noexcept(operator>>=(rhs)))
{ residue_system res {*this}; res >>= rhs; return res;}

template<std::size_t modulo, typename T>
constexpr void xmaho::math::residue_system<modulo, T>::swap(residue_system& other) noexcept
{ std::swap(value_, other.value_); }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::pow(residue_system<modulo, T> a, const T& b)
{
  if (b == 0)
    return {1};
  a *= a;
  if (b % 2)
    a += a;
  return a;
}

template<std::size_t modulo, typename T>
constexpr void xmaho::math::swap(residue_system<modulo, T>& lhs, residue_system<modulo, T>& rhs) noexcept
{ lhs.swap(rhs); }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::operator%(const T& lhs, const residue_system<modulo, T>& rhs) // no limited lhs
  noexcept(std::is_nothrow_constructible<residue_system<modulo, T>, T>::value)
{ return {lhs % static_cast<T>(rhs)}; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::operator<<(const T& lhs, const residue_system<modulo, T>& rhs) // no limited lhs
  noexcept(noexcept(std::declval<T&>() << T{}))
{ throw std::exception("xmaho::math::operator<<(const T& lhs, const residue_system<modulo, T>& rhs): No implementation now"); }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::operator>>(const T& lhs, const residue_system<modulo, T>& rhs) // no limited lhs
  noexcept(noexcept(std::declval<T&>() >> T{}))
{ return {lhs >> static_cast<T>(rhs)}; }

template<std::size_t modulo, typename T, typename... Args>
constexpr std::basic_ostream<Args...>&
xmaho::math::operator<<(std::basic_ostream<Args...>& os, const residue_system<modulo, T>& rhs)
  noexcept(noexcept(static_cast<T>(rhs)))
{ os << static_cast<T>(rhs); return os; }

template<std::size_t modulo, typename T, typename... Args>
constexpr std::basic_istream<Args...>&
xmaho::math::operator>>(std::basic_istream<Args...>& is, const residue_system<modulo, T>& rhs)
  noexcept(noexcept(rhs = T{}))
{ T v; is >> v; rhs = std::move(v); return is; }

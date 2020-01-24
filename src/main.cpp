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
template<typename T1, typename T2>
constexpr typename std::common_type<T1, T2>::type gcd(const T1& a, const T2& b) noexcept;
template<typename T1, typename T2>
constexpr typename std::common_type<T1, T2>::type lcm(const T1& a, const T2& b) noexcept;
}
}
namespace xmaho
{
namespace math
{
template<std::size_t modulo, typename T = long long>
class residue_system
{
  static_assert(modulo > 0, "Modulo must be over 0");
  static_assert(std::is_nothrow_default_constructible<T>::value, "T must can be make noexcept construct");
  static_assert(std::is_nothrow_move_constructible<T>::value ||
                std::is_nothrow_copy_constructible<T>::value, "T must can be maked by T");
  static_assert(noexcept(T{} + T{}), "T must that can be noexcept addition by T");
  static_assert(noexcept(T{} % T{}), "T must that can be noexcept dividion by T");
public:
  using value_type = T;
  constexpr residue_system() noexcept = default;
  constexpr residue_system(const T& value) noexcept;
  constexpr operator T() const
    noexcept(std::is_nothrow_copy_constructible<T>::value);
  constexpr residue_system& operator+() const noexcept;
  constexpr residue_system operator-() const noexcept(noexcept(-T{}));
  constexpr residue_system& operator+=(const residue_system& rhs) &
    noexcept(noexcept(T{} + T{}));
  constexpr residue_system& operator-=(const residue_system& rhs) &
    noexcept(noexcept(T{} - T{}));
  constexpr residue_system& operator*=(const residue_system& rhs) &
    noexcept(noexcept(T{} * T{}));
  constexpr residue_system& operator/=(const residue_system& rhs) &
    noexcept(noexcept(T{} / T{}));
  constexpr residue_system operator+(const residue_system& rhs) const
    noexcept(noexcept(T{} + T{}));
  constexpr residue_system operator-(const residue_system& rhs) const
    noexcept(noexcept(T{} - T{}));
  constexpr residue_system operator*(const residue_system& rhs) const
    noexcept(noexcept(T{} * T{}));
  constexpr residue_system operator/(const residue_system& rhs) const
    noexcept(noexcept(T{} / T{}));
  constexpr residue_system operator%(const residue_system& rhs) const
    noexcept(noexcept(T{} % T{}));
  constexpr void swap(residue_system& other) noexcept;
private:
  T value_ {};
};
template<std::size_t modulo, typename T>
constexpr void swap(residue_system<modulo, T>& a, residue_system<modulo, T>& b) noexcept;
template<std::size_t modulo, typename T>
constexpr residue_system<modulo, T> operator%(const T& lhs, const residue_system<modulo, T>& rhs)
  noexcept(noexcept(T{} % T{}));
}
}
using namespace xmaho;

int main()
{
  auto n {get_value<size_t>()};
  valarray<long long> a(n);
  long long l {1};
  for (auto& e : a) {
    long long input;
    cin >> input;
    e = input;
    l = math::lcm(input, l);
  }
  
  valarray<math::residue_system<static_cast<size_t>(1e9+7)>> res(n);
  a = l / a;
  copy(begin(a), end(a), begin(res));
  cout << static_cast<long long>(res.sum()) << '\n';

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
namespace xmaho
{
namespace math
{
namespace detail
{
template<typename T1, typename T2>
constexpr typename std::common_type<T1, T2>::type gcd_impl(const T1& a, const T2& b) noexcept
{ return b ? gcd_impl(b, a%b) : a; }
}
}
}
template<typename T1, typename T2>
constexpr typename std::common_type<T1, T2>::type xmaho::math::gcd(const T1& a, const T2& b) noexcept
{ return a ? detail::gcd_impl(b, a%b) : a; }
template<typename T1, typename T2>
constexpr typename std::common_type<T1, T2>::type xmaho::math::lcm(const T1& a, const T2& b) noexcept
{ return a / gcd(a, b) * b; }
namespace xmaho
{
namespace math
{
namespace detail
{
template<typename T>
constexpr T residue(const T& value, std::size_t modulo) noexcept
{
  static_assert(noexcept(value % value) && noexcept(value + value),
                "xmaho::math::residue_system: Interface error: noexcept through out");
  return (value % static_cast<T>(modulo) + static_cast<T>(modulo)) % static_cast<T>(modulo);
}
}
}
}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>::residue_system(const T& value) noexcept
  : value_ {detail::residue(value, modulo)} {}

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
  noexcept(noexcept(T{} + T{}))
{ value_ = detail::residue(value_ + rhs.value_, modulo); return *this; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator-=(const residue_system& rhs) &
  noexcept(noexcept(T{} - T{}))
{ value_ = detail::residue(value_ - rhs.value_, modulo); return *this; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator*=(const residue_system& rhs) &
  noexcept(noexcept(T{} * T{}))
{ value_ = detail::residue(value_ * rhs.value_, modulo); return *this; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator/=(const residue_system& rhs) &
  noexcept(noexcept(T{} / T{}))
{ value_ = detail::residue(value_ / rhs.value_, modulo); return *this; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator+(const residue_system& rhs) const
  noexcept(noexcept(T{} + T{}))
{ return {value_ + rhs.value_}; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator-(const residue_system& rhs) const
  noexcept(noexcept(T{} - T{}))
{ return {value_ - rhs.value_}; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator*(const residue_system& rhs) const
  noexcept(noexcept(T{} * T{}))
{ return {value_ * rhs.value_}; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator/(const residue_system& rhs) const
  noexcept(noexcept(T{} / T{}))
{ return {value_ / rhs.value_}; }
template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator%(const residue_system& rhs) const
  noexcept(noexcept(T{} % T{}))
{ return {value_ % rhs.value_}; }

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T> xmaho::math::operator%(const T& lhs, const residue_system<modulo, T>& rhs)
  noexcept(noexcept(T{} % T{}))
{ return {lhs % static_cast<T>(rhs)}; }

template<std::size_t modulo, typename T>
constexpr void xmaho::math::residue_system<modulo, T>::swap(residue_system& other) noexcept
{ std::swap(value_, other.value_); }

template<std::size_t modulo, typename T>
constexpr void xmaho::math::swap(residue_system<modulo, T>& lhs, residue_system<modulo, T>& rhs) noexcept
{ lhs.swap(rhs); }

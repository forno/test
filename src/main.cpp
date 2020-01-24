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
}
using namespace forno;

namespace xmaho
{
inline namespace math
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

  constexpr residue_system() = default;

  constexpr residue_system(const T& value) noexcept;

  explicit constexpr operator T() const
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

  void swap(residue_system& other) noexcept;

private:
  T value_ {};
};

template<std::size_t modulo, typename T>
void swap(residue_system<modulo, T>& a, residue_system<modulo, T>& b) noexcept;

}
}
using namespace xmaho;

int main()
{
  residue_system<static_cast<std::size_t>(1e9+7), long long> a{0};
  a += 5;
  a *= 5;
  cout << static_cast<long long>(a) << '\n';
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

}

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
  : value_ {detail::residue(value, modulo)}
{
}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>::operator T() const
  noexcept(std::is_nothrow_copy_constructible<T>::value)
{
  return value_;
}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator+() const noexcept
{
  return *this;
}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator-() const noexcept(noexcept(-T{}))
{
  return {-value_};
}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator+=(const residue_system& rhs) &
  noexcept(noexcept(T{} + T{}))
{
  value_ = detail::residue(value_ + rhs.value_, modulo);
  return *this;
}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator-=(const residue_system& rhs) &
  noexcept(noexcept(T{} - T{}))
{
  value_ = detail::residue(value_ - rhs.value_, modulo);
  return *this;
}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator*=(const residue_system& rhs) &
  noexcept(noexcept(T{} * T{}))
{
  value_ = detail::residue(value_ * rhs.value_, modulo);
  return *this;
}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>&
xmaho::math::residue_system<modulo, T>::operator/=(const residue_system& rhs) &
  noexcept(noexcept(T{} / T{}))
{
  value_ = detail::residue(value_ / rhs.value_, modulo);
  return *this;
}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator+(const residue_system& rhs) const
  noexcept(noexcept(T{} + T{}))
{
  return {value_ + rhs.value_};
}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator-(const residue_system& rhs) const
  noexcept(noexcept(T{} - T{}))
{
  return {value_ - rhs.value_};
}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator*(const residue_system& rhs) const
  noexcept(noexcept(T{} * T{}))
{
  return {value_ * rhs.value_};
}

template<std::size_t modulo, typename T>
constexpr xmaho::math::residue_system<modulo, T>
xmaho::math::residue_system<modulo, T>::operator/(const residue_system& rhs) const
  noexcept(noexcept(T{} / T{}))
{
  return {value_ / rhs.value_};
}

template<std::size_t modulo, typename T>
void xmaho::math::residue_system<modulo, T>::swap(residue_system& other) noexcept
{
  std::swap(value_, other.value_);
}

template<std::size_t modulo, typename T>
void xmaho::math::swap(residue_system<modulo, T>& lhs, residue_system<modulo, T>& rhs) noexcept
{
  lhs.swap(rhs);
}

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

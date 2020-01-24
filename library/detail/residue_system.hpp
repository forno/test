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

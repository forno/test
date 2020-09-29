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

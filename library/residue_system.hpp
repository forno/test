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

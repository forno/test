#ifndef XMAHO_XMAHO_MATH_RESIDUE_SYSTEM_H
#define XMAHO_XMAHO_MATH_RESIDUE_SYSTEM_H

/**
 * @file math/residue_system.hpp
 * @brief This have definition of xmaho::math::residue_system class.
 */
namespace xmaho
{
namespace math
{

/**
 * @brief the roop number under Modulo
 *
 * The least residue system modulo "Modulo".
 */
template<size_t Modulo, typename ValueType = size_t>
class residue_system
{
public:
  template<typename T>
  static constexpr ValueType limit(const T& value)
  {
    return value % Modulo;
  }

  explicit constexpr residue_system() noexcept = default;
  explicit constexpr residue_system(const ValueType& value) noexcept
    : value_ {limit(value)}
  {
  }

  constexpr operator ValueType() const noexcept
  {
    return value_;
  }

  residue_system& operator++() noexcept
  {
    ++value_;
    value_ %= Modulo;
    return *this;
  }

  residue_system& operator--() noexcept
  {
    if (value_ == 0)
      value_ = Modulo;
    else
      --value_;
    return *this;
  }

  template<typename T>
  constexpr const residue_system operator+(const T& rhs) const noexcept
  {
    return residue_system{value_ + rhs};
  }

  template<typename T>
  constexpr const residue_system operator-(const T& rhs) const noexcept
  {
    value_ < rhs ?
      throw std::invalid_argument{"Now cannot operate on LHS < RHS"} :
      return residue_system{value_ - rhs};
  }

private:
  ValueType value_;
};

}
}

#endif

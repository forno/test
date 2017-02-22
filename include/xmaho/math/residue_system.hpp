#ifndef XMAHO_XMAHO_MATH_RESIDUE_SYSTEM_H
#define XMAHO_XMAHO_MATH_RESIDUE_SYSTEM_H

#include <cstddef>
#include <stdexcept>

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
template<std::size_t Modulo, typename ValueType = std::size_t>
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

  constexpr const residue_system operator+(const residue_system& rhs) const noexcept
  {
    return residue_system{value_ + rhs.value_};
  }

  constexpr const residue_system operator-(const residue_system& rhs) const noexcept
  {
    return value_ < rhs.value_ ?
      throw std::invalid_argument{"Now cannot operate on LHS < RHS"} :
      residue_system{value_ - rhs.value_};
  }

private:
  ValueType value_;
};

}
}

#endif

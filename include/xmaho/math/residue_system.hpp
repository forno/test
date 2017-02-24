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
  static_assert(Modulo > 0, "Error: Modulo is negative number. It must be positive number");
  ValueType value_;

public:
  constexpr residue_system() noexcept = default;
  explicit constexpr residue_system(const ValueType& value) noexcept
    : value_ {value % Modulo}
  {
  }

  constexpr residue_system(const residue_system&) noexcept = default;
  constexpr residue_system(residue_system&&) noexcept = default;
  residue_system& operator=(const residue_system&) noexcept = default;
  residue_system& operator=(residue_system&&) noexcept = default;

  bool operator==(const residue_system& rhs) const noexcept
  {
    return value_ == rhs.value_;
  }

  residue_system& operator++() noexcept
  {
    ++value_;
    value_ %= Modulo;
    return *this;
  }

  residue_system& operator--() noexcept
  {
    if (value_ <= 0)
      value_ = Modulo - 1;
    else
      --value_;
    return *this;
  }

  residue_system operator++(int) noexcept
  {
    residue_system tmp{*this};
    ++*this;
    return tmp;
  }

  residue_system& operator--(int) noexcept
  {
    residue_system tmp{*this};
    ++*this;
    return tmp;
  }

  constexpr const residue_system operator+(const residue_system& rhs) const noexcept
  {
    return residue_system{value_ + rhs.value_};
  }

  constexpr const residue_system operator-(const residue_system& rhs) const
  {
    return residue_system{value_ + Modulo - rhs.value_};
  }
};

}
}

#endif

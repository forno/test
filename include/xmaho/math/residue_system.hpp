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
template<typename ValueType, ValueType Modulo>
class basic_residue_system
{
  static_assert(Modulo > 0, "Error: Modulo is negative number. It must be positive number");
  ValueType value_;

public:
  constexpr basic_residue_system() noexcept = default;
  explicit constexpr basic_residue_system(const ValueType& value) noexcept
    : value_ {value % Modulo}
  {
  }

  constexpr basic_residue_system(const basic_residue_system&) noexcept = default;
  constexpr basic_residue_system(basic_residue_system&&) noexcept = default;
  constexpr basic_residue_system& operator=(const basic_residue_system&) noexcept = default;
  constexpr basic_residue_system& operator=(basic_residue_system&&) noexcept = default;
  ~basic_residue_system() noexcept = default;

  constexpr bool operator==(const basic_residue_system& rhs) const noexcept
  {
    return value_ == rhs.value_;
  }

  constexpr basic_residue_system& operator++() noexcept
  {
    ++value_;
    value_ %= Modulo;
    return *this;
  }

  constexpr basic_residue_system& operator--() noexcept
  {
    if (value_ <= 0)
      value_ = Modulo - 1;
    else
      --value_;
    return *this;
  }

  constexpr basic_residue_system operator++(int) noexcept
  {
    basic_residue_system tmp{*this};
    ++*this;
    return tmp;
  }

  constexpr basic_residue_system& operator--(int) noexcept
  {
    basic_residue_system tmp{*this};
    ++*this;
    return tmp;
  }

  constexpr const basic_residue_system operator+(const basic_residue_system& rhs) const noexcept
  {
    return basic_residue_system{value_ + rhs.value_};
  }

  constexpr const basic_residue_system operator-(const basic_residue_system& rhs) const noexcept
  {
    return basic_residue_system{value_ + Modulo - rhs.value_};
  }
};

template<std::size_t Modulo>
using residue_system = basic_residue_system<std::size_t, Modulo>;

}
}

#endif

#ifndef XMAHO_XMAHO_MATH_RESIDUE_SYSTEM_H
#define XMAHO_XMAHO_MATH_RESIDUE_SYSTEM_H

#include <cstddef>

/**
 * @file math/residue_system.hpp
 * @brief This have definition of xmaho::math::residue_system class.
 */

namespace xmaho
{
namespace math
{

/**
 * @brief The roop number under a modulo.
 *
 * This class doing under the least residue system.
 * The modulo must be a positive number,
 * it mean that equivalent value are positive number.
 *
 * @tparam ValueType The equivalent type. it must be constexpr.
 * @tparam Modulo    The modulo of residue system.
 */
template<typename ValueType, ValueType Modulo>
class basic_residue_system
{
  static_assert(Modulo > 0, "Error: Modulo is negative number. It must be positive number");

public:

  /**
   * @brief The alias of equivalent type.
   */
  using value_type = ValueType;

  /**
   * @brief Create this equivalent to default number of value_type.
   */
  basic_residue_system() = default;

  /**
   * @brief Create this equivalent to value number.
   *
   * @param[in] value The equivalent number.
   */
  explicit constexpr basic_residue_system(const value_type& value)
    : value_ {value % Modulo}
  {
  }

  /**
   * @brief The explicit cast for value_type.
   *
   * This cast are explicit. ex)
   *
   * @code
   *   basic_residue_system<size_t, 2>{0} == 2; // Compile error
   * @endcode
   * 
   * If non-explicit on example of the above, a compile succeeded.
   * But result of the operator== are false.
   * So, this cast must be explicit.
   */
  explicit constexpr operator value_type() const noexcept
  {
    return value_;
  }

  constexpr bool operator==(const basic_residue_system& rhs) const noexcept
  {
    return value_ == rhs.value_;
  }

  constexpr basic_residue_system& operator++()
  {
    ++value_;
    value_ %= Modulo;
    return *this;
  }

  constexpr basic_residue_system& operator--()
  {
    if (value_ <= 0)
      value_ = Modulo - 1;
    else
      --value_;
    return *this;
  }

  constexpr basic_residue_system operator++(int)
  {
    basic_residue_system tmp{*this};
    ++*this;
    return tmp;
  }

  constexpr basic_residue_system operator--(int)
  {
    basic_residue_system tmp{*this};
    --*this;
    return tmp;
  }

  constexpr basic_residue_system operator+(const basic_residue_system& rhs) const
  {
    return basic_residue_system{value_ + rhs.value_};
  }

  constexpr basic_residue_system operator-(const basic_residue_system& rhs) const
  {
    return basic_residue_system{value_ + Modulo - rhs.value_};
  }

private:
  value_type value_;
};

template<std::size_t Modulo>
using residue_system = basic_residue_system<std::size_t, Modulo>;

}
}

#endif

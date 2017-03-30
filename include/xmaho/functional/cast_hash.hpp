#ifndef XMAHO_XMAHO_FUNCTIONAL_CAST_HASH_H
#define XMAHO_XMAHO_FUNCTIONAL_CAST_HASH_H

/**
 * @file functional/cast_hash.hpp
 * @brief This have definition of xmaho::functional::cast_hash class.
 */

#include <cstddef>

namespace xmaho
{
namespace functional
{

template<typename T>
struct cast_hash
{
  using result_type = std::size_t;
  using argument_type = T;

  constexpr result_type operator()(argument_type key) const noexcept(noexcept(static_cast<result_type>(key)))
  {
    return static_cast<result_type>(key);
  }
};

}
}

#endif

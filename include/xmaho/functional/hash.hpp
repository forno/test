#ifndef XMAHO_XMAHO_FUNCTIONAL_HASH_H
#define XMAHO_XMAHO_FUNCTIONAL_HASH_H

/**
 * @file functional/hash.hpp
 * @brief This have definition of xmaho::functional::hash functions.
 */

#include <cstddef>

namespace xmaho
{
namespace functional
{

template<typename T>
constexpr std::size_t hash_value(const T&);

template<>
constexpr std::size_t hash_value(const std::size_t& value)
{
  return value;
}

template<>
constexpr std::size_t hash_value(const char& value)
{
  return value;
}

template<typename T>
constexpr void hash_combine(std::size_t& seed, const T& value)
{
  seed ^= hash_value(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template<typename Iterator>
constexpr std::size_t hash_range(Iterator first, Iterator last)
{
  std::size_t seed {};
  while (first++ != last)
    hash_combine(seed, *first);
  return seed;
}

template<typename Iterator>
constexpr void hash_range(std::size_t& seed, Iterator first, Iterator last)
{
  while (first++ != last)
    hash_combine(seed, *first);
}

}
}

#endif

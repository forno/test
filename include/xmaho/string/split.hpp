#ifndef XMAHO_XMAHO_STRING_SPLIT_H
#define XMAHO_XMAHO_STRING_SPLIT_H

/**
 * @file string/split.hpp
 * @brief This have definition of xmaho::string::split functions.
 */

#include <cstddef>
#include <iterator>
#include <regex>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include "xmaho/traits/iterator.hpp"

namespace xmaho
{
namespace string
{

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to Container<string>.
 * On Javascript, It is know as String.split().
 *
 * @tparam    Container The result container type.
 * @param[in] first     The begin iterator of range for target string.
 * @param[in] last      The end iterator of range for target string.
 * @param[in] delimiter The delimiter of split.
 */
template<template<typename...> class Container = std::vector>
inline auto split(auto&& first, auto&& last, auto&& delimiter)
{
  static_assert(std::is_same<traits::Value_type<std::remove_reference_t<decltype(first)>>,
                             traits::Value_type<std::remove_reference_t<decltype(last)>>>{},
                "Defference value type of split target");
  using Iter = std::remove_reference_t<decltype(first)>;
  using TokenIter = std::regex_token_iterator<Iter>;
  using Regex = typename TokenIter::regex_type;
  using Result = Container<typename Regex::string_type>;

  Regex delim {std::forward<decltype(delimiter)>(delimiter)};
  return Result{TokenIter{std::forward<decltype(first)>(first), std::forward<decltype(last)>(last), delim, -1},
                TokenIter{}};
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<template<typename...> class Container = std::vector>
inline auto split(const auto& target, auto&& delimiter)
{
  using std::begin;
  using std::end;

  return split<Container>(begin(target), end(target), std::forward<decltype(delimiter)>(delimiter));
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<template<typename...> class Container = std::vector, typename CharT, std::size_t N>
inline auto split(const CharT (&target)[N], auto&& delimiter)
{
  return split<Container>(std::basic_string<CharT>{target}, std::forward<decltype(delimiter)>(delimiter));
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<template<typename...> class Container = std::vector, typename CharT>
inline auto split(const CharT* const& target, auto&& delimiter)
{
  return split<Container>(std::basic_string<CharT>{target}, std::forward<decltype(delimiter)>(delimiter));
}

}
}

#endif

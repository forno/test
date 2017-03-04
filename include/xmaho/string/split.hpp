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
 * @return The container has strings that are splited by delimiter.
 */
template<template<typename...> class Container = std::vector,
         typename BidirIter1,
         typename BidirIter2,
         typename Delimiter>
inline auto split(BidirIter1&& first, BidirIter2&& last, Delimiter&& delimiter)
{
  static_assert(
    std::is_same<
      traits::Value_type<std::remove_reference_t<BidirIter1>>,
      traits::Value_type<std::remove_reference_t<BidirIter2>>>{},
    "Defference value type of split target");
  using Iter = std::remove_reference_t<BidirIter1>;
  using TokenIter = std::regex_token_iterator<Iter>;
  using Regex = typename TokenIter::regex_type;
  using Result = Container<typename Regex::string_type>;

  Regex delim {std::forward<Delimiter>(delimiter)};
  return Result{TokenIter{
                  std::forward<BidirIter1>(first),
                  std::forward<BidirIter2>(last),
                  delim,
                  -1},
                TokenIter{}};
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 *
 * @tparam    Container The result container type.
 * @param[in] target    The string of splitting target.
 * @param[in] delimiter The delimiter of split.
 * @return The container has strings that are splited by delimiter.
 */
template<template<typename...> class Container = std::vector,
         typename String,
         typename Delimiter>
inline auto split(const String& target, Delimiter&& delimiter)
{
  using std::begin;
  using std::end;

  return split<Container>(
           begin(target),
           end(target),
           std::forward<Delimiter>(delimiter));
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 *
 * @tparam    Container The container type of result.
 * @tparam    CharT     The value type of target.
 * @tparam    N         The size of target.
 * @param[in] target    The string of splitting target.
 * @param[in] delimiter The delimiter of split.
 * @return The container has strings that are splited by delimiter.
 */
template<template<typename...> class Container = std::vector,
         typename CharT,
         std::size_t N,
         typename Delimiter>
inline auto split(const CharT (&target)[N], Delimiter&& delimiter)
{
  return split<Container>(
           std::basic_string<CharT>{target},
           std::forward<Delimiter>(delimiter));
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 *
 * @tparam    Container The result container type.
 * @tparam    CharT     The value type of target.
 * @param[in] target    The string of splitting target.
 * @param[in] delimiter The delimiter of split.
 * @return The container has strings that are splited by delimiter.
 */
template<template<typename...> class Container = std::vector,
         typename CharT,
         typename Delimiter>
inline auto split(const CharT* const& target, Delimiter&& delimiter)
{
  return split<Container>(
           std::basic_string<CharT>{target},
           std::forward<Delimiter>(delimiter));
}

}
}

#endif

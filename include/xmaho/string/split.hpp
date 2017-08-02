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
 * @tparam    BidirIter The string iterator. must be bidirctional or random iterator.
 * @tparam    Delimiter The delimiter type. must be convertable to regex.
 * @param[in] first     The begin iterator of range for target string.
 * @param[in] last      The end iterator of range for target string.
 * @param[in] delimiter The delimiter of split.
 * @return The container has strings that are splited by delimiter.
 */
template<template<typename...> class Container = std::vector,
         typename BidirIter,
         typename Delimiter>
inline auto split(BidirIter first, BidirIter last, Delimiter&& delimiter)
{
  using TokenIter = std::regex_token_iterator<BidirIter>;
  using Regex = typename TokenIter::regex_type;
  using Result = Container<typename Regex::string_type>;

  Regex delim {std::forward<Delimiter>(delimiter)};
  return Result{TokenIter{first, last, delim, -1}, TokenIter{}};
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 *
 * @tparam    Container The result container type.
 * @tparam    String    The string container type.
 * @tparam    Delimiter The delimiter type. must be convertable to regex.
 * @param[in] target    The string of splitting target.
 * @param[in] delimiter The delimiter of split.
 * @return The container has strings that are splited by delimiter.
 */
template<template<typename...> class Container = std::vector,
         typename String,
         typename Delimiter>
inline auto split(const String& target, Delimiter&& delimiter)
{
  return split<Container>(target.begin(), target.end(),
                          std::forward<Delimiter>(delimiter));
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 *
 * @tparam    Container The container type of result.
 * @tparam    charT     The value type of target.
 * @tparam    N         The size of target.
 * @tparam    Delimiter The delimiter type. must be convertable to regex.
 * @param[in] target    The string of splitting target.
 * @param[in] delimiter The delimiter of split.
 * @return The container has strings that are splited by delimiter.
 */
template<template<typename...> class Container = std::vector,
         typename charT,
         std::size_t N,
         typename Delimiter>
inline auto split(const charT (&target)[N], Delimiter&& delimiter)
{
  return split<Container>(std::basic_string<charT>{target},
                          std::forward<Delimiter>(delimiter));
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 *
 * @tparam    Container The result container type.
 * @tparam    charT     The value type of target.
 * @tparam    Delimiter The delimiter type. must be convertable to regex.
 * @param[in] target    The string of splitting target.
 * @param[in] delimiter The delimiter of split.
 * @return The container has strings that are splited by delimiter.
 */
template<template<typename...> class Container = std::vector,
         typename charT,
         typename Delimiter>
inline auto split(const charT* const& target, Delimiter&& delimiter)
{
  return split<Container>(std::basic_string<charT>{target},
                          std::forward<Delimiter>(delimiter));
}

}
}

#endif

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
template<typename T> class show_type;
/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<template<typename...> class Container = std::vector,
         typename BidirIter,
         typename Delimiter,
         typename ResultValue = std::basic_string<traits::Value_type<std::remove_reference_t<BidirIter>>>>
inline Container<ResultValue> split(BidirIter&& first, BidirIter&& last, Delimiter&& delimiter)
{
  using OriginalIter = std::remove_reference_t<BidirIter>;
  using Regex = std::basic_regex<traits::Value_type<OriginalIter>>;
  using TokenIter = std::regex_token_iterator<OriginalIter>;

  Regex delim {std::forward<Delimiter>(delimiter)};
  return {TokenIter{std::forward<BidirIter>(first), std::forward<BidirIter>(last), delim, -1}, TokenIter{}};
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<template<typename...> class Container = std::vector,
         typename String,
         typename Delimiter,
         typename ResultValue = String>
inline auto split(const String& target, Delimiter&& delimiter)
{
  return split<Container, typename String::const_iterator, Delimiter, ResultValue>
             (std::cbegin(target), std::cend(target), std::forward<Delimiter>(delimiter));
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<template<typename...> class Container = std::vector, typename CharT, std::size_t N, typename Delimiter>
inline auto split(const CharT (&target)[N], Delimiter&& delimiter)
{
  return split<Container>(std::basic_string<CharT>{target}, std::forward<Delimiter>(delimiter));
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<template<typename...> class Container = std::vector, typename CharT, typename Delimiter>
inline auto split(const CharT* const& target, Delimiter&& delimiter)
{
  return split<Container>(typename std::basic_string<CharT>{target}, std::forward<Delimiter>(delimiter));
}

}
}

#endif

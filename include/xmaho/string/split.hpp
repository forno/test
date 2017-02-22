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
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<typename BidirIter, typename Delimiter>
inline std::vector<std::basic_string<std::remove_const_t<traits::Value_type<BidirIter>>>>
split(BidirIter&& first, BidirIter&& last, Delimiter&& delimiter)
{
  using Regex = std::basic_regex<traits::Value_type<BidirIter>>;
  using TokenIter = std::regex_token_iterator<BidirIter>;

  Regex delim {std::forward<Delimiter>(delimiter)};
  return {TokenIter{std::forward<BidirIter>(first), std::forward<BidirIter>(last), delim, -1}, TokenIter{}};
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<typename String, typename Delimiter>
inline auto split(const String& target, Delimiter&& delimiter)
{
  return split(std::begin(target), std::end(target), std::forward<Delimiter>(delimiter));
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<typename CharT, std::size_t N, typename Delimiter>
inline auto split(const CharT (&target)[N], Delimiter&& delimiter)
{
  return split(std::begin(target), target + N - 1, std::forward<Delimiter>(delimiter)); // N - 1 for ignore \0
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<typename CharT, typename Delimiter>
inline auto split(const CharT* const& target, Delimiter&& delimiter)
{
  return split(typename std::basic_string<CharT>{target}, std::forward<Delimiter>(delimiter));
}

}
}

#endif

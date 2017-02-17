#ifndef XMAHO_XMAHO_STRING_SPLIT_H
#define XMAHO_XMAHO_STRING_SPLIT_H

/**
 * @file string/split.hpp
 * @brief This have definition of xmaho::string::split functions.
 */

#include <iterator>
#include <regex>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

#include "xmaho/traits.hpp"

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
inline std::vector<std::basic_string<typename std::iterator_traits<BidirIter>::value_type>>
split(BidirIter&& first, BidirIter&& last, Delimiter&& delimiter)
{
  using Regex = std::basic_regex<typename std::iterator_traits<BidirIter>::value_type>;
  using TokenIter = std::regex_token_iterator<BidirIter>;

  Regex delim {std::forward<Delimiter>(delimiter)};
  return {TokenIter{std::forward<BidirIter>(first), std::forward<BidirIter>(last), delim, -1}, TokenIter{}};
  return {};
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<typename String, typename Delimiter>
inline std::vector<String> split(const String& target, Delimiter&& delimiter)
{
  return split(target.cbegin(), target.cend(), std::forward<Delimiter>(delimiter));
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<typename CharT, size_t N, typename Delimiter>
inline std::vector<typename std::basic_string<CharT>> split(const CharT (&target)[N], Delimiter&& delimiter)
{
  return split(target, target + N, std::forward<Delimiter>(delimiter));
}

template<typename CharT, typename Delimiter>
inline std::vector<typename std::basic_string<CharT>> split(const CharT* target, Delimiter&& delimiter)
{
  return split(typename std::basic_string<CharT> {target}, std::forward<Delimiter>(delimiter));
}

}
}

#endif

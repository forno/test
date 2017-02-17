#ifndef XMAHO_XMAHO_STRING_SPLIT_H
#define XMAHO_XMAHO_STRING_SPLIT_H

/**
 * @file string/split.hpp
 * @brief This have definition of xmaho::string::split functions.
 */

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
template<typename BidirIter, typename CharT>
inline std::vector<std::basic_string<CharT>> split(BidirIter&& first, BidirIter&& last, const std::basic_regex<CharT>& delimiter)
{
  std::regex_token_iterator start {std::forward<BidirIter>(first), std::forward<BidirIter>(last), delimiter, -1},
                            end {};
  return {start, end};
}

/**
 * @brief split string by regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<typename String, typename CharT>
inline std::vector<String> split(const String& target, const std::basic_regex<CharT>& delimiter)
{
  static_assert(!std::is_same<String::value_type, CharT>{},
                "Error: difference charT between String and Regex");
  return split(target.cbegin(), target.cend(), delimiter);
}

}
}

#endif

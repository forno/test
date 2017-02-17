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
 * @brief Vector of string is splited by delimiter that is regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<typename BidirIter, typename Regex>
inline std::vector<typename Regex::string_type> split(BidirIter&& first, BidirIter&& last, const Regex& delimiter)
{
  std::regex_token_iterator start {std::forward<BidirIter>(first), std::forward<BidirIter>(last), delimiter, -1},
                            end {};
  return {start, end};
}

}
}

#endif

#ifndef XMAHO_XMAHO_STRING_SPLIT_H
#define XMAHO_XMAHO_STRING_SPLIT_H

/**
 * @file string/split.hpp
 * @brief This have definition of string::split function.
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
 * \brief Vector of string is splited by delimiter that is regex.
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<typename StringT, typename DelimiterT>
inline traits::Enable_if<std::is_same<DelimiterT,
                                      std::basic_regex<typename StringT::value_type>>{},
                         std::vector<StringT>>
split(const StringT& base_text, const DelimiterT& delimiter_regex)
{
  std::regex_token_iterator<typename StringT::const_iterator>
      first {base_text.cbegin(), base_text.cend(), delimiter_regex, -1},
      last {};
  return {first, last};
}

/**
 * \brief Vector of string is splited by delimiter that is string
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<typename StringT, typename DelimiterT>
inline traits::Enable_if<!std::is_same<typename std::remove_reference<DelimiterT>::type,
                                       std::basic_regex<typename StringT::value_type>>{},
                         decltype(split(StringT{}, std::basic_regex<typename StringT::value_type>{}))>
split(const StringT& base_text, DelimiterT&& delimiter)
{
  std::basic_regex<typename StringT::value_type> delimiter_regex {std::forward<DelimiterT>(delimiter)};
  return split(base_text, delimiter_regex);
}

/**
 * \brief xmaho::string::split for string literal
 *
 * Call xmaho::string::split with std::basic_string<CharT> on const CharT (&)[N].
 */
template<typename CharT, size_t N, typename DelimiterT>
inline auto split(const CharT (&base_text)[N], DelimiterT&& delimiter) -> decltype(split(std::basic_string<CharT>{}, std::forward<DelimiterT>(delimiter)))
{
  return split(std::basic_string<CharT>(base_text), std::forward<DelimiterT>(delimiter));
}

/**
 * \brief xmaho::string::split for char pointer
 *
 * Call xmaho::string::split with std::basic_string<CharT> on const CharT* (&).
 */
template<typename CharT, typename DelimiterT>
inline auto split(const CharT*& base_text, DelimiterT&& delimiter) -> decltype(split(std::basic_string<CharT>{}, std::forward<DelimiterT>(delimiter)))
{
  return split(std::basic_string<CharT>(base_text), std::forward<DelimiterT>(delimiter));
}

}
}

#endif

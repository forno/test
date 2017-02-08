#ifndef XMAHO_XMAHO_STRING_SPLIT_H
#define XMAHO_XMAHO_STRING_SPLIT_H

#include <regex>
#include <string>
#include <utility>
#include <vector>

namespace xmaho
{
namespace string
{

/**
 * \brief Vector of string is splited by delimiter
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<typename StringT, typename DelimiterT>
inline typename std::enable_if<std::is_same<DelimiterT,
                                            std::basic_regex<typename StringT::value_type>>{},
                               std::vector<StringT>>::type
split(const StringT& base_text, const DelimiterT& delimiter_regex)
{
  std::regex_token_iterator<typename StringT::const_iterator>
      first {base_text.cbegin(), base_text.cend(), delimiter_regex, -1},
      last {};
  return {first, last};
}

/**
 * \brief Vector of string is splited by delimiter
 *
 * The string is splited by delimiter to std::vector.
 * On Javascript, It is know as String.split().
 */
template<typename StringT, typename DelimiterT>
inline typename std::enable_if<!std::is_same<typename std::remove_reference<DelimiterT>::type,
                                             std::basic_regex<typename StringT::value_type>>{},
                               std::vector<StringT>>::type
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
inline std::vector<std::basic_string<CharT>> split(const CharT (&base_text)[N], DelimiterT&& delimiter)
{
  return split(std::basic_string<CharT>(base_text), std::forward<DelimiterT>(delimiter));
}

}
}

#endif

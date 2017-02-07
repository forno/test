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
template<typename DelimiterT, typename StringT>
inline std::vector<StringT> split(const StringT& base_text, DelimiterT&& delimiter)
{
  std::basic_regex<typename StringT::value_type> delimiterRegex(std::forward<DelimiterT>(delimiter));
  std::regex_token_iterator<typename StringT::const_iterator>
      first {base_text.cbegin(), base_text.cend(), delimiterRegex, -1},
      last;
  return {first, last};
}

/**
 * \brief xmaho::string::split for string literal
 *
 * Call xmaho::string::split with std::basic_string<CharT> on const CharT (&)[N].
 */
template<typename DelimiterT, typename CharT, size_t N>
inline std::vector<std::basic_string<CharT>> split(const CharT (&base_text)[N], DelimiterT&& delimiter)
{
  return split(std::basic_string<CharT>(base_text), std::forward<DelimiterT>(delimiter));
}

}
}

#endif

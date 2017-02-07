#ifndef XMAHO_XMAHO_STRING_H
#define XMAHO_XMAHO_STRING_H

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
std::vector<StringT> split(const StringT& base_text, DelimiterT&& delimiter)
{
  std::basic_regex<typename StringT::value_type> delimiterRegex(std::forward<DelimiterT>(delimiter));
  std::regex_token_iterator<typename StringT::const_iterator>
      first {base_text.cbegin(), base_text.cend(), delimiterRegex, -1},
      last;
  return {first, last};
}

template<typename CharT, size_t N, typename DelimiterT>
std::vector<std::basic_string<CharT>> split(const CharT (&base_text)[N], DelimiterT&& delimiter)
{
  return split(std::basic_string<CharT>(base_text), std::forward<DelimiterT>(delimiter));
}

}
}

#endif

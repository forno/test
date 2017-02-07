#ifndef XMAHO_XMAHO_STRING_H
#define XMAHO_XMAHO_STRING_H

#include <regex>
#include <vector>
#include <string>

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
std::vector<StringT> split(const StringT& base_text,
                           const DelimiterT& delimiter)
{
  std::basic_regex<typename StringT::value_type> delimiterRegex(delimiter);
  std::regex_token_iterator<typename StringT::const_iterator>
      first {base_text.cbegin(), base_text.cend(), delimiterRegex, -1},
      last;
  return {first, last};
}

}
}

#endif

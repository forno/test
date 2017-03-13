#ifndef XMAHO_XMAHO_STRING_STRING_H
#define XMAHO_XMAHO_STRING_STRING_H

/**
 * @file string/string.hpp
 * @brief This have definition of xmaho::string::string class.
 */

#include <array>
#include <cstddef>
#include <string>

namespace xmaho
{
namespace string
{

template<typename charT>
constexpr std::size_t strlen(const charT* str, std::size_t length)
{
  constexpr charT defval {};
  for (std::size_t i {}; i < length; ++i)
    if (*str++ == defval) return i;
  return length;
}

template<typename charT, std::size_t N, typename traits = std::char_traits<charT>>
class basic_string
{
public:
  using traits_type = traits;
  using value_type = typename traits_type::char_type;
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;
  using reference = value_type&;
  using const_reference = const value_type&;
  using pointer = value_type*;
  using const_pointer = const value_type*;
  using iterator = charT*;
  using const_iterator = const charT*;

  basic_string() = default;

private:
  template<typename T, T... Seq>
  constexpr basic_string(const const_pointer& str, std::integer_sequence<T, Seq...>)
    : data_ {{str[Seq]...}},
      size_ {strlen(str, sizeof...(Seq))}
  {
    static_assert(sizeof...(Seq) <= N, "string: max_size < your string size");
  }

public:
  template<size_type N2>
  constexpr basic_string(const value_type (&str)[N2])
    : basic_string(str, std::make_index_sequence<N2>{})
  {
    static_assert(N2 <= N, "string: max_size < your string size.");
  }

  constexpr size_type size() const noexcept
  {
    return size_;
  }

  constexpr const_iterator begin() const noexcept
  {
    return data_.begin();
  }

  constexpr const_iterator end() const noexcept
  {
    return std::next(data_.begin(), size_);
  }

private:
  std::array<value_type, N + 1> data_ {};
  size_type size_ {};
};

}
}

#endif

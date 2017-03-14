#ifndef XMAHO_XMAHO_STRING_STRING_H
#define XMAHO_XMAHO_STRING_STRING_H

/**
 * @file string/string.hpp
 * @brief This have definition of xmaho::string::string class.
 */

#include <cstddef>
#include <stdexcept>
#include <string>
#include <type_traits>

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

  static constexpr size_type npos = -1;

  basic_string() = default;

private:
  template<typename T, T... Seq>
  constexpr basic_string(const const_pointer& str, std::integer_sequence<T, Seq...>)
    : data_ {str[Seq]...},
      length_ {strlen(str, sizeof...(Seq))}
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

  template<size_type N2, size_type N3, typename T, T... Seq>
  constexpr basic_string(const basic_string<charT, N2, traits>& lhs,
                         const basic_string<charT, N3, traits>& rhs,
                         std::integer_sequence<T, Seq...>)
    : data_ {(Seq < lhs.size() ? lhs[Seq] :
              Seq < lhs.size() + rhs.size() ? rhs[Seq - lhs.size()] :
              charT{})...},
      length_ {lhs.size() + rhs.size()}
  {
    static_assert(N2 + N3 <= N, "string: max_size < your string size.");
  }

  template<std::size_t N2>
  constexpr auto operator+(basic_string<charT, N2, traits> rhs) const
  {
    return basic_string<charT, N + N2, traits>{*this, rhs, std::make_index_sequence<N+N2>{}};
  }

  constexpr const_reference operator[](size_type index) const
  {
    return data_[index];
  }

  constexpr reference operator[](size_type index)
  {
    return const_cast<reference>(const_cast<std::add_const_t<decltype(this)>>(this)->operator[](index));
  }

  constexpr size_type size() const noexcept
  {
    return length_;
  }

  constexpr size_type length() const noexcept
  {
    return size();
  }

  constexpr size_type max_size() const noexcept
  {
    return N;
  }

  constexpr size_type capacity() const noexcept
  {
    return max_size();
  }

  constexpr void clear() noexcept
  {
    front() = charT{};
    length_ = 0;
  }

  constexpr bool empty() const noexcept
  {
    return size() == 0;
  }

  constexpr const_reference at(size_type pos) const
  {
    return pos < size() ? operator[](pos) :
           throw std::out_of_range("string: index out of range.");
  }

  constexpr reference at(size_type pos)
  {
    return const_cast<reference>(const_cast<std::add_const_t<decltype(this)>>(this)->at(pos));
  }

  constexpr const_reference front() const noexcept
  {
    return operator[](0);
  }

  constexpr reference front() noexcept
  {
    return const_cast<reference>(const_cast<std::add_const_t<decltype(this)>>(this)->front());
  }

  constexpr const_reference back() const noexcept
  {
    return operator[](size() - 1);
  }

  constexpr reference back() noexcept
  {
    return const_cast<reference>(const_cast<std::add_const_t<decltype(this)>>(this)->back());
  }

  constexpr const_iterator begin() const noexcept
  {
    return data_;
  }

  constexpr const_iterator end() const noexcept
  {
    return data_ + length_;
  }

  constexpr iterator begin() noexcept
  {
    return data_;
  }

  constexpr iterator end() noexcept
  {
    return data_ + length_;
  }

  constexpr const_iterator cbegin() const noexcept
  {
    return data_;
  }

  constexpr const_iterator cend() const noexcept
  {
    return data_ + length_;
  }

private:
  value_type data_[N+1] {};
  size_type length_ {};
};

}
}

#endif

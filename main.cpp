#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#include <vector>

template<typename T>
constexpr T twice_newline[] {};

template<>
constexpr char twice_newline<char>[] {"\r\n\r\n"};

template<>
constexpr wchar_t twice_newline<wchar_t>[] {L"\r\n\r\n"};

template<>
constexpr char16_t twice_newline<char16_t>[] {u"\r\n\r\n"};

template<>
constexpr char32_t twice_newline<char32_t>[] {U"\r\n\r\n"};

int main(int, char**)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cout << "char" << twice_newline<char>;
  std::wcout << L"wchar" << twice_newline<wchar_t>;
}

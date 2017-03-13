#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_set>
#include <utility>

template<typename T> [[deprecated]] void show_type(T&&){};

template<std::size_t N>
struct str
{
  char data_[N];

  template<typename String, typename T, T... Seq>
  constexpr str(const String& arg, std::integer_sequence<T, Seq...>)
    : data_ {static_cast<char>(arg[Seq])...}
  {
  }
};

template<std::size_t N>
constexpr str<N> f(const char (&arg)[N])
{
  return str<N>(arg, std::make_index_sequence<N>{});
}


int main(int argc, char** argv) {
  constexpr auto s {f("hoge")};
  for (const auto& e : s.data_) {
    std::cout << e << ' ';
  }
  std::cout << std::endl;
}

#include <array>
#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_set>
#include <utility>

template<typename T> [[deprecated]] void show_type(T&&){};

int main(int argc, char** argv) {
  int a;
  const decltype(a) b {0};
  const decltype(b) c {0};
  static_assert(std::is_same<const int, decltype(b)>{}, "what");
  static_assert(std::is_same<const int, decltype(c)>{}, "what");
}

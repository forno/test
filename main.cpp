#include <array>
#include <cstddef>
#include <functional>
#include <iomanip>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_set>
#include <utility>
#include <valarray>

template<typename T> [[deprecated]] void show_type(T&&){};

constexpr auto limit {5};

int main(int argc, char** argv) {
  std::valarray<int> a(10);
  std::iota(std::begin(a), std::end(a), 0);
  std::cout << a;
}

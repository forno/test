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
  std::cout << std::setfill('0') << std::setw(5) << 1 << 2 << 3 << '\n';
  std::cout << 1 << 2 << 3 << '\n';
  std::cout << std::setw(8) << "ho" << "ge" << '\n';
  std::cout << "ho" << "ge" << '\n';
  std::cout << std::setw(5);
  std::cout << 0 << "nya" << std::endl;
  std::cout << 0 << "nya" << std::endl;
}

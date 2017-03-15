#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_set>
#include <utility>
#include <valarray>

template<typename T> [[deprecated]] void show_type(T&&){};

int main(int argc, char** argv) {
  std::unique_ptr<int> p1 {std::make_unique<int>(10)};
  std::unique_ptr<long> p2(std::move(p1));
  std::cout << *p2 << std::endl;
}

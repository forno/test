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
  constexpr std::array<int, 4> a{0,1,2};
  std::cout << std::get<2>(a) << std::get<3>(a) << std::endl;
}

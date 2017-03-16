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

const auto f()
{
  std::valarray<int> a(20);
  std::iota(std::begin(a), std::end(a), 0);
  return a.apply([](int e){std::cout << e << ' '; return 0;});
}

int main(int argc, char** argv) {
  std::valarray<int> a(20);
  std::iota(std::begin(a), std::end(a), 0);
  auto b {a.apply([](int e){std::cout << e << ' '; return 0;})};
  std::cout << "\nb: " << b[0] << std::endl;
  const auto& c {f()};
  std::cout << "\nc: " << c[0] << std::endl;
}

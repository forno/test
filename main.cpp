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
  return a[std::slice(1, 5, 2)];
}

int main(int argc, char** argv) {
  std::valarray<int> a(20);
  std::iota(std::begin(a), std::end(a), 0);
  auto b {a.apply([](int e){std::cout << e << ' '; return 0;})};
  std::cout << "\nb: " << b[0] << '\n';
  auto c {f()};
  std::valarray<int> d {c};
  std::cout << "\nd: " << d[0] << std::endl;
}

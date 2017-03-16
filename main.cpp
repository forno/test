#include <array>
#include <cstddef>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_set>
#include <utility>
#include <valarray>

template<typename T> [[deprecated]] void show_type(T&&){};

int main(int argc, char** argv) {
  std::valarray<bool> a(50);
  a[5] = true;
  std::cout << (a == false).sum() << std::endl;
}

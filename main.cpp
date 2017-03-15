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

enum class kind
{
  a,
  b,
  c
};

int main(int argc, char** argv) {
  std::valarray<kind> val {5};
  if (std::end(val) - std::begin(val) == 5)
    std::cout << "length is correct with uniform init\n";
  if (std::all_of(std::begin(val), std::end(val), [](auto e){return e == kind::a;}))
    std::cout << "default is kind::a\n";
  val = kind::b;
  if (std::all_of(std::begin(val), std::end(val), [](auto e){return e == kind::b;}))
    std::cout << "operator= is parfect move\n";
  std::cout << std::flush;
}

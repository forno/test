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

enum class kind
{
  zero, one, two, three, four, five, six, seven, eight, nine
};

namespace std
{

template<>
struct hash<kind>
{
  std::size_t operator()(kind) const noexcept;
};

}

std::size_t std::hash<kind>::operator()(kind k) const noexcept
{
  return static_cast<underlying_type_t<kind>>(k);
}

int main(int argc, char** argv) {
  const std::unordered_set<kind> set {
    kind::zero, kind::one, kind::two, kind::three, kind::four, kind::five, kind::six, kind::seven, kind::eight, kind::nine
  };
}

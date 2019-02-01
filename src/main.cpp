#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <random>
#include <string>
#include <string_view>
#include <utility>
#include <valarray>

template<typename T>
constexpr T get_value(std::istream& is)
{
  T v {};
  is >> v;
  return v;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
  const auto input_length {get_value<std::size_t>(std::cin)};
  std::map<int, int> used_count {};

  for (auto i {input_length}; i; --i) {
    const auto input {get_value<int>(std::cin)};
    ++used_count[input];
  }

  const auto max_value {std::max_element(used_count.begin(), used_count.end(), [](const auto& lhs, const auto& rhs){
    return lhs.second < rhs.second;
  })->second};

  bool is_first {false};
  for (auto& v : used_count) {
    if (v.second == max_value) {
      if (std::exchange(is_first, true)) {
        std::cout.put(' ');
      }
      std::cout << v.first;
    }
  }
}

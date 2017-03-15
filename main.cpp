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

constexpr auto limit {5};

int main(int argc, char** argv) {
  std::default_random_engine rand {std::random_device{}()};
  std::vector<int> counter(limit);
  for (auto i {0}; i < 10000; ++i) {
    std::uniform_int_distribution<> dist {0, limit - 1};
    ++counter[dist(rand)];
  }
  std::for_each(counter.begin(), counter.end(), [](auto e){std::cout << e << ' ';});
}

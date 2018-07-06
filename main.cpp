#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <experimental/algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <random>
#include <valarray>

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
  constexpr auto length {10000000u};
  static_assert(length < std::numeric_limits<std::uint_fast32_t>::max(), "Size error");
  std::valarray<std::uint_fast32_t> a(length);
  std::iota(std::begin(a), std::end(a), 1);

  std::valarray<std::uint_fast32_t> ans(a.size() / 2);
  std::experimental::sample(std::begin(a), std::end(a), std::begin(ans), ans.size(), std::default_random_engine{std::random_device{}()});

  std::sort(std::begin(ans), std::end(ans));
  std::valarray<std::uint_fast32_t> dis(ans.size());
  std::adjacent_difference(std::begin(ans), std::end(ans), std::begin(dis));

  std::map<uint_fast32_t, uint_fast32_t> res;
  for (auto e : dis)
    ++res[e];

  for (const auto& e : res)
    std::cout << e.first << ',' << e.second << '\n';
}

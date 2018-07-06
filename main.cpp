#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <experimental/algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <random>
#include <string>
#include <valarray>

int main(int argc, char** argv)
{
  if (argc < 3) {
    std::cerr << "I need arguments\n";
    return EXIT_FAILURE;
  }

  std::size_t length {std::strtoul(argv[1], nullptr, 10)};
  assert(length < std::numeric_limits<std::uint_fast32_t>::max());

  float percent {std::strtof(argv[2], nullptr)};
  assert(percent <= 1);

  std::valarray<std::uint_fast32_t> a(length);
  std::iota(std::begin(a), std::end(a), 1);

  std::valarray<std::uint_fast32_t> ans(static_cast<std::size_t>(a.size() * percent));
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

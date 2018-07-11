#include <algorithm>
#include <experimental/algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
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
    std::cerr << "I need arguments\n"
                 "[Usage]   execute [data size] [rest percent]\n"
                 "[Example] execute 100000 0.7\n";
    return EXIT_FAILURE;
  }

  std::size_t length {std::stoul(argv[1])};
  assert(length < std::numeric_limits<std::uint_fast32_t>::max());

  auto percent {std::stof(argv[2])};
  assert(percent <= 1);

  std::valarray<std::uint_fast32_t> a(length);
  std::iota(std::begin(a), std::end(a), 1);

  std::valarray<std::uint_fast32_t> ans(static_cast<std::size_t>(static_cast<decltype(percent)>(a.size()) * percent));
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

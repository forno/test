#include <cmath>
#include <iostream>
#include <limits>
#include <random>

int main(int argc, char** argv)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::uniform_int_distribution<> dist {-static_cast<int>(std::pow(std::abs(std::numeric_limits<int>::min() + 1), 1. / 5)), static_cast<int>(std::pow(std::numeric_limits<int>::max(), 1. / 5))};
  std::default_random_engine rand {std::random_device{}()};

  auto a {dist(rand)};
  auto b {dist(rand)};

  std::cout << "abs(min) == " << std::abs(std::numeric_limits<int>::min()) << '\n';
  std::cout << "[min max]             == [" << -static_cast<int>(std::pow(std::abs(std::numeric_limits<int>::min() + 1), 1. / 5)) << ' ' << static_cast<int>(std::pow(std::numeric_limits<int>::max(), 1. / 5)) << "]\n"
            << "[a b]                 == [" << a << ' ' << b << "]\n"
            << "[a*a*a b*b*b]         == [" << a*a*a << ' ' << b*b*b << "]\n"
            << "[pow(a, 3) pow(b, 3)] == [" << std::pow(a, 3) << ' ' << std::pow(b, 3) << "]\n";
}

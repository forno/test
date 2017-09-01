#include <cstddef>
#include <iostream>
#include <limits>
#include <utility>
#include <valarray>

int main(int argc, char** argv)
{
  std::cout << "max size: " << std::numeric_limits<std::size_t>::max() << std::endl;
  std::valarray<int> v1(std::numeric_limits<std::size_t>::max() / 18446744073ul);
  std::cout << "v1 is created" << std::endl;
  std::valarray<int> v2 {std::move(v1)};
  std::cout << "v2 is created" << std::endl;
  std::valarray<int> v3 {std::move(v2)};
  std::cout << "v3 is created" << std::endl;
}

#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main(int argc, char** argv)
{
  const auto target {[]{std::string s; std::cin >> s; return s;}()};
  const auto data {[data_length = []{std::size_t v; std::cin >> v; return v;}()]{
    std::vector<std::string> v(data_length);
    for (auto& e : v)
      std::cin >> e;
    return v;
  }()};
  {
    const auto find_it {std::find(std::begin(data), std::end(data), target)};
    if (find_it != std::end(data)) {
      std::cout << std::distance(std::begin(data), find_it) << '\n';
      return EXIT_SUCCESS;
    }
  }
  std::cout << "-1\n";
}

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <istream>
#include <string>
#include <vector>

namespace
{

template<typename T>
T get_value(std::istream& is)
{
  T value;
  is >> value;
  return value;
}

}

int main(int, char**)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  const auto target {get_value<std::string>(std::cin)};
  const auto log([s = get_value<std::size_t>(std::cin)]{
    std::vector<std::string> v(s);
    for (auto& e : v)
      std::cin >> e;
    return v;
  }());

  const auto find_it {std::find(std::begin(log), std::end(log), target)};
  using namespace std::literals::string_literals;
  std::cout << (find_it == std::end(log) ? "NG\n"s : std::to_string(std::distance(std::begin(log), std::end(log)))) << '\n';
}

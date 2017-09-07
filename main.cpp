#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::size_t super_length;
  std::cin >> super_length;

  std::vector<int> super(super_length);
  for (auto& e : super)
    std::cin >> e;
  std::sort(super.begin(), super.end());

  std::size_t sub_length;
  std::cin >> sub_length;

  std::vector<int> sub(sub_length);
  for (auto& e : sub)
    std::cin >> e;
  std::sort(sub.begin(), sub.end());

  std::vector<int> result;
  std::set_difference(super.begin(), super.end(),
                      sub.begin(), sub.end(),
                      std::back_inserter(result));

  if (result.empty())
    std::cout << "No";
  else {
    bool first = true;
    for (const auto& e : result) {
      if (!std::exchange(first, false))
        std::cout << ' ';
      std::cout << e;
    }
  }
}

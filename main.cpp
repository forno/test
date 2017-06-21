#include <iostream>
#include <valarray>
#include <vector>

bool check_valid(int target, int min, int max) {
  return min <= target && target <= max;
}

int main()
{
  int length, center, limit;
  std::cin >> length >> center >> limit;
  const auto min {center - limit}, max {center + limit};

  std::vector<std::pair<int, int>> items(length);
  for (auto& e : items)
    std::cin >> e.first >> e.second;

  std::valarray<bool> filter(length);
  for (auto i {0}; i < length; ++i)
    filter[i] = check_valid(items[i].second, min, max);
  std::valarray<int> means(length);
  for (auto i {0}; i < length; ++i)
    means[i] = items[i].first;

  std::valarray<int> valid_means {means[filter]};
  auto max_mean {valid_means.max()};
  for (auto i {0}; i < length; ++i)
    if (filter[i] && means[i] == max_mean) {
      std::cout << i + 1 << '\n';
      return 0;
    }
  std::cout << "not found\n";
}

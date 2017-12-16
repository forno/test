#include <iostream>
#include <unordered_map>

int main(int, char**)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  const std::unordered_map<int, std::string> month_to_str {
    {1, "January"},
    {2, "February"},
    {3, "March"},
    {4, "April"},
    {5, "May"},
    {6, "June"},
    {7, "July"},
    {8, "August"},
    {9, "September"},
    {10, "October"},
    {11, "November"},
    {12, "December"}
  };

  const auto month {[]{int v; std::cin >> v; return v;}()};
  std::cout << month_to_str.at(month) << '\n';
}

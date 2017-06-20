#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

constexpr auto limit {1000000000ul};
constexpr auto input_max {1000000ul};

int main()
{
  std::uintmax_t input;
  std::cin >> input;

  std::uintmax_t result {1};
  for (auto i {input}; i > 1; --i) {
    std::vector<char> values;
    for (auto j {i}; j != 0; j /= 10)
      values.push_back(j % 10);
    const auto last_value {result};
    result = 0;
    for (auto j {0}; j < values.size(); ++j) {
      const auto mask {static_cast<std::uintmax_t>(std::pow(10, j))};
      result += (last_value % ((limit * input_max * 100) / mask)) * mask * values[j];
    }
    while (!(result % 10)) result /= 10;
    result %= limit * input_max;
//    std::cout << i << '\t' << result << '\n';
  }
  std::cout << result % limit << '\n';
}

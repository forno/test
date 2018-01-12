#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#include <vector>

template<typename T>
constexpr T value;

template<>
constexpr auto value<int> {0};

int main(int, char**)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cout << value<int>;
  std::cout << value<char>;
}

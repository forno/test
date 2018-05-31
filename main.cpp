#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <numeric>
#include <queue>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

int main()
{
  std::unordered_map<std::string, std::unordered_map<std::string, std::string>> m {};
  m.emplace("a", decltype(m)::mapped_type{{"b", "c"}});

  return EXIT_SUCCESS;
}

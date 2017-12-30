#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <unordered_set>
#include <valarray>
#include <vector>

int main(int, char**)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cout << static_cast<std::ostringstream&>(std::ostringstream{} << "one" << "two" << "three").str() << '\n';
  std::ostringstream oss{};
  std::cout << static_cast<std::ostringstream&>(oss << "one" << "two" << "three").str() << '\n';
}

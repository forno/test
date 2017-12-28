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

  for (std::string s; std::cin >> s;)
    std::cout << "load : " << std::cin.good() << ' ' <<  s << std::endl;
  if (!std::cin)
    std::cout << "good" << std::endl;
  if (std::cin.eof())
    std::cout << "ok" << std::endl;
}

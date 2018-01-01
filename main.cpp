#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <string_view>
#include <unordered_set>
#include <unordered_map>
#include <valarray>
#include <vector>

void func(std::string_view = {});

void func(std::string_view)
{
}

class c
{
public:
  std::unordered_map<std::string, std::string> f;
  std::string a;
  std::string b;
  std::string c;
  std::string d;
};

int main(int, char**)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  func();
}

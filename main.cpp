#include <algorithm>
#include <iostream>
#include <map>

int main(int argc, char** argv)
{
  std::string str;
  std::cin >> str;

  std::transform(str.begin(), str.end(), str.begin(), [](auto e){
    const std::map<char, char> rule {
      {'A', '4'}, {'L', '1'}
    };

    const auto it {rule.find(e)};
    return it == rule.end() ? e : it->second;
  });

  std::cout << str << '\n';
}

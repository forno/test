#include <iostream>
#include <utility>

void func(std::pair<int, int> p)
{
  std::cout << p.first << " , " << p.second << '\n';
}

int main(int argc, char** argv)
{
  func({1, 5});
}

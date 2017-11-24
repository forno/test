#include <iostream>
#include <string>

int main(int argc, char** argv)
{
  int member_count;
  int size_x, size_y;
  std::cin >> member_count >> size_x >> size_y;
  std::cout << (size_x * size_y) % member_count << '\n';
}

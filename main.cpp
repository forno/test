#include <iostream>
#include <string>

int main(int argc, char** argv)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string a, b;
  std::cin >> a >> b;
  if (a.back() != b.front()) {
    std::cout << "NG\n";
    return 0;
  }
  if (b.back() == 'n') {
    std::cout << "NG\n";
    return 0;
  }
  std::cout << "OK\n";
}

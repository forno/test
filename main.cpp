#include <iostream>
#include <regex>
#include <string>
#include <type_traits>
#include <vector>

template<typename CharT>
void func(const CharT*& input)
{
  std::cout << input << std::endl;
}

int main(int argc, char** argv) {
  func("hoge");
  auto buf = "nyan";
  func(buf);
}

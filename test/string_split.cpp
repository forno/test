#include "xmaho/string.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
  auto result = xmaho::string::split(std::string("hoge"), "o");
  for (auto& x : result) std::cout << x << std::endl;
  std::cout << "othor test" << std::endl;
  auto othertest = xmaho::string::split(("nyan"), "a");
  for (auto& x : othertest) std::cout << x << std::endl;
}

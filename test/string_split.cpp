#include <iostream>
#include <regex>
#include <string>

#include "xmaho/string.hpp"

int main(int argc, char* argv[]) {
  {
    std::cout << "[[test]]" << std::endl;
    std::string text("hogehogehoge");
    std::regex delim("o");
    auto result = xmaho::string::split(text, delim);
    for (auto& x : result) std::cout << x << std::endl;
  }
  {
    std::cout << "[[test]]" << std::endl;
    std::string text("hogehogehoge");
    std::string delim("o");
    auto result = xmaho::string::split(text, delim);
    for (auto& x : result) std::cout << x << std::endl;
  }
  {
    std::cout << "[[test]]" << std::endl;
    auto result = xmaho::string::split(std::string("hoge"), "o");
    for (auto& x : result) std::cout << x << std::endl;
  }
  {
    std::cout << "[[test]]" << std::endl;
    auto result = xmaho::string::split(("nyan"), "a");
    for (auto& x : result) std::cout << x << std::endl;
  }
}

#include <iostream>
#include <iterator>
#include <string>

#include <xmaho/xmaho.hpp>

int main(int argc, char** argv) {
  const char a[] {'a', 'v', '\0'};
  std::cout << std::string {std::begin(a), std::end(a)}.size() <<
    ':' << std::string {a}.size();
}

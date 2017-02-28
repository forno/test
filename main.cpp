#include <iostream>
#include <xmaho/xmaho.hpp>

int main(int argc, char** argv) {
  while (argc--) {
    std::cout << *argv << std::endl;
    ++argv;
  }
}

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_set>
#include <utility>

template<typename T> [[deprecated]] void show_type(T&&){};

void f(std::string) {}

int main(int argc, char** argv) {
  std::string{'a'};
  f('b');
}

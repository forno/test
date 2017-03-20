#include <array>
#include <cstddef>
#include <functional>
#include <iomanip>
#include <complex>
#include <iostream>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_set>
#include <utility>
#include <valarray>

template<typename T> [[deprecated]] void show_type(T&&){};

int main(int argc, char** argv) {
  std::string s;
  getline(std::cin, s);
  std::cout << s;
}

#include <array>
#include <cstddef>
#include <functional>
#include <iomanip>
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
  int i;
  std::cin >> i;
  switch (i) {
  case 0: case 1:
  { const int now {i};
    return now - i;
  }
  case 2:
    return 0;
  }
}

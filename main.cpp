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
  std::ios_base::sync_with_stdio(false);

  std::string s;
  getline(std::cin, s);
  auto it {std::find(std::make_reverse_iterator(s.end()), std::make_reverse_iterator(s.begin()), 'a').base()};
  std::cout << std::distance(s.begin(), it) << '\n';
  std::cout << s << '\n';
}

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

class c
{
  std::valarray<int> a;
  friend std::ostream& operator<<(std::ostream&, const c&);
public:
  c()
    : a(20)
  {
    std::iota(std::begin(a), std::end(a), 1);
  }

  auto get() noexcept
  {
    return a[std::slice(0, 5, 3)];
  }

  std::valarray<int> get() const noexcept
  {
    return a[std::slice(0, 5, 3)];
  }
};

std::ostream& operator<<(std::ostream& out, const c& o)
{
  std::copy(std::begin(o.a), std::end(o.a), std::ostream_iterator<int>(out, " "));
}

int main(int argc, char** argv) {
  c obj {};
  show_type(obj.get());
  obj.get() = 2;
  std::cout << obj;
  const c obj2 {};
  show_type(obj2.get());
  obj2.get() *= 2;
  std::cout << obj2;
}

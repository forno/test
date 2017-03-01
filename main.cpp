#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

struct n {
  n() // user definition are not noexcept
    : s {}
  {
//    throw std::logic_error {"Error"};
  }

  char s;
};

class c {
public:
  c() = default;
private:
  int m1;
  double m2;
  char m3;
  int* m4;
  bool m5;
  n m6;
};

int main(int argc, char** argv) {
//  constexpr c o {};
//  constexpr c co(o);
//  constexpr c mo(std::move(o));
  try {
    c o {};
  } catch (...) {}

  static_assert(noexcept(c()), "default constructor except");
  static_assert(std::is_nothrow_move_constructible<c>{}, "default move constructor");
}

#include <utility>
#include <type_traits>

class c {
public:
  c() = default;
private:
  int m1;
  double m2;
  char m3;
  int* m4;
  bool m5;
};

int main(int argc, char** argv) {
  constexpr c o {};
  constexpr c co(o);
  constexpr c mo(std::move(o));

  static_assert(noexcept(c::c), "default constructor except");
  static_assert(noexcept(c::operator=), "default copy constructor");
  static_assert(std::is_nothrow_move_constructible<c>{}, "default move constructor");
}

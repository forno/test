#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#include <vector>

class C
{
public:
  C()
    : value_ {"default"}
  {
    std::cout << "C::C : default constructer " << value_ << '\n';
  }

  C(std::string_view value)
    : value_ {std::cbegin(value), std::cend(value)}
  {
    std::cout << "C::C : default constructer " << value_ << '\n';
  }

  C(const C&)
  {
    std::cout << "C::C : copy constructer " << value_ << '\n';
  }

  C(C&&)
  {
    std::cout << "C::C : move constructer " << value_ << '\n';
  }

  C& operator=(const C&)
  {
    std::cout << "C::C : copy assign " << value_ << '\n';
    return *this;
  }

  C& operator=(C&&)
  {
    std::cout << "C::C : move assign " << value_ << '\n';
    return *this;
  }

  template<typename... Args>
  C& operator()(Args...)
  {
    return *this;
  }

  ~C()
  {
    std::cout << "C::~C : destructer " << value_ << '\n';
  }

private:
  std::string value_;
};

int main(int, char**)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  C{"wide"}(C{"first argument"})(C{"second argument1"}, C{"second argument2"})(C{"third argument"});
}

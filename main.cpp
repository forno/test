#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

template<typename T> [[deprecated]] void show_type(T&&){};

namespace ns
{
  struct s {
  };

  void swap(s&, s&)
  {
    std::cout << "user swap" << std::endl;
  }
}

template<typename T>
void f(T&& lhs, T&& rhs)
{
  using std::swap;
  swap(lhs, rhs);
}

int main(int argc, char** argv) {
  ns::s s1 {};
  ns::s s2 {};
  f(s1, s2);
}

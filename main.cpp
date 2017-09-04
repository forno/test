#include <iostream>
#include <type_traits>
#include <valarray>

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  static_assert(std::is_same<int&, decltype(std::declval<int&>())>{},
                "declval with lvalue reference");
}

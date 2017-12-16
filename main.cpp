#include <iostream>
#include <unordered_map>
#include <valarray>

template<typename T>
auto f(const std::valarray<T>& v)
{
  return v.apply([](const auto& e){std::cout << e << '\n'; return e;});
}

int main(int, char**)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  f(std::valarray<int>{1, 3, 5, 7, 9})[3];
}

#include <iostream>
#include <valarray>

using namespace std;

class C : private valarray<int>
{
public:
  using valarray<int>::valarray;

  auto begin() {
    return std::begin(static_cast<valarray<int>>(*this));
  }

  auto end() {
    return std::begin(static_cast<valarray<int>>(*this));
  }
};

int main(int argc, char** argv)
{
  {
    C array {2, 4, 5, 8, 10};
    for (auto e : array)
      std::cout << e << '\n';
  }

  {
    valarray<int> array {2, 4, 5, 8, 10};
    for (auto e : array)
      std::cout << e << '\n';
  }
}

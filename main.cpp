#include <iostream>
#include <utility>
#include <valarray>

class C : std::valarray<int>
{
public:
  using std::valarray<int>::valarray;

  std::gslice_array<int> block(std::pair<std::size_t, std::size_t> pos, std::pair<std::size_t, std::size_t> size)
  {
    return (std::valarray<int>::operator[](std::gslice{pos.first * 3 + pos.second, {size.first, size.second}, {3, 1}}));
  }
};

std::gslice_array<int> f(std::valarray<int> v)
{
  return (v[std::gslice{0, {2, 1}, {3, 1}}]);
}

int main(int argc, char** argv)
{
  {
    std::valarray<int> v {0, 1, 2, 3, 4, 5};
    std::valarray<int> nv {v[std::gslice{0, {2, 1}, {3, 1}}]};
    for (auto e : nv)
      std::cout << e << '\n';
    std::cout << std::flush;
  }
  {
    std::valarray<int> v {0, 1, 2, 3, 4, 5};
    //std::valarray<int> nv {f(v)};
    std::cout << "hoge" << std::endl;
    f(v) = 50;
    std::cout << "foo" << std::endl;
    //std::cout << "size : " << nv.size() << '\n';
    //for (auto e : nv)
    //  std::cout << e << '\n';
    //std::cout << std::flush;
    for (auto e : v)
      std::cout << e << '\n';
  }
  {
    C v {0, 1, 2, 3, 4, 5};
    std::valarray<int> nv {v.block({0, 0}, {2, 2})};
    std::cout << "size : " << nv.size() << '\n';
    for (auto e : nv)
      std::cout << e << '\n';
    std::cout << std::flush;
  }
}

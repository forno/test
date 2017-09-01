#include <initializer_list>
#include <iostream>
#include <type_traits>
#include <utility>
#include <valarray>
#include <vector>

class MyVector
{
public:
  template<typename... Args>
    MyVector(Args&&... args)
    : array_(std::forward<Args>(args)...)
  {
  }

  MyVector(std::initializer_list<int> init)
    : array_(init)
  {
  }

  template<typename... Args>
  auto operator[](Args&&... args) -> decltype(std::declval<std::valarray<int>>().operator[](std::forward<Args>(args)...))
  {
    return array_.operator[](std::forward<Args>(args)...);
  }

  decltype(auto) operator[](const std::vector<int>& i)
  {
    std::cout << "my extends\n";
    return array_[i[0]];
  }

private:
  std::valarray<int> array_;
};


int main()
{
  MyVector v(10);
  std::vector<int> hoge {2};
  std::cout << v[hoge] << '\n';
}

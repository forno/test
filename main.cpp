#include <iostream>
#include <tuple>
#include <utility>

class C
{
public:
  explicit C(int, std::pair<int, int>, std::tuple<int, int, std::pair<int, int>>)
  {
  }
};

int main(int argc, char** argv)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  C instance {0, {1, 2}, {3, 4, {5, 6}}};
}

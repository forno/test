#include <iostream>

class C
{
public:
  void operator()(){
    static int v;
    std::cout << ++v << '\n';
  }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
  C a{};
  C b{};

  a();
  b();
  a();
  b();

  return 0;
}

#include <iostream>
#include <utility>
#include <memory>

struct B {};
struct C1 {};
struct C2 {};

int main(int argc, char** argv)
{
  std::unique_ptr<B> p1 {std::make_unique<C1>()};
  std::unique_ptr<B> p2 {std::make_unique<C2>()};

  return 0;
}

#include <iostream>
#include <future>

int main(int argc, char** argv)
{
  auto func {std::async([]{return 9*8*7*6*5*4*3*2;})};
  std::cout << func.get() << std::endl;
}

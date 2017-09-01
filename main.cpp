#include <iostream>
#include <utility>

template<typename T>
void func(T&&)
{
  std::cout << "default\n";
}

const int& func(const int& v)
{
  std::cout << "const int&\n";
  return v;
}

int& func(int& v)
{
  std::cout << "int&\n";
  return v;
}

int&& func(int&& v)
{
  std::cout << "int&&\n";
  return std::move(v);
}

volatile const int& func(volatile const int& v)
{
  std::cout << "volatile const int&\n";
  return v;
}

volatile int& func(volatile int& v)
{
  std::cout << "volatile int&\n";
  return v;
}

volatile int&& func(volatile int&& v)
{
  std::cout << "volatile int&&\n";
  return std::move(v);
}

void call()
{
}

template<typename Head, typename... Tail>
void call(Head&& value, Tail&&... rect)
{
  func(std::forward<Head>(value));
  call(std::forward<Tail>(rect)...);
}

int main(int argc, char** argv)
{
  int i {0};
  const int ci {0};
  volatile int vi {0};
  volatile const int vci {0};
  volatile int rvi {0};

  call(i, ci, 0, vi, vci, std::move(rvi));
}

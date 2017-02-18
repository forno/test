#include <iostream>
#include <regex>
#include <string>
#include <type_traits>
#include <vector>

template<typename T, typename S>
bool func(const T& lhs, const S& rhs) {
  std::cout << "call1\n";
  return lhs < rhs;
}

template<typename T>
bool func(const T& lhs, const T& rhs) {
  std::cout << "call2\n";
  return lhs < rhs;
}

template<>
bool func(const int& lhs, const int& rhs) {
  std::cout << "call3\n";
  return lhs < rhs;
}

int main(int argc, char** argv) {
  constexpr int a1 {0}, a2 {1};
  func(a1, a2);

  constexpr double b1 {0.1}, b2 {3.1};
  func(b1, b2);

  func(a1, b2);
}

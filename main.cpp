#include <iostream>
#include <string>
#include <unordered_set>

#include <xmaho/xmaho.hpp>

template<typename OStream, template<typename...> class Container, typename... Args>
inline OStream& operator<<(OStream& s, const Container<Args...>& c)
{
  for (const auto& v : c)
    s << v;
  return s;
}

template<template<typename...> class Container = std::vector>
Container<std::string> foo()
{
  return {"hogehoge", "nyannyan"};
}

int main(int argc, char** argv) {
  std::cout << foo<std::unordered_set>();
}

#include <tuple>

#include <xmaho/xmaho.hpp>


template<typename T>
auto f(T v)
{
  return std::tuple<T>{v};
}

template<typename T, typename... Rests>
auto f(T v, Rests... rests)
{
  if (v)
    return std::tuple_cat(std::tuple<T>{v}, f(rests...));
  return f(rests...);
}

int main(int argc, char** argv) {
  f(5, 3.3, 2, 31, 'v') != f(3, 2, 3, 'a', 23.4);
}

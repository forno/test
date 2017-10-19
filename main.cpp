#include <iostream>
#include <boost/asio.hpp>

class base
{
public:
  constexpr explicit base(int value) noexcept;

  constexpr int operator+=(int value);

  constexpr explicit operator int() const noexcept;

private:
  int value_;
};

constexpr base::base(int value) noexcept
  : value_ {value}
{
}

constexpr int base::operator+=(int value)
{
  return value_ += value;
}

constexpr base::operator int() const noexcept
{
  return value_;
}

template<int v>
class c : private base
{
public:
  constexpr explicit c() noexcept;

  constexpr int operator+=(int value);

  constexpr explicit operator int() const noexcept;
};

template<int v>
constexpr c<v>::c() noexcept
  : base {v}
{
}

template<int v>
constexpr int c<v>::operator+=(int value)
{
  return base::operator+=(value);
}

template<int v>
constexpr c<v>::operator int() const noexcept
{
  return base::operator int();
}

template<int a, int b>
constexpr c<a> func()
{
  c<a> value;
  value += b;
  return value;
}


int main(int argc, char** argv)
{
  c<5> value;
  value += 5;
  std::cout << static_cast<int>(value) << '\n';

  constexpr auto v {func<3, 4>()};
  std::cout << static_cast<int>(v) << '\n';
}

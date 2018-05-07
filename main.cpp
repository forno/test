#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

template<typename T, typename... Args>
T get_input(std::basic_istream<Args...>& is);

class BigInteger
{
public:
  BigInteger();
  BigInteger(std::uintmax_t init_value);

  BigInteger& operator+=(const BigInteger& value);

  template<typename... Args>
  friend std::basic_ostream<Args...>& operator<<(std::basic_ostream<Args...>& os, const BigInteger& rhs);

private:
  std::valarray<std::uint_least16_t> values {};
};

template<typename T>
constexpr std::size_t bit_digit(T value, std::size_t bit_width = 2)
{
  std::size_t ans {0};
  while (value >>= bit_width)
    ++ans;
  return ans + 1;
}

template<typename... Args>
std::basic_ostream<Args...>& operator<<(std::basic_ostream<Args...>& os, const BigInteger& rhs);

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  constexpr auto init {0xffeedu};
  std::cout << "init is : " << init << '\n';
  std::cout << "init size is : " << bit_digit(init, 16) << std::endl;
  BigInteger value {init};
  std::cout << value << '\n';
}

template<typename T, typename... Args>
T get_input(std::basic_istream<Args...>& is)
{
  T value;
  is >> value;
  return value;
}

BigInteger::BigInteger() = default;

BigInteger::BigInteger(std::uintmax_t init_value)
  : values(bit_digit(init_value, 16))
{
  constexpr auto bitmask16 {0xffffu};
  constexpr auto digits {16u};

  for (auto& e : values) {
    e = init_value & bitmask16;
    init_value >>= digits;
  }
}

BigInteger& BigInteger::operator+=(const BigInteger& rhs)
{
  return *this;
}

template<typename... Args>
std::basic_ostream<Args...>& operator<<(std::basic_ostream<Args...>& os, const BigInteger& rhs)
{
  if (rhs.values.size() == 0)
    return os;
  std::for_each(std::reverse_iterator{std::end(rhs.values)}, std::reverse_iterator{std::begin(rhs.values)},
  [&os](const auto& e){os << e << '\t';});
  return os;
}

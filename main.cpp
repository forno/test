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

template<typename T>
[[deprecated]]
constexpr void f(T)
{
}

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
  void resize(std::size_t length);

  static constexpr std::uint_least16_t mod {10000u};
  static const auto digit {static_cast<std::uint_least16_t>(std::log10(mod))};

  std::valarray<std::uint_least16_t> values {};
};

const std::uint_least16_t BigInteger::digit;

template<typename... Args>
std::basic_ostream<Args...>& operator<<(std::basic_ostream<Args...>& os, const BigInteger& rhs);

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  constexpr auto init {98765};
  BigInteger value {init};
  std::cout << "first is          : " << value << '\n';
  value += 50;
  std::cout << "be added 50 is    : " << value << '\n';
  value += 5000;
  std::cout << "be added 5000 is  : " << value << '\n';
  value += 10000;
  std::cout << "be added 10000 is : " << value << '\n';
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
  : values(static_cast<std::uintmax_t>(std::log10(static_cast<long double>(init_value))) / 4 + 1)
{
  for (auto& e : values) {
    e = static_cast<std::uint_least16_t>(init_value % mod);
    init_value /= mod;
  }
}

BigInteger& BigInteger::operator+=(const BigInteger& rhs)
{
  if (values.size() < rhs.values.size())
    resize(rhs.values.size());

  bool carry {false};
  auto it {std::begin(values)};
  std::for_each(std::begin(rhs.values), std::end(rhs.values), [&carry, &it](const auto& e){
    carry = mod <= (*it += e + (carry ? 1 : 0));
    if (carry)
      *it -= mod;
    ++it;
  });
  if (carry) {
    if (it == std::end(values)) {
      resize(values.size() + 1);
      it = std::end(values);
      --it;
    }
    *it += 1;
  }
  return *this;
}

template<typename... Args>
std::basic_ostream<Args...>& operator<<(std::basic_ostream<Args...>& os, const BigInteger& rhs)
{
  if (rhs.values.size() == 0)
    return os;
  bool isfirst {false};
  std::for_each(std::reverse_iterator{std::end(rhs.values)}, std::reverse_iterator{std::begin(rhs.values)},
  [&os, &isfirst](const auto& e){os << (std::exchange(isfirst, true) ? ' ' : '\0') << e;});
  return os;
}

void BigInteger::resize(std::size_t length)
{
  const auto tmp {values};
  values.resize(length);
  std::copy(std::begin(tmp), std::end(tmp), std::begin(values));
}

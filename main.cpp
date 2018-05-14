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

  std::uintmax_t count {0};
  std::uintmax_t limit {2600};
  while (true) {
    long double now_time;
    if (std::cin >> now_time) {
      if (now_time < limit)
        ++count;
      else {
        std::cout << limit << ',' << count << '\n';
        limit += 2600;
        count = 1;
      }
    } else {
      std::cout << limit << ',' << count << '\n';
      return 0;
    }
  }
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
  : values(static_cast<std::uintmax_t>(std::log10(static_cast<long double>(init_value))) / 4u + 1u)
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

  auto carry {false};
  auto it {std::begin(values)};
  for (const auto& e : rhs.values) {
    if (carry = mod <= (*it += e + (carry ? 1u : 0u)))
      *it -= mod;
    ++it;
  }

  if (carry) {
    if (it == std::end(values)) {
      resize(values.size() + 1u);
      it = std::prev(std::end(values));
    }
    *it += 1;
  }
  return *this;
}

template<typename... Args>
std::basic_ostream<Args...>& operator<<(std::basic_ostream<Args...>& os, const BigInteger& rhs)
{
  if (rhs.values.size() == 0u)
    return os;
  bool isfirst {false};
  std::for_each(std::reverse_iterator{std::end(rhs.values)}, std::reverse_iterator{std::begin(rhs.values)},
                [&os, &isfirst](const auto& e){os << (std::exchange(isfirst, true) ? ' ' : '\0') << e;});
  return os;
}

void BigInteger::resize(std::size_t length)
{
  if (values.size() == length)
    return;
  const decltype(values) tmp {length > values.size() ? values : values[std::slice(0, length, 1)]};
  values.resize(length);
  std::copy(std::begin(tmp), std::end(tmp), std::begin(values));
}

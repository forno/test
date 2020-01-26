#include <bits/stdc++.h>
using namespace std;
using namespace std::literals::chrono_literals;
using namespace std::literals::string_literals;
using ll = long long;

#define repi(i, s, n) for (long long i {s}, i##_len{n}; i < i##_len; ++i)
#define rep(i, n) repi(i, 0, n)
#define all(x) std::begin(x), std::end(x)

namespace xmaho
{
inline namespace input
{
template<typename T>
T get_value(std::istream& is = std::cin);
template<typename C>
C get_container(std::istream& is = std::cin, typename C::size_type length = std::numeric_limits<typename C::size_type>::max());
}
}
namespace xmaho
{
inline namespace integer
{
template<typename C>
constexpr auto ssize(const C& c) noexcept(noexcept(c.size()))
  -> typename std::common_type<std::ptrdiff_t, typename std::make_signed<decltype(c.size())>::type>::type;
template <class T, ptrdiff_t N>
constexpr std::ptrdiff_t ssize(const T (&)[N]) noexcept;
}
}
using namespace xmaho;

int main()
{
  const auto h {get_value<uint64_t>()};
  const auto n {get_value<uint64_t>()};
  vector<std::pair<uint64_t, uint64_t>> magics{};
  magics.reserve(n);
  for (auto i {n}; i != 0; --i) {
    std::pair<uint64_t, uint64_t> p;
    cin >> p.first >> p.second;
    magics.push_back(std::move(p));
  }
  sort(magics.begin(), magics.end(), [](const auto& lhs, const auto& rhs){return lhs.second < rhs.second;}); // low use point
  const auto efficiency_comp {[](const auto& lhs, const auto& rhs){return (static_cast<float>(rhs.first) / rhs.second) < (static_cast<float>(lhs.first) / lhs.second);}};
  stable_sort(magics.begin(), magics.end(), efficiency_comp); // high effect


  const auto& useful_magic {magics.front()};
  {
    vector<float> efficiency(n);
    transform(magics.begin(), magics.end(), efficiency.begin(), [](const auto& e){return static_cast<float>(e.first) / e.second;});

    auto useful_efficity {efficiency.front()};
    const auto no_need_it {lower_bound(efficiency.begin(), efficiency.end(), useful_efficity / 2, greater<float>{})};
    magics.erase(next(magics.begin(), distance(efficiency.begin(), no_need_it)), magics.end());
    //magics.erase(lower_bound(magics.begin(), magics.end(), static_cast<float>(useful_magic.first) / useful_magic.second, efficiency_comp));
  }

  // after magics is useful magic only
  vector<uint64_t> damages(n);
  transform(magics.begin(), magics.end(), damages.begin(), [](const auto& e){return e.first;});
  const auto max_damage {*max_element(damages.begin(), damages.end())};
  if (h <= max_damage) {
    sort(magics.begin(), magics.end(), [](auto lhs, auto rhs){return lhs.first < rhs.first;});
    for (const auto& e : magics) {
      if (h <= e.first) {
        cout << e.second << '\n';
        return 0;
      }
    }
    return 1;
  }
  uint64_t use_count {(h - max_damage + useful_magic.first - 1) / useful_magic.first};
  const auto left_h {h - useful_magic.first * use_count};
  auto res {useful_magic.second * use_count};
  sort(magics.begin(), magics.end(), [](auto lhs, auto rhs){return lhs.first < rhs.first;});
  for (const auto& e : magics) {
    if (left_h <= e.first) {
      cout << res + e.second << '\n';
      return 0;
    }
  }

  return 1;
}

class initalization
{
  class custom_numpunct: public std::numpunct<char>
  {
  public:
    using numpunct::numpunct;
  protected:
    std::string do_truename() const override { return "Yes"; }
    std::string do_falsename() const override { return "No"; }
  };

public:
  initalization()
  {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.imbue(std::locale(std::cout.getloc(), new custom_numpunct{}));
    std::cout << std::boolalpha << std::fixed << std::setprecision(15);
  }
} initalize;

template<typename T>
T xmaho::input::get_value(std::istream& is)
{ T v {}; is >> v; return v; }

template<typename C>
C xmaho::input::get_container(std::istream& is, typename C::size_type length)
{
  C v {};
  if (length != std::numeric_limits<typename C::size_type>::max())
    v.reserve(length);
  typename C::value_type e {};
  for (auto i {length}; i != 0 && is >> e; --i)
    v.push_back(std::move_if_noexcept(e));
  return v;
}

template<typename C>
constexpr auto xmaho::integer::ssize(const C& c) noexcept(noexcept(c.size()))
  -> typename std::common_type<std::ptrdiff_t, typename std::make_signed<decltype(c.size())>::type>::type
{ return c.size(); }

template <class T, ptrdiff_t N>
constexpr std::ptrdiff_t xmaho::integer::ssize(const T (&)[N]) noexcept
{ return N; }

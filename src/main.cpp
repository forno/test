#include <bits/stdc++.h>
using namespace std;
using namespace std::literals::chrono_literals;
using namespace std::literals::string_literals;

#define repi(i, s, n) for (intmax_t i {s}, i##_len{n}; i < i##_len; ++i)
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
  const auto n {get_value<intmax_t>()};
  const auto a_init {get_value<intmax_t>()};
  const auto b_init {get_value<intmax_t>()};

  intmax_t res {0};
  if ((a_init + b_init) % 2) {
    const auto wall_dis {min({a_init - 1, b_init - 1, n - a_init, n - b_init})};
    res = wall_dis + 1;
    cout << res + ((static_cast<intmax_t>(abs(a_init - b_init))) / 2) << '\n';
    return 0;
  }

  cout << static_cast<intmax_t>(abs(a_init - b_init) / 2) << '\n';
  return 0;
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

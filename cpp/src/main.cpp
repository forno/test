#include <bits/stdc++.h>
using namespace std::literals;
using namespace std;

namespace xmaho
{
  inline namespace input
  {
    template <typename T>
    T get_value(std::istream &is = std::cin);
    template <typename C>
    C get_container(std::istream &is = std::cin, typename C::size_type length = std::numeric_limits<typename C::size_type>::max());
  }
}
using namespace xmaho;

int main()
{
  default_random_engine engine{random_device{}()};
  uniform_int_distribution<> dist{0, 5};
  const auto get_dice = [&dist, &engine](auto)
  {
    return dist(engine);
  };

  const auto test_ochinchin = [&get_dice](auto)
  {
    array<uint, 6> dice_count{};

    for (const auto dice : views::iota(0, 5) | views::transform(get_dice))
    {
      ++dice_count[dice];
    }

    return dice_count[0] == 1 && dice_count[1] == 2 && dice_count[2] == 2;
  };

  const auto try_count = get_value<uint>(cin);
  const auto ochinchin_count = ranges::count(
      views::iota(0u, try_count) | views::transform(test_ochinchin),
      true);

  cout << ochinchin_count << '/' << try_count << '\n'
       << (double)ochinchin_count / try_count * 100. << endl;
  return 0;
}

class initalization
{
  class custom_numpunct : public std::numpunct<char>
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

template <typename T>
T xmaho::input::get_value(std::istream &is)
{
  T v{};
  is >> v;
  return v;
}

template <typename C>
C xmaho::input::get_container(std::istream &is, typename C::size_type length)
{
  C v{};
  if (length != std::numeric_limits<typename C::size_type>::max())
    v.reserve(length);
  typename C::value_type e{};
  for (auto i{length}; i != 0 && is >> e; --i)
    v.push_back(std::move_if_noexcept(e));
  return v;
}

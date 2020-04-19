#include <bits/stdc++.h>
#include <boost/range/irange.hpp>
using namespace std::literals;
using namespace std;

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
using namespace xmaho;

int main()
{
  double r;
  cin >> r;
  cout << (2.0 * r * 3.14159) << endl;
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


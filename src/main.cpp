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
  const auto N {get_value<unsigned long>(cin)};
  const auto K {get_value<unsigned long>(cin)};
  auto A {get_container<vector<unsigned long>>(cin, N)};

  vector<unsigned long> footprints(N);

  auto pos {0ul};
  for (auto i {0ul}; i < K; ++i) {
    if (footprints[pos] == 0) {
      footprints[pos] = i + 1;
      pos = A[pos] - 1;
    } else {
      const auto loop_length {i + 1 - footprints[pos]};
      if (loop_length > 1) {
        const auto left_count {K - i};
        const auto surplus_left_count {left_count % loop_length};
        const auto it {find(footprints.begin(), footprints.end(), surplus_left_count + footprints[pos])};
        pos = distance(footprints.begin(), it);
        cerr << "i, loop_length: " << i << ' ' << loop_length << '\n';
        cerr << "left_count: " << left_count << '\n';
        cerr << "surplus_left_count: " << surplus_left_count << '\n';
        cerr << "pos: " << pos << '\n';
      }
      break;
    }
  }

  cout << pos + 1 << '\n';

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

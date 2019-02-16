#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <random>
#include <string>
#include <string_view>
#include <utility>
#include <valarray>

template<typename T>
constexpr T get_value(std::istream& is)
{
  T v {};
  is >> v;
  return v;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
	int A, B, C, X;
	int total;
	int ans = 0;
	std::cin >> A >> B >> C >> X;
	for (int i = 0; i <= A; ++i) {
    std::cout << "i";
		for (int j = 0; j <= B; ++j) {
      std::cout << "j";
			for (int k = 0; k <= C; ++k) {
        std::cout << "k";
				total = 500*i + 100*j + 50*k;
				if (total == X) ++ans;
			}
		}
    std::cout << '\n';
	}
	std::cout << ans << std::endl;
	return 0;
}

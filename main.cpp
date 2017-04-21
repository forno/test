#include <complex>
#include <iostream>
#include <vector>

using point = std::complex<double>;

int main(int argc, char** argv)
{
  std::ios_base::sync_with_stdio(false);

  double origin_x, origin_y;
  int inner_range, outer_range;
  std::cin >> origin_x >> origin_y >> inner_range >> outer_range;
  point origin {origin_x, origin_y};

  int length;
  std::cin >> length;
  std::vector<point> points(length);
  for (auto& e : points) {
    double x, y;
    std::cin >> x >> y;
    e = point{x, y};
  }

  for (const auto& e : points) {
    const auto local_point {e - origin};
    const auto diff_length {std::abs(local_point)};
    std::cout << (inner_range <= diff_length && diff_length <= outer_range ? "yes" : "no");
    std::cout.put('\n');
  }

  return 0;
}

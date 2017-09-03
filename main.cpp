#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <random>
#include <valarray>

int main(int argc, char** argv)
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::random_device seed_gen;
  std::array<std::seed_seq::result_type, std::mt19937_64::state_size> seed_data;
  std::generate(seed_data.begin(), seed_data.end(), [&seed_gen]{return seed_gen();});

  std::seed_seq seq(seed_data.begin(), seed_data.end());
  std::mt19937_64 rand {seq};
  std::normal_distribution<> dist {0, 1};

  std::cout << "make values" << std::endl;
  std::valarray<double> population(100000000ul); // 500000000ul ok
  for (auto& e : population)
    e = dist(rand);

  std::cout << "sample values" << std::endl;
  std::valarray<double> sample(10000ul);
  std::sample(std::begin(population), std::end(population), std::begin(sample), sample.size(), rand);

  std::copy(std::begin(sample), std::end(sample), std::ostream_iterator<double>{std::cout, "\n"});
}

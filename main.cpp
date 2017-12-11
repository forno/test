#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <numeric>
#include <valarray>
#include <vector>

using value_type = unsigned int;

namespace std //! Template specialization is legal on std namespace.
{

template<>
struct equal_to<std::valarray<value_type>>
{
  bool operator()(const std::valarray<value_type>& lhs, const std::valarray<value_type>& rhs) const
  {
    return std::equal(std::begin(lhs), std::end(lhs), std::begin(rhs), std::end(rhs));
  }
};

}

int main(int argc, char** argv)
{
  const auto sequence_length {[]{std::size_t v; std::cin >> v; return v;}()};
  const auto target {[sequence_length]{
    std::valarray<value_type> v(sequence_length);
    for (auto& e : v)
      std::cin >> e;
    return v;
  }()};
  const auto transform_length {[]{std::size_t v; std::cin >> v; return v;}()};
  const auto transforms {[transform_length, sequence_length]{
    std::vector<std::valarray<std::size_t>> vv(transform_length, std::valarray<std::size_t>(sequence_length));
    for (auto& v : vv)
      for (auto& e : v)
        std::cin >> e;
    return vv;
  }()};

  const auto inital_sequence {[sequence_length]{
    std::valarray<value_type> v(sequence_length);
    std::iota(std::begin(v), std::end(v), 0);
    return v;
  }()};

  if (std::equal_to<std::valarray<value_type>>{}(target, inital_sequence)) {
    std::cout << "0\n";
    return EXIT_SUCCESS;
  }

  std::vector<std::valarray<value_type>> working_unexplored_sequences {inital_sequence};
  std::vector<std::valarray<value_type>> explored_sequences {inital_sequence};
  std::vector<std::valarray<value_type>> untransformed_sequences {}; // for runtime speed: should be in loop.
  for (auto i {1u}; !working_unexplored_sequences.empty(); ++i) {
    for (const auto& working_sequence : working_unexplored_sequences)
      for (const auto& transform : transforms) {
        std::valarray<value_type> new_sequence {working_sequence[transform]};
        if (std::equal_to<std::valarray<value_type>>{}(target, new_sequence)) {
          std::cout << i << '\n';
          return EXIT_SUCCESS;
        }
        const auto find_it {std::find_if(std::begin(explored_sequences), std::end(explored_sequences), [new_sequence](const auto& e){
          return std::equal_to<std::valarray<value_type>>{}(new_sequence, e);
        })};
        if (find_it == std::end(explored_sequences)) {
          explored_sequences.push_back(new_sequence);
          untransformed_sequences.push_back(new_sequence);
        }
      }
    working_unexplored_sequences = untransformed_sequences;
    untransformed_sequences.clear();
  }
  std::cout << "-1\n";
}

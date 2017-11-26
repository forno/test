#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

using Position = std::pair<int, int>;

const std::vector<char> board {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '\0', 'z', 'x', 'c', 'v', 'b', 'n', 'm', '\0', '\0', '\0'};

const Position size {10, 3};

Position get_position(char c)
{
  const auto pos {std::find(board.begin(), board.end(), c)};
  const auto index {std::distance(board.begin(), pos)};
  return {index % size.first, index / size.first};
}

std::size_t calculate_distance_1norm(Position lhs, Position rhs) {
  return std::abs(lhs.first - rhs.first) + std::abs(lhs.second - rhs.second);
}

enum class HandKind
{
  left,
  right
};

HandKind get_correct_hand(Position pos)
{
  return pos.first < 5 ? HandKind::left : HandKind::right;
}

std::pair<HandKind, Position> get_use_hand(char newchar, Position last_pos, HandKind last_hand)
{
  const auto new_pos {get_position(newchar)};
  const auto distance {calculate_distance_1norm(new_pos, last_pos)};
  if (distance <= 1) return {last_hand, new_pos};
  return {get_correct_hand(new_pos), new_pos};
}

int main(int argc, char** argv)
{
  std::string s;
  std::cin >> s;

  auto miss_count {0u};
  Position last_pos {}; // correct: 0, 0 are not affect to get_use_hand()
  HandKind last_hand {};
  for (auto e : s) {
    auto new_data {get_use_hand(e, last_pos, last_hand)};
    last_hand = new_data.first;
    last_pos = new_data.second;
    auto correct_hand {get_correct_hand(new_data.second)};
    if (new_data.first != correct_hand) ++miss_count;
  }

  std::cout << miss_count << '\n';
}

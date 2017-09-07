#include <iostream>
#include <valarray>

enum class Direction
{
  Left,
  Right
};

void rotate(std::pair<int, int>& dir, Direction dir_specify)
{
  if (dir.first) {
    dir.second = dir_specify == Direction::Right ? -dir.first : dir.first;
    dir.first = 0;
  } else {
    dir.first = dir_specify == Direction::Right ? dir.second : -dir.second;
    dir.second = 0;
  }
}

int main(int argc, char** argv)
{
  using position = std::pair<std::size_t, std::size_t>;

  constexpr auto poor {true};
  constexpr auto rich {false};

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  position size;
  std::cin >> size.second >> size.first;

  position pos;
  std::cin >> pos.second >> pos.first;
  --pos.first;
  --pos.second;

  std::valarray<bool> map(size.first * size.second);
  for (auto i {0}; i < map.size(); ++i) {
    char ch;
    std::cin >> ch;
    map[i] = (ch == '.');
  }

  std::pair<int, int> dir {0, -1};
  while (pos.first < size.first && pos.second < size.second) {
    const auto index_pos {pos.second * size.first + pos.first};
    rotate(dir, map[index_pos] ? Direction::Left : Direction::Right);
    map[index_pos] = !map[index_pos];
    pos.first += dir.first;
    pos.second += dir.second;
  }

  for (auto i {0}; i < size.second; ++i) {
    std::valarray<bool> row {map[std::slice{i * size.first, size.first, 1}]};
    for (auto e : row)
      std::cout << (e ? '.' : '*');
    std::cout << '\n';
  }
}

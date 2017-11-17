#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>
#include <valarray>

using Point = std::pair<std::size_t, std::size_t>;

class Board
{
public:
  enum class State
  {
    ice,
    dirt
  };

  static constexpr State convert_state(char type) {
    switch (type) {
    case '#': return Board::State::ice;
    case '.': return Board::State::dirt;
    }
    throw std::domain_error{"Error by convert_state"};
  }

  Board(const Point& size)
    : field(size.first * size.second),
      size {size}
  {
  }

  State operator()(const Point& position) const
  {
    return field[get_serial(position)];
  }

  template<typename F>
  void apply_self(F f)
  {
    field = field.apply(f);
  }

  Point get_size() const
  {
    return size;
  }

private:
  std::size_t get_serial(const Point& position) const
  {
    return position.first + position.second * size.second;
  }

  std::valarray<State> field;
  Point size;
};

namespace position
{


class Mover
{
public:
  virtual ~Mover() = default;

  Point move(Point now, const Board& board) const
  {
    do {
      if (is_edge(now, board.get_size()))
        return now;
      now = once(now);
    } while (board(now) == Board::State::ice);
    return now;
  }

private:
  virtual bool is_edge(const Point& now, const Point& limit) const = 0;
  virtual Point once(Point now) const = 0;
};

class MoverLeft
  : public Mover
{
  bool is_edge(const Point& now, const Point&) const final override
  {
    return now.first <= 0;
  }

  Point once(Point now) const final override
  {
    --now.first;
    return now;
  }
};

class MoverRight
  : public Mover
{
public:
  bool is_edge(const Point& now, const Point& limit) const final override
  {
    return now.first >= limit.first - 1;
  }

  Point once(Point now) const final override
  {
    ++now.first;
    return now;
  }
};

class MoverUp
  : public Mover
{
public:
  bool is_edge(const Point& now, const Point&) const final override
  {
    return now.second <= 0;
  }

  Point once(Point now) const final override
  {
    --now.second;
    return now;
  }
};

class MoverDown
  : public Mover
{
public:
  bool is_edge(const Point& now, const Point& limit) const final override
  {
    return now.second >= limit.second - 1;
  }

  Point once(Point now) const final override
  {
    ++now.second;
    return now;
  }
};

std::unique_ptr<Mover> get_mover(char type)
{
  switch (type) {
  case 'L': return std::make_unique<MoverLeft>();
  case 'R': return std::make_unique<MoverRight>();
  case 'U': return std::make_unique<MoverUp>();
  case 'D': return std::make_unique<MoverDown>();
  }
  throw std::domain_error{"Error by get_mover"};
}

}

int main(int argc, char** argv)
{
  Point size;
  std::cin >> size.second >> size.first;
  Board board {size};
  board.apply_self([](Board::State e){
    std::cout << (e == Board::State::ice ? '#' : '.');
    return e;
  });

  board.apply_self([](Board::State e){
    char c;
    while ((c = std::cin.get()) == '\n');
    return Board::convert_state(c);
  });
  
  Point now;
  std::cin >> now.first >> now.second;
  --now.first; --now.second;

  std::size_t move_count;
  std::cin >> move_count;
  for (auto i {move_count}; i > 0; --i) {
    char move_type;
    std::cin >> move_type;
    auto mover {position::get_mover(move_type)};
    now = mover->move(now, board);
  }
  std::cout << ++now.first << ' ' << ++now.second << '\n';
}

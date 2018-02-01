#include <algorithm>
#include <cstddef>
#include <ios>
#include <iostream>
#include <iterator>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

template<typename T, typename... Args>
T get_input(std::basic_istream<Args...>& is);

namespace rectangle
{

using Rectangle = std::vector<std::pair<int, int>>;
using point_type = std::pair<int, int>;
using size_type = std::pair<std::size_t, std::size_t>;

Rectangle make_rectangle();
Rectangle make_rectangle(point_type left_up, point_type right_down);
Rectangle make_rectangle(point_type left_up, size_type size);

class Operation
{
public:
  virtual ~Operation() noexcept;
  virtual Rectangle operator()(const Rectangle&, const Rectangle&) const = 0;
  virtual std::unique_ptr<Operation> copy() const = 0;
};

Operation::~Operation() noexcept = default;

class UnionOperation
  : public Operation
{
public:
  Rectangle operator()(const Rectangle& lhs, const Rectangle& rhs) const override;
  std::unique_ptr<Operation> copy() const override;
};

class ComplementOperation
  : public Operation
{
public:
  Rectangle operator()(const Rectangle& lhs, const Rectangle& rhs) const override;
  std::unique_ptr<Operation> copy() const override;
};

std::istream& operator>>(std::istream& is, std::unique_ptr<Operation>& v);

namespace square
{

Rectangle make_square(point_type left_up, std::size_t size);

template<typename... Args>
Rectangle make_square(std::basic_istream<Args...>& is);

}
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  rectangle::Rectangle calc_buf {rectangle::square::make_square(std::cin)};
  std::queue<rectangle::Rectangle> rectangles;
  std::queue<std::unique_ptr<rectangle::Operation>> operations;
  for (auto i {get_input<std::size_t>(std::cin)}; i != 0; --i)
  {
    rectangles.push(rectangle::square::make_square(std::cin));
    operations.push(get_input<std::unique_ptr<rectangle::Operation>>(std::cin));
  }

  for (; !operations.empty(); operations.pop(), rectangles.pop())
    calc_buf = (*operations.front())(calc_buf, rectangles.front());

  for (const auto& e : calc_buf) std::cout << '<' << e.first << ", " << e.second << "> ";
  std::cout << '\n';
  std::cout << calc_buf.size() << '\n';
}

template<typename T, typename... Args>
T get_input(std::basic_istream<Args...>& is)
{
  T value;
  is >> value;
  return value;
}

rectangle::Rectangle rectangle::make_rectangle()
{
  return {};
}

rectangle::Rectangle rectangle::make_rectangle(point_type left_up, point_type right_down)
{
  Rectangle v;
  for (auto i {left_up.first}; i < right_down.first; ++i)
    for (auto j {left_up.second}; j < right_down.second; ++j)
      v.emplace_back(i, j);
  return v;
}

rectangle::Rectangle rectangle::make_rectangle(point_type left_up, size_type size)
{
  return make_rectangle(
      left_up,
      point_type{left_up.first + static_cast<point_type::first_type>(size.first),
                 left_up.second + static_cast<point_type::second_type>(size.second)});
}

rectangle::Rectangle rectangle::UnionOperation::operator()(const Rectangle& lhs, const Rectangle& rhs) const
{
  Rectangle v;
  std::set_union(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend(), std::back_inserter(v));
  return v;
}

std::unique_ptr<rectangle::Operation> rectangle::UnionOperation::copy() const
{
  return std::make_unique<UnionOperation>();
}

rectangle::Rectangle rectangle::ComplementOperation::operator()(const Rectangle& lhs, const Rectangle& rhs) const
{
  Rectangle v;
  std::set_difference(lhs.cbegin(), lhs.cend(), rhs.cbegin(), rhs.cend(), std::back_inserter(v));
  return v;
}

std::unique_ptr<rectangle::Operation> rectangle::ComplementOperation::copy() const
{
  return std::make_unique<ComplementOperation>();
}

std::istream& rectangle::operator>>(std::istream& is, std::unique_ptr<Operation>& v)
{
  std::unordered_map<char, std::unique_ptr<Operation>> map;
  map.emplace('a', std::make_unique<UnionOperation>());
  map.emplace('d', std::make_unique<ComplementOperation>());

  const auto ch {get_input<char>(is)};
  const auto it {map.find(ch)};
  if (it == map.end()) {
    is.putback(ch);
  } else {
    v = it->second->copy();
  }
  return is;
}

rectangle::Rectangle rectangle::square::make_square(point_type left_up, std::size_t size)
{
  return make_rectangle(
      left_up,
      point_type{left_up.first + static_cast<point_type::first_type>(size),
                 left_up.second + static_cast<point_type::second_type>(size)});
}

template<typename... Args>
rectangle::Rectangle rectangle::square::make_square(std::basic_istream<Args...>& is)
{
  const auto left_point {get_input<int>(is)};
  const auto up_point {get_input<int>(is)};
  const auto size {get_input<std::size_t>(is)};
  return make_square({left_point, up_point}, size);
}

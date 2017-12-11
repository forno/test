#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
T get_value(istream& is) {
  T v;
  is >> v;
  return v;
}

string get_oneline(istream& is) {
  string s;
  getline(is, s);
  return s;
}

template<typename T>
vector<T> get_oneline_vector(istream& is) {
  const string oneline = get_oneline(is);
  vector<T> value;
  istringstream iss(oneline);
  for (T v; iss >> v;)
    value.push_back(v);
  return value;
}

// input data structure: c0r0 c0r1 c0r2...
//                       c1r0 c1r1...
template<typename T>
vector<vector<T>> get_multi_vector(istream& is, size_t col_size) {
  vector<vector<T>> value;
  value.reserve(col_size);
  for (size_t i = col_size; i > 0u; --i)
    value.push_back(get_oneline_vector<T>(is));
  return value;
}

int main(int argc, char** argv)
{
const auto value = []{size_t v; cin >> v; return v;}();
const auto oneline = []{string s; getline(cin, s); return s;}();

const auto multi_vector = []{
  using inner_vector = vector<size_t>;
  constexpr auto size = 3u;
  vector<inner_vector> value;
  value.reserve(size);
  for (auto i = size; i > 0u; --i)
    value.push_back([]{
      auto line = []{std::string s; getline(cin, s); return s;}();
      inner_vector value;
      istringstream iss(std::move(line));
      for (std::size_t v; iss >> v;)
        value.push_back(v);
      return value;
    }());
  return value;
}();

const auto values {[size = []{size_t v; cin >> v; return v;}()]{
  std::vector<int> v(size);
  for (auto& e : v)
    std::cin >> e;
  return v;
}()};

const auto values2 {[row_size = []{size_t v; cin >> v; return v;}(),
                    col_size = []{size_t v; cin >> v; return v;}()]{
  vector<vector<int>> vv(col_size);
  for (auto& v : vv) {
    v.resize(row_size);
    for (auto& e : v)
      cin >> e;
  }
  return vv;
}()};

for (const auto& v : multi_vector) {
  for (const auto& e : v)
    std::cout << e << ' ';
  std::cout.put('\n');
}
std::cout.put('\n');
for (const auto& e : values)
  std::cout << e << ' ';
std::cout.put('\n');
std::cout.put('\n');
for (const auto& v : values2) {
  for (const auto& e : v)
    std::cout << e << ' ';
  std::cout.put('\n');
}
}

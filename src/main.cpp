#include <bits/stdc++.h>
using namespace std;

template<typename T>
T get_value(std::istream& is);

int convert(const string& s, const unordered_map<char, int>& vars)
{
  try {
    return stoi(s);
  } catch (...) {
    return vars.at(s.front());
  }
}

int get_int_expr(istream& is, const unordered_map<char, int>& vars)
{
  string row;
  getline(is, row);
  istringstream iss {row};

  int cal {convert(get_value<string>(iss), vars)};
  for (string s; iss >> s;) {
    switch (s.front()) {
    case '+':
      cal += convert(get_value<string>(iss), vars);
      break;
    case '-':
      cal -= convert(get_value<string>(iss), vars);
      break;
    }
  }

  return cal;
}

vector<int> get_vec_expr(istream& is, const unordered_map<char, vector<int>>& vecs, const unordered_map<char, int>& vars)
{
  string row;
  getline(is, row);
  istringstream iss {row};

  const auto read_vec {[&](istream& is) {
    const auto first_char {get_value<string>(is).front()};
    if (first_char == '[') {
      string row;
      getline(is, row, ']');
      istringstream iss {row};

      vector<int> vec {};
      for (string s; iss >> s;) {
        vec.push_back(convert(s, vars));
        iss.ignore(numeric_limits<streamsize>::max(), ',');
      }
      return vec;
    } else {
      return vecs.at(first_char);
    }
  }};

  vector<int> cal {read_vec(iss)};
  for (string s; iss >> s;) {
    switch (s.front()) {
    case '+':
    {
      const auto val {read_vec(iss)};
      for (auto i {0ul}, end {cal.size()}; i < end; ++i) {
        cal[i] += val[i];
      }
      break;
    }
    case '-':
    {
      const auto val {read_vec(iss)};
      for (auto i {0ul}, end {cal.size()}; i < end; ++i) {
        cal[i] -= val[i];
      }
      break;
    }
    }
  }

  return cal;
}

int main() {
  const auto size {get_value<size_t>(cin)};

  unordered_map<char, int> var_map {};
  unordered_map<char, vector<int>> vec_map {};
  for (auto i {size}; i != 0; --i) {
    const auto op {get_value<string>(cin)};
    if (op == "int") {
      const auto var_name {get_value<string>(cin).front()};
      cin.ignore(numeric_limits<streamsize>::max(), '=');
      var_map.emplace(var_name, get_int_expr(cin, var_map));
    } else if (op == "print_int") {
      cout << get_int_expr(cin, var_map) << '\n';
    } else if (op == "vec") {
      const auto vec_name {get_value<string>(cin).front()};
      cin.ignore(numeric_limits<streamsize>::max(), '=');
      vec_map.emplace(vec_name, get_vec_expr(cin, vec_map, var_map));
    } else {
      const auto vec {get_vec_expr(cin, vec_map, var_map)};
      cout << '[';
      for (auto e : vec)
        cout << ' ' << e;
      cout << " ]\n";
    }
  }

  return 0;
}

template<typename T>
inline T get_value(std::istream& is)
{
  T v;
  is >> v;
  return v;
}

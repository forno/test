#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_set>
#include <valarray>
#include <vector>

template<typename T>
T get_value(std::istream& is)
{
  T v;
  is >> v;
  return v;
}

class player_iterator
{
private:
  std::valarray<bool>& v_;
  std::decay_t<decltype(std::begin(std::declval<std::valarray<bool>&>()))> it_;

public:
  player_iterator(std::valarray<bool>& v)
    : v_ {v},
      it_ {std::begin(v_)}
  {
  }

  player_iterator& operator++()
  {
    do {
      if(++it_ == std::end(v_))
        it_ = std::begin(v_);
    } while (!*it_);
    return *this;
  }

  decltype(*it_) operator*()
  {
    return *it_;
  }

  decltype(it_) raw()
  {
    return it_;
  }
};

int main(int, char**)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  const auto player_count {get_value<std::size_t>(std::cin)};
  const auto vocabulary_count {get_value<std::size_t>(std::cin)};
  const auto game_count {get_value<std::size_t>(std::cin)};

  const auto vocabularies {[vocabulary_count]{
    std::vector<std::string> v(vocabulary_count);
    for (auto& e : v)
      std::cin >> e;
    std::sort(v.begin(), v.end());
    return v;
  }()};

  std::valarray<bool> player_states(true, player_count);

  player_iterator player_it {player_states};
  std::unordered_set<std::string> used_words {};
  std::string last_value {};
  for (auto i {game_count}; i != 0; --i, ++player_it) {
    const auto value {get_value<std::string>(std::cin)};
    if (value.back() == 'z') {
      *player_it = false;
      last_value.clear();
      continue;
    }
    if (!last_value.empty() && last_value.back() != value.front()) {
      *player_it = false;
      last_value.clear();
      used_words.insert(value);
      continue;
    }
    if (!std::binary_search(vocabularies.begin(), vocabularies.end(), value)) {
      *player_it = false;
      last_value.clear();
      used_words.insert(value);
      continue;
    }
    if (used_words.count(value)) {
      *player_it = false;
      last_value.clear();
      continue;
    }
    used_words.insert(value);
    last_value = value;
  }

  std::cout << std::count(std::begin(player_states), std::end(player_states), true) << '\n';
  for (auto it {std::begin(player_states)}, end_it {std::end(player_states)};
       it != end_it;
       ++it) {
    if (*it)
      std::cout << std::distance(std::begin(player_states), it) + 1 << '\n';
  }
}

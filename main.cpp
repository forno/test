#include <iostream>
int main(void){
  int width, height, depth, length;
  std::cin >> width >> height >> depth >> length;

  std::vector<int> w_data {0, width};
  std::vector<int> h_data {0, height};

  for (auto i {length}; i > 0; --i) {
    int kind, pos;
    std::cin >> kind >> pos;
    if (kind == 0)
      w_data.push_back(pos);
    else
      h_data.push_back(pos);
  }

  std::sort(w_data.begin(), w_data.end());
  std::sort(h_data.begin(), h_data.end());

  std::vector<int> w_width(w_data.size());
  std::adjacent_difference(w_data.begin(), w_data.end(), w_width.begin());
  const auto min_w_width {*std::min_element(w_width.begin() + 1, w_width.end())};

  std::vector<int> h_width(h_data.size());
  std::adjacent_difference(h_data.begin(), h_data.end(), h_width.begin());
  const auto min_h_width {*std::min_element(h_width.begin() + 1, h_width.end())};

  std::cout << min_w_width * min_h_width * depth;

  return 0;
}


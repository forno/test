#include <iostream>
#include <regex>
#include <string>
#include <type_traits>
#include <vector>

int main(int argc, char** argv) {
  std::vector<std::string> input (argv, argv + argc);

  for (const auto& e : input) {
    std::regex delimiter {","};
    std::regex_token_iterator<std::remove_reference<decltype(e)>::type::const_iterator> start {e.cbegin(), e.cend(), delimiter, -1},
                                                                                        end {};
    for (;start != end; ++start)
      std::cout << *start << ' ';
    std::cout << std::endl;
  }
}

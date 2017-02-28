#include <xmaho/xmaho.hpp>

int main(int argc, char** argv) {
  using test_type = std::regex_token_iterator<std::string::iterator>;
  show_type<test_type>{};

  static_assert(std::is_same<test_type,
                             std::sregex_token_iterator>{},
                "Check type of regex_token_iterator");
}

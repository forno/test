#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>
#include <unordered_set>

template<typename T> [[deprecated]] void show_type(T&&){};

auto f(std::basic_string<auto> a){};

int main(int argc, char** argv) {
  f(std::string{});
}

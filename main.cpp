#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_set>
#include <utility>

template<typename T> [[deprecated]] void show_type(T&&){};

int main(int argc, char** argv) {
  auto p {std::make_unique<int>(3)};
}

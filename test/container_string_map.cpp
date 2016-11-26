#include "xmaho/container.h"

#include <cassert>

int main(int argc, char* argv[]) {
  xmaho::container::StringMap<int> map {};
  assert(map.empty());
  assert(map.emplace("first", 0).second);
  assert(map.emplace("second", 1).second);
  assert(map.at("first") != map.at("second"));
  assert(!map.emplace("first", 3).second);
  assert(map.at("first") == 0);
}

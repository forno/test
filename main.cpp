#include <xmaho/xmaho.hpp>

template<typename T> class show_type;

int main(int argc, char** argv) {
  show_type<xmaho::traits::Value_type<const char*>>{};
}

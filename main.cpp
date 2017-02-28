#include <string>

#include <xmaho/xmaho.hpp>

template<typename String = std::basic_string<CharT>, typename CharT>
auto f(CharT v)
{
}

int main(int argc, char** argv) {
  f<std::basic_string>('a');
}

#include <iostream>

#include <xmaho/ability_bank/connector.hpp>

int main(int argc, char** argv)
{
  xmaho::ability_bank::Connector connector {"localhost", "80", "/"};
  std::cout << connector("") << "\n\n";
  std::cout << connector("random-pick.html") << "\n\n";
}

#include <iostream>
#include <string>
#include <utility>

class Base
{
};

class Deriverd
  : public Base
{
};

class DeriverdPrivate
  : Base
{
public:
  Base& as_base()
  {
    return static_cast<Base&>(*this);
  }
};

int main(int argc, char** argv)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Deriverd deriverd {};
  Base& base_deriverd {static_cast<Base&>(deriverd)};

  DeriverdPrivate deriverd_private {};
  Base& base_deriverd_private {deriverd_private.as_base()};
}

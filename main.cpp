#include <cstdlib>
#include <sstream>

namespace
{

constexpr auto token {"xtv6U9xiWGDTLpp98eThGM5bDg5pywNgJfJE20Vcacd"};

}

int main(int argc, char** argv)
{
  std::ostringstream oss {};
  oss << "curl -X POST -H 'Authorization: Bearer " << token << "' -F 'message=foobar' https://notify-api.line.me/api/notify";
  std::system(oss.str().c_str());
}

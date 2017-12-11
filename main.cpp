#include <cstdlib>
#include <sstream>

namespace
{

constexpr auto token {
#include "token"
};

}

int main(int argc, char** argv)
{
  std::ostringstream oss {};
  oss << "curl -X POST -H 'Authorization: Bearer " << token << "' -F 'message=Studio daemon tester' https://notify-api.line.me/api/notify";
  std::system(oss.str().c_str());
}

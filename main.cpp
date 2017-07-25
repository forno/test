#include <boost/network/protocol/http/client.hpp>

int main()
{
  using namespace boost::network;
  using namespace boost::network::http;
  client::request request_("http://127.0.0.1:80/");
  request_ << header("Connection", "close");
  client client_;
  client::response response_ = client_.get(request_);
  std::string body_ = body(response_);
  std::cout << body_;
}

#include <iostream>
#include <string_view>

#include <boost/asio.hpp>

int main(int argc, char** argv)
{
  namespace asio = boost::asio;
  using asio::ip::tcp;

  asio::io_service io_service;
  tcp::socket socket(io_service);

  boost::system::error_code error;
  socket.connect(tcp::endpoint(asio::ip::address::from_string("127.0.0.1"), 31400), error);

  if (error)
    std::cout << "connect failed : " << error.message() << std::endl;
  else
    std::cout << "connected" << std::endl;
}

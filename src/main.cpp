#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
  using tcp = boost::asio::ip::tcp;
  namespace http = boost::beast::http;

  try {
    constexpr auto host {"example.com"};
    constexpr auto method {"http"};
    constexpr auto target {"/"};
    constexpr auto version {11};

    boost::asio::io_context ioc {};

    http::request<http::string_body> req{http::verb::get, target, version};
    req.set(http::field::host, host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    tcp::socket socket{ioc};
    boost::asio::connect(socket, tcp::resolver{ioc}.resolve(host, method));

    http::write(socket, req);

    boost::beast::flat_buffer buffer;
    http::response<http::dynamic_body> res;
    http::read(socket, buffer, res);

    std::cout << res << std::endl;

    boost::system::error_code ec;
    socket.shutdown(tcp::socket::shutdown_both, ec);
    if(ec && ec != boost::system::errc::not_connected)
      throw boost::system::system_error{ec};
  } catch(const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

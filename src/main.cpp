#include <cstdlib>
#include <iostream>
#include <string>

#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

int main(int argc, char** argv)
{
  try {
    constexpr auto host{"example.com"};
    constexpr auto method{"https"};
    constexpr auto target{"/"};
    constexpr auto version{11};

    boost::asio::io_context ioc{};
    boost::asio::ssl::context ctx{boost::asio::ssl::context::tlsv12_client};
    ctx.set_default_verify_paths();
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> stream{ioc, ctx};

    boost::beast::http::request<boost::beast::http::string_body> req{boost::beast::http::verb::get, target, version};
    req.set(boost::beast::http::field::host, host);
    req.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    boost::asio::connect(stream.next_layer(), boost::asio::ip::tcp::resolver{ioc}.resolve(host, method));
    stream.handshake(boost::asio::ssl::stream_base::client);

    boost::beast::http::write(stream, req);

    boost::beast::flat_buffer buffer;
    boost::beast::http::response<boost::beast::http::dynamic_body> res;
    boost::beast::http::read(stream, buffer, res);

    std::cout << res << std::endl;

    boost::system::error_code ec;
    stream.shutdown(ec);
    if(ec && ec != boost::asio::error::eof)
      throw boost::system::system_error{ec};
  } catch(const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

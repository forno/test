#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <string_view>

#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

namespace
{

bool is_whitelist_character_of_percent_encoding(char v)
{
  if (std::isalpha(v) || std::isdigit(v)) {
    return true;
  }
  switch (v) {
  case '-':
  case '.':
  case '_':
  case '~':
    return true;
  }
  return false;
}

std::string encode_percent_encoding(std::string_view sv)
{
  std::stringstream ss{};
  ss << std::hex << std::uppercase << std::setfill('0');
  for (unsigned char v : sv) {
    if (is_whitelist_character_of_percent_encoding(v)) {
      ss.put(v);
    } else {
      ss.put('%');
      ss << std::setw(2) << static_cast<int>(v);
    }
  }
  return ss.str();
}

}

int main(int argc, char** argv)
{
  for (std::string s; std::getline(std::cin, s);) {
    std::cout << encode_percent_encoding(s) << '\n';
  }
  return EXIT_SUCCESS;

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

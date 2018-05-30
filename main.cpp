#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <memory>
#include <numeric>
#include <queue>
#include <sstream>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

// Performs an HTTP GET and prints the response
int main()
{
  try
  {
    auto const host = "www.example.com";
    auto const port = "443";
    auto const target = "/";
    auto const version = 11;

    // The io_context is required for all I/O
    boost::asio::io_context ioc;

    // The SSL context is required, and holds certificates
    boost::asio::ssl::context ctx{boost::asio::ssl::context::tlsv12_client};

    // This holds the root certificate used for verification
    ctx.set_default_verify_paths();

    // These objects perform our I/O
    boost::asio::ip::tcp::resolver resolver{ioc};
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> stream{ioc, ctx};

    // Look up the domain name
    auto const results = resolver.resolve(host, port);

    // Make the connection on the IP address we get from a lookup
    boost::asio::connect(stream.next_layer(), results.begin(), results.end());

    // Perform the SSL handshake
    stream.handshake(boost::asio::ssl::stream_base::client);

    // Set up an HTTP GET request message
    boost::beast::http::request<boost::beast::http::string_body> req{boost::beast::http::verb::get, target, version};
    req.set(boost::beast::http::field::host, host);
    req.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    // Send the HTTP request to the remote host
    boost::beast::http::write(stream, req);

    // This buffer is used for reading and must be persisted
    boost::beast::flat_buffer buffer;

    // Declare a container to hold the response
    boost::beast::http::response<boost::beast::http::dynamic_body> res;

    // Receive the HTTP response
    boost::beast::http::read(stream, buffer, res);

    // Write the message to standard out
    std::cout << res << std::endl;

    // Gracefully close the stream
    boost::system::error_code ec;
    stream.shutdown(ec);
    if(ec == boost::asio::error::eof) {
      ec.assign(0, ec.category());
    }
    if(ec)
      throw boost::system::system_error{ec};

    // If we get here then the connection is closed gracefully
  }
  catch(std::exception const& e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

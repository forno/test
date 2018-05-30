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

constexpr auto host {"sparql.crssnky.xyz"};
constexpr auto target {"/spql/imas/query"};
constexpr auto version {11u};

int main()
{
  try
  {
    // Prepare some objects for The TCP over TLS connection (Asio settings)
    boost::asio::io_context ioc;
    boost::asio::ssl::context ctx{boost::asio::ssl::context::tlsv12_client};
    ctx.set_default_verify_paths();
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> stream{ioc, ctx};

    boost::asio::connect(stream.next_layer(), boost::asio::ip::tcp::resolver{ioc}.resolve(host, "https"));
    stream.handshake(boost::asio::ssl::stream_base::client);

    // HTTP POST section (with Beast library)
    boost::beast::http::request<boost::beast::http::string_body> req {boost::beast::http::verb::post, target, version};
    req.set(boost::beast::http::field::accept, "text/tab-separated-values");
    req.set(boost::beast::http::field::content_type, "application/sparql-query; charset=utf-8");
    req.set(boost::beast::http::field::host, host);
    req.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    req.body() = std::string{"SELECT ?n ?p WHERE{?s "}.append("<http://schema.org/name>").append(1, '|').append("<http://schema.org/alternateName>").append(1, '|').append("<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#nameKana>").append(" ?o; filter(regex(str(?o),\"").append("幽谷霧子").append("\")). ?s ?n ?p;}");
    req.content_length(req.body().size());

    boost::beast::http::write(stream, req);

    // HTTP response operation
    boost::beast::flat_buffer buffer;
    boost::beast::http::response<boost::beast::http::dynamic_body> res;
    boost::beast::http::read(stream, buffer, res);

    std::cout << boost::beast::buffers(res.body().data()) << std::endl;

    // Close connection (Asio setting)
    boost::system::error_code ec;
    stream.shutdown(ec);
    if(ec == boost::asio::error::eof) {
      ec.assign(0, ec.category());
    }
    if(ec)
      throw boost::system::system_error{ec};

  } catch(std::exception const& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

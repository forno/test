#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

constexpr auto host {"sparql.crssnky.xyz"};
constexpr auto sparql_endpoint {"/spql/imas/query"};

int main()
{
  try {
    boost::asio::io_context io_context {};
    boost::asio::ssl::context ssl_context {boost::asio::ssl::context::tlsv12};
    ssl_context.set_default_verify_paths();
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> ssl_socket {io_context, ssl_context};
    ssl_socket.set_verify_mode(boost::asio::ssl::verify_peer);
    boost::asio::connect(ssl_socket.lowest_layer(), boost::asio::ip::tcp::resolver{io_context}.resolve(host, "https"));
    ssl_socket.handshake(boost::asio::ssl::stream_base::client);

    const std::string query {R"(PREFIX schema: <http://schema.org/>
PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>
PREFIX imas: <https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#>
PREFIX imasrdf: <https://sparql.crssnky.xyz/imasrdf/RDFs/detail/>
PREFIX foaf: <http://xmlns.com/foaf/0.1/>
PREFIX math: <http://www.w3.org/2005/xpath-functions/math#>

SELECT ?n ?p
WHERE {
  ?s schema:name|schema:alternateName|imas:nameKana ?o;
     filter(regex(str(?o),"双葉杏")).
  ?s ?n ?p;
})"};
    boost::asio::streambuf request;
    std::ostream req {&request};
    req << "POST " << sparql_endpoint << " HTTP/1.1\r\n" <<
           "Host: " << host << "\r\n" <<
           "Content-Type: application/sparql-query; charset=utf-8\r\n" <<
           "Content-Length: " << query.size() << "\r\n" <<
           "Accept: application/sparql-results+json\r\n\r\n" <<
           query;

    boost::asio::write(ssl_socket, request);

    boost::asio::streambuf res;
    boost::system::error_code ec;
    boost::asio::read(ssl_socket, res, ec);

    if (ec != boost::asio::error::eof)
      throw std::runtime_error{"xmaho::ability_bank::Connector: Network error"};

    std::string receive_data {boost::asio::buffer_cast<const char*>(res.data())};
    std::cout << receive_data << '\n';
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }
}

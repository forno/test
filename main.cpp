#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

#include <boost/asio.hpp>

constexpr auto host {"sparql.crssnky.xyz"};
constexpr auto sparql_endpoint {"/spql/imas/query"};

int main()
{
  using boost::asio::ip::tcp;
  try {
    boost::asio::io_context io_context;
    tcp::socket s(io_context);
    boost::asio::connect(s, tcp::resolver{io_context}.resolve(host, "http"));

    const std::string query {R"(query=PREFIX%20schema%3A%20<http%3A%2F%2Fschema.org%2F>%0APREFIX%20imas%3A%20<https%3A%2F%2Fsparql.crssnky.xyz%2Fimasrdf%2FURIs%2Fimas-schema.ttl%23>%0ASELECT%20%3Fo%20%3Fh%0AWHERE%20%7B%0A%20%20%3Fs%20schema%3Aname%7Cschema%3AalternateName%20%3Fo%3B%0A%20%20%20%20%20schema%3Aheight%20%3Fh.%0A%7Dorder%20by(%3Fh))"};
    boost::asio::streambuf request;
    std::ostream req {&request};
    req << "GET " << sparql_endpoint << '?' << query << " HTTP/1.1\r\n" <<
           "Host: " << host << "\r\n" <<
           "Accept: application/sparql-results+json\r\n\r\n";

    boost::asio::write(s, request);

    boost::asio::streambuf res;
    boost::system::error_code ec;
    boost::asio::read(s, res, ec);

    if (ec != boost::asio::error::eof)
      throw std::runtime_error{"xmaho::ability_bank::Connector: Network error"};

    std::string receive_data {boost::asio::buffer_cast<const char*>(res.data())};
    std::cout << receive_data << '\n';
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }
}

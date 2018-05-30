#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstddef>
#include <cstdint>
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

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

inline constexpr auto pi {3.1415926535897932384626433832795029L};

namespace imasref
{

namespace imasparql
{

class Transporter
{
public:
  static constexpr auto host {"sparql.crssnky.xyz"};
  static constexpr auto sparql_endpoint {"/spql/imas/query"};

  explicit Transporter(boost::asio::io_context& io)
    : io_ {io},
      socket_ {io_, context_}
  {
    context_.set_default_verify_paths();
    socket_.set_verify_mode(boost::asio::ssl::verify_peer);
  }

  template<typename Iter>
  std::string communicate(Iter begin, Iter end, std::string_view value)
  {
    if (begin == end)
      return {};
  
    const static auto query_sequence {[&]{
      std::vector<std::string_view> query_parts {"SELECT ?n ?p WHERE{?s "};
      query_parts.emplace_back(*begin);
      for (++begin; begin != end; ++begin) {
        query_parts.emplace_back("|");
        query_parts.emplace_back(*begin);
      }
      query_parts.emplace_back(" ?o; filter(regex(str(?o),");
      query_parts.emplace_back(value);
      query_parts.emplace_back(")). ?s ?n ?p;}");
      return query_parts;
    }()};
  
    boost::asio::connect(socket_.lowest_layer(), boost::asio::ip::tcp::resolver{io_}.resolve(host, "https"));
    socket_.handshake(boost::asio::ssl::stream_base::client);
    boost::asio::streambuf request;
    std::ostream req {&request};
    req << "POST " << sparql_endpoint << " HTTP/1.1\r\n" <<
           "Host: " << host << "\r\n" <<
           "Content-Type: application/sparql-query; charset=utf-8\r\n" <<
           "Content-Length: " << std::accumulate(query_sequence.cbegin(), query_sequence.cend(), 0u, [](auto i, const auto& e){return i + e.size();}) << "\r\n" <<
           "Accept: text/tab-separated-values\r\n\r\n";
    for (const auto& e : query_sequence)
      req << e;
    boost::asio::write(socket_, request);

    boost::asio::streambuf res;
    boost::system::error_code ec;
    boost::asio::read(socket_, res, ec);
    if (ec != boost::asio::error::eof)
      throw std::runtime_error{"imasref::imasparql::Connector: Network error"};
    return std::string{boost::asio::buffer_cast<const char*>(res.data())};
  }

  std::string find_by_name(std::string_view name)
  {
    static const std::vector<std::string_view> predicate {"<http://schema.org/name>",
                                                          "<http://schema.org/alternateName>",
                                                          "<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#nameKana>"};
    return communicate(predicate.cbegin(), predicate.cend(), std::string{'"'}.append(name).append(1, '"'));
  }

private:
    boost::asio::ssl::context context_ {boost::asio::ssl::context::tlsv12};
    boost::asio::io_context& io_;
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> socket_;
};

}

}

template<typename T>
[[deprecated]]
constexpr void f(T)
{
}

template<typename T, typename... Args>
T get_input(std::basic_istream<Args...>& is);

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  boost::asio::io_context io {};
  imasref::imasparql::Transporter t {io};
  std::cout << t.find_by_name("萩原") << '\n';
}

template<typename T, typename... Args>
T get_input(std::basic_istream<Args...>& is)
{
  T value;
  is >> value;
  return value;
}

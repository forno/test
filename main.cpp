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

namespace imasref
{
namespace predicate
{
namespace idol
{

using namespace std::literals::string_view_literals;

constexpr auto age              {"<http://xmlns.com/foaf/0.1/age>"sv};
constexpr auto alternate_name   {"<http://schema.org/alternateName>"sv};
constexpr auto attribute        {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Attribute>"sv};
constexpr auto birth_date       {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#givenNameKana>"sv};
constexpr auto birth_place      {"<http://schema.org/birthPlace>"sv};
constexpr auto bloodtype        {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#BloodType>"sv};
constexpr auto bust             {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#bust>"sv};
constexpr auto color            {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Color>"sv};
constexpr auto constellation    {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#constellation>"sv};
constexpr auto cv               {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#cv>"sv};
constexpr auto description      {"<http://schema.org/description>"sv};
constexpr auto division         {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Division>"sv};
constexpr auto family_name      {"<http://schema.org/familyName>"sv};
constexpr auto fimily_name_kana {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#familyNameKana>"sv};
constexpr auto gender           {"<http://schema.org/gender>"sv};
constexpr auto given_name       {"<http://schema.org/givenName>"sv};
constexpr auto given_name_kana  {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#givenNameKana>"sv};
constexpr auto handedness       {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Handedness>"sv};
constexpr auto height           {"<http://schema.org/height>"sv};
constexpr auto hip              {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#hip>"sv};
constexpr auto hobby            {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Hobby>"sv};
constexpr auto member_of        {"<http://schema.org/memberOf>"sv};
constexpr auto name             {"<http://schema.org/name>"sv};
constexpr auto name_kana        {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#nameKana>"sv};
constexpr auto talent           {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Talent>"sv};
constexpr auto title            {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#Title>"sv};
constexpr auto type             {"<http://www.w3.org/1999/02/22-rdf-syntax-ns#type>"sv};
constexpr auto waist            {"<https://sparql.crssnky.xyz/imasrdf/URIs/imas-schema.ttl#waist>"sv};
constexpr auto weight           {"<http://schema.org/weight>"sv};

}
}

namespace imasparql
{

class Connector
{
public:
  using RDFClass = std::unordered_multimap<std::string, std::unordered_multimap<std::string, std::string>>;

  static constexpr auto host_name {"sparql.crssnky.xyz"};
  static constexpr auto end_point {"/spql/imas/query"};
  static constexpr auto http_version {11u};

  Connector(boost::asio::io_context& ioc, boost::asio::ssl::context& ctx)
    : ioc_ {ioc},
      ctx_ {ctx}
  {
  }

  template<typename Iter>
  RDFClass find_by(Iter predicate_begin, Iter predicate_end, std::string_view value)
  {
    std::vector<std::string_view> sparql_query {"SELECT ?s ?n ?p WHERE{?s "};
    sparql_query.emplace_back(*predicate_begin);
    std::for_each(++predicate_begin, predicate_end, [&sparql_query](const auto& e){
      sparql_query.emplace_back("|");
      sparql_query.emplace_back(e);});
    sparql_query.emplace_back(" ?o; filter(regex(str(?o),\"");
    sparql_query.emplace_back(std::move(value));
    sparql_query.emplace_back("\")). ?s ?n ?p;}");

    return parse_rdf_from_tsv(communicate(sparql_query.cbegin(), sparql_query.cend()));
  }

  RDFClass find_by_name(std::string_view value)
  {
    constexpr std::string_view predicates[] {
      predicate::idol::name,
      predicate::idol::alternate_name,
      predicate::idol::name_kana};

    return find_by(std::cbegin(predicates), std::cend(predicates), std::move(value));
  }

private:
  template<typename IterBegin, typename IterEnd>
  std::string communicate(IterBegin begin, IterEnd end)
  {
    if (begin == end)
      return {};

    // Setup TCP over TLS1.2
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> stream {ioc_, ctx_};
    boost::asio::connect(stream.next_layer(), boost::asio::ip::tcp::resolver{ioc_}.resolve(host_name, "https"));
    stream.handshake(boost::asio::ssl::stream_base::client);

    // Operate HTTP request
    auto req {create_request_template()};
    for (req.body().assign(*begin); ++begin != end; req.body().append(*begin));
    req.content_length(req.body().size());
    boost::beast::http::write(stream, req);

    // Operate HTTP response
    boost::beast::flat_buffer buffer;
    boost::beast::http::response<boost::beast::http::dynamic_body> res;
    boost::beast::http::read(stream, buffer, res);

    // Close connection
    boost::system::error_code ec;
    stream.shutdown(ec);
    if(ec == boost::asio::error::eof)
      ec.assign(0, ec.category());
    if(ec)
      throw boost::system::system_error{ec};

    return boost::beast::buffers_to_string(res.body().data());
  }

  static boost::beast::http::request<boost::beast::http::string_body> create_request_template()
  {
    boost::beast::http::request<boost::beast::http::string_body> req {boost::beast::http::verb::post, end_point, http_version};
    req.set(boost::beast::http::field::accept, "text/tab-separated-values");
    req.set(boost::beast::http::field::content_type, "application/sparql-query; charset=utf-8");
    req.set(boost::beast::http::field::host, host_name);
    req.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);
    return req;
  }

  static RDFClass parse_rdf_from_tsv(std::string tsv)
  {
    std::istringstream iss {tsv};
    iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore headline

    RDFClass ans {};
    for (std::string s {}; std::getline(iss, s);) {
      std::cout << s << std::endl;
      std::string n {s.substr(0, s.find('\t'))};
      const auto start_point_of_predicate {n.size() + 1};
      std::string p {s.substr(start_point_of_predicate, s.rfind('\t') - start_point_of_predicate)};
      std::string o {s.substr(start_point_of_predicate + p.size() + 1)};
      ans.emplace(std::move(n), RDFClass::mapped_type{{std::move(p), std::move(o)}});
    }
    return ans;
  }

  boost::asio::io_context& ioc_;
  boost::asio::ssl::context& ctx_;
};

}
}

int main()
{
  try
  {
    boost::asio::io_context ioc;
    boost::asio::ssl::context ctx{boost::asio::ssl::context::tlsv12_client};
    ctx.set_default_verify_paths();

    imasref::imasparql::Connector client {ioc, ctx};
    const auto rdf {client.find_by_name("幽谷霧子")};

    for (const auto n : rdf)
      for (const auto p : n.second)
          std::cout << n.first << '\t' << p.first << '\t' << p.second << '\n';

  } catch(std::exception const& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

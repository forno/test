#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <random>
#include <string>
#include <string_view>
#include <valarray>

#include <redland.h>

namespace rdf
{

class World
{
public:
  explicit World(librdf_world* v) noexcept;
  World(const World&) = delete;
  World& operator=(const World&) = delete;
  explicit World(World&& rhs) noexcept;
  World& operator=(World&& rhs) noexcept;
  ~World() noexcept;

  librdf_world* get() noexcept;
  librdf_world* release() noexcept;

  operator auto*() noexcept
  {
    return value;
  }

private:
  void delete_resource() noexcept;

  librdf_world* value;
};

World new_world();

class Uri
{
public:
  explicit Uri(librdf_uri* v) noexcept;
  Uri(const Uri&) = delete;
  Uri& operator=(const Uri&) = delete;
  explicit Uri(Uri&& rhs) noexcept;
  Uri& operator=(Uri&& rhs) noexcept;
  ~Uri() noexcept;

  librdf_uri* get() noexcept;
  librdf_uri* release() noexcept;

  operator auto*() noexcept
  {
    return value;
  }

private:
  void delete_resource() noexcept;

  librdf_uri* value;
};

Uri new_uri(librdf_world* w, const char* uri);

class Storage
{
public:
  explicit Storage(librdf_storage* v) noexcept;
  Storage(const Storage&) = delete;
  Storage& operator=(const Storage& rhs) = delete;
  explicit Storage(Storage&& rhs) noexcept;
  Storage& operator=(Storage&&) noexcept;
  ~Storage() noexcept;

  librdf_storage* get() noexcept;
  librdf_storage* release() noexcept;

  operator auto*() noexcept
  {
    return value;
  }

private:
  void delete_resource() noexcept;

  librdf_storage* value;
};

Storage new_storage(
  librdf_world* w,
  const char* storage_name,
  const char* name,
  const char* options_string);

class Model
{
public:
  explicit Model(librdf_model* v) noexcept;
  Model(const Model&) = delete;
  Model& operator=(const Model&) = delete;
  explicit Model(Model&& rhs) noexcept;
  Model& operator=(Model&& rhs) noexcept;
  ~Model() noexcept;

  librdf_model* get() noexcept;
  librdf_model* release() noexcept;

  operator auto*() noexcept
  {
    return value;
  }

private:
  void delete_resource() noexcept;

  librdf_model* value;
};

Model new_model(
  librdf_world* w,
  librdf_storage* s,
  const char* options_string);

class Parser
{
public:
  explicit Parser(librdf_parser* v) noexcept;
  Parser(const Parser&) = delete;
  Parser& operator=(const Parser&) = delete;
  explicit Parser(Parser&& rhs) noexcept;
  Parser& operator=(Parser&& rhs) noexcept;
  ~Parser() noexcept;

  librdf_parser* get() noexcept;
  librdf_parser* release() noexcept;

  operator auto*() noexcept
  {
    return value;
  }

private:
  void delete_resource() noexcept;

  librdf_parser* value;
};

Parser new_parser(
  librdf_world* w,
  const char* name,
  const char* mine_type,
  librdf_uri* type_uri);

class Statement
{
public:
  explicit Statement(librdf_statement* v) noexcept;
  Statement(const Statement&) = delete;
  Statement& operator=(const Statement&) = delete;
  explicit Statement(Statement&& rhs) noexcept;
  Statement& operator=(Statement&& rhs) noexcept;
  ~Statement() noexcept;

  librdf_statement* get() noexcept;
  librdf_statement* release() noexcept;

  operator auto*() noexcept
  {
    return value;
  }

private:
  void delete_resource() noexcept;

  librdf_statement* value;
};

Statement new_statement(librdf_world* w);

Statement new_statement(
  librdf_world* w,
  librdf_node* subject,
  librdf_node* predicate,
  librdf_node* object);

class Stream
{
public:
  explicit Stream(librdf_stream* v) noexcept;
  Stream(const Stream&) = delete;
  Stream& operator=(const Stream&) = delete;
  explicit Stream(Stream&& rhs) noexcept;
  Stream& operator=(Stream&& rhs) noexcept;
  ~Stream() noexcept;

  librdf_stream* get() noexcept;
  librdf_stream* release() noexcept;

  operator auto*() noexcept
  {
    return value;
  }

private:
  void delete_resource() noexcept;

  librdf_stream* value;
};

Stream find_statements(librdf_model* m, librdf_statement* s);

class Iterator
{
public:
  explicit Iterator(librdf_iterator* v) noexcept;
  Iterator(const Iterator&) = delete;
  Iterator& operator=(const Iterator&) = delete;
  explicit Iterator(Iterator&& rhs) noexcept;
  Iterator& operator=(Iterator&& rhs) noexcept;
  ~Iterator() noexcept;

  librdf_iterator* get() noexcept;
  librdf_iterator* release() noexcept;

  operator auto*() noexcept
  {
    return value;
  }

private:
  void delete_resource() noexcept;

  librdf_iterator* value;
};

Iterator get_targets(librdf_model* m, librdf_node* source, librdf_node* arc);

namespace raptor
{

raptor_world* get_raptor(librdf_world* p) noexcept;

class Iostream
{
public:
  explicit Iostream(raptor_iostream* v) noexcept;
  Iostream(const Iostream&) = delete;
  Iostream& operator=(const Iostream&) = delete;
  explicit Iostream(Iostream&& rhs) noexcept;
  Iostream& operator=(Iostream&& rhs) noexcept;
  ~Iostream() noexcept;

  raptor_iostream* get() noexcept;
  raptor_iostream* release() noexcept;

  operator auto*() noexcept
  {
    return value;
  }

private:
  void delete_resource() noexcept;

  raptor_iostream* value;
};

Iostream new_iostream(
  raptor_world* w,
  std::FILE* handle);

}
}

int main(int argc, char** argv)
{
  auto program {argv[0]};

  if (argc < 2 || argc > 3) {
    std::cerr << "USAGE: " << program << ": <RDF source URI> [rdf parser name]\n";
    return 1;
  }

  auto world {rdf::new_world()};
  librdf_world_open(world);
  auto raptor_world_ptr {rdf::raptor::get_raptor(world)};

  auto uri {rdf::new_uri(world, argv[1])};
  if (!uri) {
    std::cerr << program << ": Failed to create URI\n";
    return 1;
  }

  auto storage {rdf::new_storage(world, "memory", "test", nullptr)};
  if (!storage) {
    std::cerr << program << ": Failed to create new storage\n";
    return 1;
  }

  auto model {rdf::new_model(world, storage, nullptr)};
  if (!model) {
    std::cerr << program << ": Failed to create model\n";
    return 1;
  }

  auto parser_name {argc == 3 ? argv[2] : nullptr};

  {
    auto parser {rdf::new_parser(world, parser_name, nullptr, nullptr)};
    if (!parser) {
      std::cerr << program << ": Failed to create new parser\n";
      return 1;
    }

    /* PARSE the URI as RDF/XML*/
    std::cout << program << ": Parsing URI " << librdf_uri_as_string(uri) << '\n';
    if (librdf_parser_parse_into_model(parser, uri, uri, model)) {
      std::cerr << program << ": Failed to parse RDF into model\n";
      return 1;
    }
  }

  {
    auto statement2 {rdf::new_statement(
      world,
      librdf_new_node_from_uri_string(world, (const unsigned char*)"http://www.dajobe.org/"),
      librdf_new_node_from_uri_string(world, (const unsigned char*)"http://purl.org/dc/elements/1.1/title"),
      librdf_new_node_from_literal(world, (const unsigned char*)"My Home Page", nullptr, 0))};
    librdf_model_add_statement(model, statement2);
  }

  /* Print out the model*/
  std::cout << program << ": Resulting model is:\n";
  {
    auto iostr {rdf::raptor::new_iostream(raptor_world_ptr, stdout)};
    librdf_model_write(model, iostr);
  }


  /* Construct the query predicate (arc) and object (target) 
   * and partial statement bits
   */
  auto subject {librdf_new_node_from_uri_string(world, (const unsigned char*)"http://www.dajobe.org/")};
  auto predicate {librdf_new_node_from_uri_string(world, (const unsigned char*)"http://purl.org/dc/elements/1.1/title")};
  if (!subject || !predicate) {
    std::cerr << program << ": Failed to create nodes for searching\n";
    return 1;
  }

  auto partial_statement {rdf::new_statement(world)};
  librdf_statement_set_subject(partial_statement, subject);
  librdf_statement_set_predicate(partial_statement, predicate);


  /* QUERY TEST 1 - use find_statements to match */

  std::cout << program << ": Trying to find_statements\n";
  if (auto stream {rdf::find_statements(model, partial_statement)}; !stream) {
    std::cerr << program << ": librdf_model_find_statements returned nullptr stream\n";
  } else {
    auto count {0};
    while (!librdf_stream_end(stream)) {
      auto statement {librdf_stream_get_object(stream)};
      if (!statement) {
        std::cerr << program << ": librdf_stream_next returned nullptr\n";
        break;
      }

      std::cout << "  Matched statement: \n";
      librdf_statement_print(statement, stdout);
      std::cout.put('\n');

      librdf_stream_next(stream);
      ++count;
    }
    std::cerr << program << ": got " << count << "matching statements\n";
  }


  /* QUERY TEST 2 - use get_targets to do match */
  std::cout << program << ": Trying to get targets\n";
  {
    auto iterator {rdf::get_targets(model, subject, predicate)};
    if (!iterator) {
      std::cerr << program << ": librdf_model_get_targets failed to return iterator for searching\n";
      return 1;
    }

    auto count {0u};
    while(!librdf_iterator_end(iterator)) {
      librdf_node* target {static_cast<librdf_node*>(librdf_iterator_get_object(iterator))};
      if (!target) {
        std::cerr << program << ": librdf_iterator_get_object returned nullptr\n";
        break;
      }

      fputs("  Matched target: ", stdout);
      librdf_node_print(target, stdout);
      fputc('\n', stdout);

      count++;
      librdf_iterator_next(iterator);
    }
    std::cerr << program << ": got " << count << " target nodes\n";
  }

  /* the above does this since they are still attached */
  /* librdf_free_node(predicate); */
  /* librdf_free_node(object); */
  return 0;
}

inline rdf::World::World(librdf_world* v) noexcept
  : value {v}
{
}

inline rdf::World::World(World&& rhs) noexcept
  : value {rhs.release()}
{
}

inline rdf::World& rdf::World::operator=(World&& rhs) noexcept
{
  delete_resource();
  value = rhs.release();
  return *this;
}

inline rdf::World::~World() noexcept
{
  delete_resource();
}

inline librdf_world* rdf::World::get() noexcept
{
  return value;
}

inline librdf_world* rdf::World::release() noexcept
{
  auto v {value};
  value = nullptr;
  return v;
}

inline void rdf::World::delete_resource() noexcept
{
  if (value) {
    librdf_free_world(value);
    value = nullptr;
  }
}

inline rdf::World rdf::new_world()
{
  return World {librdf_new_world()};
}

inline rdf::Uri::Uri(librdf_uri* v) noexcept
  : value {v}
{
}

inline rdf::Uri::Uri(Uri&& u) noexcept
  : value {u.release()}
{
}

inline rdf::Uri& rdf::Uri::operator=(Uri&& rhs) noexcept
{
  delete_resource();
  value = rhs.release();
  return *this;
}

inline rdf::Uri::~Uri() noexcept
{
  delete_resource();
}

inline librdf_uri* rdf::Uri::get() noexcept
{
  return value;
}

inline librdf_uri* rdf::Uri::release() noexcept
{
  auto v {value};
  value = nullptr;
  return v;
}

inline void rdf::Uri::delete_resource() noexcept
{
  if (value) {
    librdf_free_uri(value);
    value = nullptr;
  }
}

inline rdf::Uri rdf::new_uri(librdf_world* w, const char* uri)
{
  return Uri {librdf_new_uri(w, reinterpret_cast<const unsigned char*>(uri))};
}

inline rdf::Storage::Storage(librdf_storage* v) noexcept
  : value {v}
{
}

inline rdf::Storage::Storage(Storage&& rhs) noexcept
  : value {rhs.release()}
{
}

inline rdf::Storage& rdf::Storage::operator=(Storage&& rhs) noexcept
{
  delete_resource();
  value = rhs.release();
  return *this;
}

inline rdf::Storage::~Storage() noexcept
{
  delete_resource();
}

inline librdf_storage* rdf::Storage::get() noexcept
{
  return value;
}

inline librdf_storage* rdf::Storage::release() noexcept
{
  auto v {value};
  value = nullptr;
  return v;
}

inline void rdf::Storage::delete_resource() noexcept
{
  if (value) {
    librdf_free_storage(value);
    value = nullptr;
  }
}

inline rdf::Storage rdf::new_storage(
  librdf_world* w,
  const char* storage_name,
  const char* name,
  const char* options_string)
{
  return Storage {librdf_new_storage(w, storage_name, name, options_string)};
}

inline rdf::Model::Model(librdf_model* v) noexcept
  : value {v}
{
}

inline rdf::Model::Model(Model&& rhs) noexcept
  : value {rhs.release()}
{
}

inline rdf::Model& rdf::Model::operator=(Model&& rhs) noexcept
{
  delete_resource();
  value = rhs.release();
  return *this;
}

inline rdf::Model::~Model() noexcept
{
  delete_resource();
}

inline librdf_model* rdf::Model::get() noexcept
{
  return value;
}

inline librdf_model* rdf::Model::release() noexcept
{
  auto v {value};
  value = nullptr;
  return v;
}

inline void rdf::Model::delete_resource() noexcept
{
  if (value) {
    librdf_free_model(value);
    value = nullptr;
  }
}

inline rdf::Model rdf::new_model(
  librdf_world* w,
  librdf_storage* s,
  const char* options_string)
{
  return Model {librdf_new_model(w, s, options_string)};
}

inline rdf::Parser::Parser(librdf_parser* v) noexcept
  : value {v}
{
}

inline rdf::Parser::Parser(Parser&& rhs) noexcept
  : value {rhs.release()}
{
}

inline rdf::Parser& rdf::Parser::operator=(Parser&& rhs) noexcept
{
  delete_resource();
  value = rhs.release();
  return *this;
}

inline rdf::Parser::~Parser() noexcept
{
  delete_resource();
}

inline librdf_parser* rdf::Parser::get() noexcept
{
  return value;
}

inline librdf_parser* rdf::Parser::release() noexcept
{
  auto v {value};
  value = nullptr;
  return v;
}

inline void rdf::Parser::delete_resource() noexcept
{
  if (value) {
    librdf_free_parser(value);
    value = nullptr;
  }
}

inline rdf::Parser rdf::new_parser(
  librdf_world* w,
  const char* name,
  const char* mine_type,
  librdf_uri* type_uri)
{
  return Parser {librdf_new_parser(w, name, mine_type, type_uri)};
}

inline rdf::Statement::Statement(librdf_statement* v) noexcept
  : value {v}
{
}

inline rdf::Statement::Statement(Statement&& rhs) noexcept
  : value {rhs.release()}
{
}

inline rdf::Statement& rdf::Statement::operator=(Statement&& rhs) noexcept
{
  delete_resource();
  value = rhs.release();
  return *this;
}

inline rdf::Statement::~Statement() noexcept
{
  delete_resource();
}

inline librdf_statement* rdf::Statement::get() noexcept
{
  return value;
}

inline librdf_statement* rdf::Statement::release() noexcept
{
  auto v {value};
  value = nullptr;
  return v;
}

inline void rdf::Statement::delete_resource() noexcept
{
  if (value) {
    librdf_free_statement(value);
    value = nullptr;
  }
}

inline rdf::Statement rdf::new_statement(librdf_world* w)
{
  return Statement {librdf_new_statement(w)};
}

inline rdf::Statement rdf::new_statement(
  librdf_world* w,
  librdf_node* subject,
  librdf_node* predicate,
  librdf_node* object)
{
  return Statement {librdf_new_statement_from_nodes(w, subject, predicate, object)};
}

inline rdf::Stream::Stream(librdf_stream* v) noexcept
  : value {v}
{
}

inline rdf::Stream::Stream(Stream&& rhs) noexcept
  : value {rhs.release()}
{
}

inline rdf::Stream& rdf::Stream::operator=(Stream&& rhs) noexcept
{
  delete_resource();
  value = rhs.release();
  return *this;
}

inline rdf::Stream::~Stream() noexcept
{
  delete_resource();
}

inline librdf_stream* rdf::Stream::get() noexcept
{
  return value;
}

inline librdf_stream* rdf::Stream::release() noexcept
{
  auto v {value};
  value = nullptr;
  return v;
}

inline void rdf::Stream::delete_resource() noexcept
{
  if (value) {
    librdf_free_stream(value);
    value = nullptr;
  }
}

inline rdf::Stream rdf::find_statements(librdf_model* m, librdf_statement* s)
{
  return Stream {librdf_model_find_statements(m, s)};
}

inline rdf::Iterator::Iterator(librdf_iterator* v) noexcept
  : value {v}
{
}

inline rdf::Iterator::Iterator(Iterator&& rhs) noexcept
  : value {rhs.release()}
{
}

inline rdf::Iterator& rdf::Iterator::operator=(Iterator&& rhs) noexcept
{
  delete_resource();
  value = rhs.release();
  return *this;
}

inline rdf::Iterator::~Iterator() noexcept
{
  delete_resource();
}

inline librdf_iterator* rdf::Iterator::get() noexcept
{
  return value;
}

inline librdf_iterator* rdf::Iterator::release() noexcept
{
  auto v {value};
  value = nullptr;
  return v;
}

inline void rdf::Iterator::delete_resource() noexcept
{
  if (value) {
    librdf_free_iterator(value);
    value = nullptr;
  }
}

rdf::Iterator rdf::get_targets(librdf_model* m, librdf_node* source, librdf_node* arc)
{
  return Iterator {librdf_model_get_targets(m, source, arc)};
}

inline raptor_world* rdf::raptor::get_raptor(librdf_world* p) noexcept
{
  return librdf_world_get_raptor(p);
}

inline rdf::raptor::Iostream::Iostream(raptor_iostream* v) noexcept
  : value {v}
{
}

inline rdf::raptor::Iostream::Iostream(Iostream&& rhs) noexcept
  : value {rhs.release()}
{
}

inline rdf::raptor::Iostream& rdf::raptor::Iostream::operator=(Iostream&& rhs) noexcept
{
  delete_resource();
  value = rhs.release();
  return *this;
}

inline rdf::raptor::Iostream::~Iostream() noexcept
{
  delete_resource();
}

inline raptor_iostream* rdf::raptor::Iostream::get() noexcept
{
  return value;
}

inline raptor_iostream* rdf::raptor::Iostream::release() noexcept
{
  auto v {value};
  value = nullptr;
  return v;
}

inline void rdf::raptor::Iostream::delete_resource() noexcept
{
  if (value) {
    raptor_free_iostream(value);
    value = nullptr;
  }
}

inline rdf::raptor::Iostream rdf::raptor::new_iostream(
  raptor_world* w,
  std::FILE* handle)
{
  return Iostream {raptor_new_iostream_to_file_handle(w, handle)};
}

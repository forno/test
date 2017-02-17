#ifndef XMAHO_XMAHO_TRAITS_TYPE_ALIAS_H
#define XMAHO_XMAHO_TRAITS_TYPE_ALIAS_H

/**
 * @file traits/type_alias.hpp
 * @brief This have some convertion to **_t from **::type.
 */

#include <type_traits>

namespace xmaho
{
namespace traits
{

/**
 * @brief remove_const_t for c++11.
 */
template<typename T>
using remove_const_t = typename std::remove_const<T>::type;

}
}

#endif

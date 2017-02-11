#ifndef XMAHO_XMAHO_TRAITS_ENABLE_IF_H
#define XMAHO_XMAHO_TRAITS_ENABLE_IF_H

/**
 * @file traits/enable_if.hpp
 * @brief This have definition of xmaho::traits::Enable_if.
 */

#include <type_traits>

namespace xmaho
{
namespace traits
{

/**
 * @brief The syntactic suger of `std::enable_if::type`.
 */
template<bool B, typename T = void>
using Enable_if = typename std::enable_if<B, T>::type;

}
}

#endif

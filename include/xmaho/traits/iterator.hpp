#ifndef XMAHO_XMAHO_TRAITS_ITERATOR_H
#define XMAHO_XMAHO_TRAITS_ITERATOR_H

/**
 * @file traits/iterator.hpp
 * @brief This have syntactic sugar from iterator_traits.
 */

#include <iterator>

namespace xmaho
{
namespace traits
{

/**
 * @brief syntactic sugar of std::iterator_traits::value_type.
 */
template<typename T>
using Value_type = typename std::iterator_traits<T>::value_type;

}
}

#endif

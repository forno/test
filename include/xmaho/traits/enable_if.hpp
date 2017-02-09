#ifndef XMAHO_XMAHO_TRAITS_ENABLE_IF_H
#define XMAHO_XMAHO_TRAITS_ENABLE_IF_H

#include <type_traits>

namespace xmaho
{
namespace traits
{

/**
 * \brief The syntactic suger of std::enable_if<B,T>::type
 */
template<bool B, typename T>
using Enable_if = typename std::enable_if<B, T>::type;

}
}

#endif

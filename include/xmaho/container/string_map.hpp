#ifndef XMAHO_XMAHO_CONTAINER_STRING_MAP_H
#define XMAHO_XMAHO_CONTAINER_STRING_MAP_H

/**
 * @file container/string_map.hpp
 * @brief This have definition of xmaho::container::string_map
 */

#include <unordered_map>

namespace xmaho
{
namespace container
{

/**
 * \brief Speedy string map.
 *
 * This is unordered map.
 */
template<typename T>
using string_map = std::unordered_map<std::string, T>;

}
}

#endif

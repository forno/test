#ifndef XMAHO_XMAHO_CONTAINER_H
#define XMAHO_XMAHO_CONTAINER_H

#include <unordered_map>

namespace xmaho
{
namespace container
{

/**
 * \brief Speedy string map.
 *
 * This is unorderd map.
 */
template<typename T>
using StringMap = std::unordered_map<std::string, T>;
}
}

#endif

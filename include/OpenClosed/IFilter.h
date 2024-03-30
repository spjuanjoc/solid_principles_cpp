/**
 * @file IFilter.h
 *
 * @brief Declaration of the filter interface.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef FILTER_H
#define FILTER_H

#include <vector>

namespace OpenClosed
{

// Forward declarations
template <typename T>
struct Specification;

struct Product;

/**
 * @brief The Filter interface.
 *
 * @tparam Type The type of filter.
 */
template <typename Type>
class IFilter
{
public:
  virtual ~IFilter() = default;

  virtual std::vector<Type*> filter(std::vector<Type*> items, Specification<Type>& spec) = 0;
};

}  // namespace OpenClosed

#endif  //FILTER_H

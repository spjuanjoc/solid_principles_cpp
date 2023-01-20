/**
 * @file .h
 *
 * @brief Declaration of the  class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#include "OpenClosed/Filter.h"

#include "OpenClosed/Specification.h"

namespace OpenClosed
{

std::vector<Product*>
BetterFilter::filter(std::vector<Product*> items, Specification<Product>& spec)
{
  {
    std::vector<Product*> result;
    for (auto& p : items)
      if (spec.isSatisfied(p))
        result.push_back(p);
    return result;
  }
}

}  // namespace OpenClosed

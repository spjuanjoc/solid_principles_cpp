/**
 * @file ProductFilter.cpp
 *
 * @brief Definition of the product filter class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#include "OpenClosed/ProductFilter.h"

#include "OpenClosed/IFilter.h"
#include "OpenClosed/Specification.h"

namespace OpenClosed
{

std::vector<Product*>
ProductFilter::filter(std::vector<Product*> items, Specification<Product>& spec)
{
  {
    std::vector<Product*> result;

    for (auto& item : items)
    {
      if (spec.isSatisfied(item))
      {
        result.push_back(item);
      }
    }
    return result;
  }
}

}  // namespace OpenClosed

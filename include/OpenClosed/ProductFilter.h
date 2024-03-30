/**
 * @file ProductFilter.h
 *
 * @brief Declaration of the product filter class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef PRODUCTFILTER_H
#define PRODUCTFILTER_H

#include "IFilter.h"

#include <vector>

namespace OpenClosed
{

// Forward declarations
template <typename T>
struct Specification;

struct Product;

/**
 * @brief The product filter.
 */
class ProductFilter : public virtual IFilter<Product>
{
public:
  std::vector<Product*> filter(std::vector<Product*> items, Specification<Product>& spec) override;
};

}  // namespace OpenClosed

#endif  //PRODUCTFILTER_H

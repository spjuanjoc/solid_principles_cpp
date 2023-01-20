/**
 * @file .h
 *
 * @brief Declaration of the  class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef FILTER_H
#define FILTER_H

#include <vector>

namespace OpenClosed
{


/// Fwd declarations
template <typename T>
struct Specification;

struct Product;

/// Filter interface
template <typename T>
class Filter
{
public:
  virtual ~Filter() = default;

  virtual std::vector<T*> filter(std::vector<T*> items, Specification<T>& spec) = 0;
};

/// Filter implementation
class BetterFilter : public virtual Filter<Product>
{
public:

  std::vector<Product*> filter(std::vector<Product*> items, Specification<Product>& spec) override;
};

}  // namespace OpenClosed

#endif  //FILTER_H

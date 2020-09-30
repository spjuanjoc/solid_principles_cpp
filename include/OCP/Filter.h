//
// Created by juan.castellanos on 10/01/20.
//

#ifndef FILTER_H
#define FILTER_H

#include <vector>

/// Fwd declarations
template<typename T>
struct Specification;

struct Product;

/// Filter interface
template<typename T>
struct Filter
{
  virtual std::vector<T*> filter(std::vector<T*> items, Specification<T>& spec) = 0;
};

/// Filter implementation
struct BetterFilter : Filter<Product>
{
  std::vector<Product*> filter(std::vector<Product*> items, Specification<Product>& spec) override;
};

#endif  //FILTER_H

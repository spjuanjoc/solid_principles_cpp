//
// Created by juan.castellanos on 10/01/20.
//

#include "Specification.h"
#include "Product.h"

bool ColorSpecification::is_satisfied(Product* item)
{
  return item->color == _color;
}

bool SizeSpecification::is_satisfied(Product* item)
{
  return item->size == _size;
}

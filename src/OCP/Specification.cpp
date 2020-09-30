//
// Created by juan.castellanos on 10/01/20.
//

#include "OCP/Specification.h"
#include "OCP/Product.h"

bool ColorSpecification::is_satisfied(Product* item)
{
  return item->color == _color;
}

bool SizeSpecification::is_satisfied(Product* item)
{
  return item->size == _size;
}

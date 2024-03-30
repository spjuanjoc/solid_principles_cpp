/**
 * @file Specification.cpp
 *
 * @brief Definition of the specification classes.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#include "OpenClosed/Specification.h"

#include "OpenClosed/Product.h"

namespace OpenClosed
{

bool
ColorSpecification::isSatisfied(Product* item)
{
  return item->color == m_color;
}

bool
SizeSpecification::isSatisfied(Product* item)
{
  return item->size == m_size;
}

}  // namespace OpenClosed

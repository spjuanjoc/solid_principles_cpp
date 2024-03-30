/**
 * @file Product.h
 *
 * @brief Declaration of the Product class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

namespace OpenClosed
{

// Forward declarations
template <typename Type>
struct Specification;

enum class Color
{
  Red,
  Green,
  Blue
};

enum class Size
{
  Small,
  Medium,
  Large
};

struct Product
{
  std::string name;
  Color       color;
  Size        size;
};

}  // namespace OpenClosed

#endif  //PRODUCT_H

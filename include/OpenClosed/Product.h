/**
 * @file .h
 *
 * @brief Declaration of the  class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

namespace OpenClosed
{


template <typename T>
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

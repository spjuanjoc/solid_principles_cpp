/**
 * @file .cpp
 *
 * @brief Declaration of the  class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#include "LiskovSubstitution/Shape.h"

namespace LiskovSubstitution
{

int
Shape::get_width() const
{
  return m_width;
}

void
Shape::setWidth(const int& width)
{
  this->m_width = width;
}

int
Shape::getHeight() const
{
  return m_height;
}

void
Shape::setHeight(const int& height)
{
  this->m_height = height;
}

int
Shape::area() const
{
  return m_width * m_height;
}

bool
Shape::isSquare() const
{
  return m_width == m_height;
}

Shape
RectangleFactory::createRectangle(int width, int height)
{
  return Shape(width, height);
}

Shape
RectangleFactory::createSquare(int size)
{
  return Shape(size, size);
}

}  // namespace LiskovSubstitution

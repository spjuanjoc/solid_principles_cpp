/**
 * @file Shape.cpp
 *
 * @brief Declaration of the Shape class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#include "LiskovSubstitution/Shape.h"

#include <cassert>

namespace LiskovSubstitution
{

std::uint32_t
Shape::getWidth() const
{
  return m_width;
}

void
Shape::setWidth(const std::uint32_t& width)
{
  this->m_width = width;
}

std::uint32_t
Shape::getHeight() const
{
  return m_height;
}

void
Shape::setHeight(const std::uint32_t& height)
{
  this->m_height = height;
}

std::uint32_t
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
RectangleFactory::createRectangle(std::uint32_t width, std::uint32_t height)
{
  assert(width > 0);
  assert(height > 0);

  return { width, height };
}

Shape
RectangleFactory::createSquare(std::uint32_t size)
{
  assert(size > 0);

  return { size, size };
}

}  // namespace LiskovSubstitution

/**
 * @file Shape.h
 *
 * @brief Declaration of the Shape class for the Liskov Substitution Principle.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <cstdint>

namespace LiskovSubstitution
{


class Shape
{
public:
  Shape(const std::uint32_t width, const std::uint32_t height)
  : m_width{ width }
  , m_height{ height }
  {
  }

  virtual ~Shape() = default;

  virtual void setWidth(const std::uint32_t& width);

  virtual void setHeight(const std::uint32_t& height);

  std::uint32_t getWidth() const;

  std::uint32_t getHeight() const;

  std::uint32_t area() const;

  bool isSquare() const;

protected:
  std::uint32_t m_width;
  std::uint32_t m_height;
};

class RectangleFactory
{
public:
  static Shape createRectangle(std::uint32_t width, std::uint32_t height);
  static Shape createSquare(std::uint32_t size);
};

}  // namespace LiskovSubstitution

#endif  //SHAPE_H

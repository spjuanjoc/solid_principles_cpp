/**
 * @file .h
 *
 * @brief Declaration of the  class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

namespace LiskovSubstitution
{


class Shape
{
public:
  Shape(const int width, const int height)
  : m_width{ width }
  , m_height{ height }
  {
  }

  virtual ~Shape() = default;

  virtual void setWidth(const int& width);

  virtual void setHeight(const int& height);

  int get_width() const;

  int getHeight() const;

  int area() const;

  bool isSquare() const;

protected:
  int m_width;
  int m_height;
};

class RectangleFactory
{
public:
  static Shape createRectangle(int width, int height);
  static Shape createSquare(int size);
};

}  // namespace LiskovSubstitution

#endif  //RECTANGLE_H

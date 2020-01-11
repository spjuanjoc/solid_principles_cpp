//
// Created by juan.castellanos on 10/01/20.
//

#include "LSP/Rectangle.h"

int Rectangle::get_width() const
{
  return _width;
}
void Rectangle::set_width(const int& width)
{
  this->_width = width;
}
int Rectangle::get_height() const
{
  return _height;
}
void Rectangle::set_height(const int& height)
{
  this->_height = height;
}
int Rectangle::area() const
{
  return _width * _height;
}
bool Rectangle::is_square() const
{
  return _width == _height;
}

Rectangle RectangleFactory::create_rectangle(int width, int height)
{
  return Rectangle(width, height);
}
Rectangle RectangleFactory::create_square(int size)
{
  return Rectangle(size, size);
}

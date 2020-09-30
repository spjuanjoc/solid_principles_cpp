//
// Created by juan.castellanos on 10/01/20.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
protected:
  int _width, _height;

public:
  Rectangle(const int width, const int height) : _width{ width }, _height{ height }
  {
  }

  int          get_width() const;
  virtual void set_width(const int& width);
  int          get_height() const;
  virtual void set_height(const int& height);
  int          area() const;
  bool         is_square() const;
};

struct RectangleFactory
{
  static Rectangle create_rectangle(int width, int height);
  static Rectangle create_square(int size);
};

#endif  //RECTANGLE_H

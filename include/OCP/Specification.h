//
// Created by juan.castellanos on 10/01/20.
//

#ifndef SPECIFICATION_H
#define SPECIFICATION_H

enum class Color;
enum class Size;
struct Product;

/// Specification interface
template<typename T>
struct Specification
{
  virtual bool is_satisfied(T* item) = 0;
};

/// Specification implementation for Color
struct ColorSpecification : Specification<Product>
{
  Color _color;

  explicit ColorSpecification(const Color color) : _color{ color }
  {
  }

  bool is_satisfied(Product* item) override;
};

/// Specification implementation for Size
struct SizeSpecification : Specification<Product>
{
  Size _size;

  explicit SizeSpecification(const Size size) : _size{ size }
  {
  }

  bool is_satisfied(Product* item) override;
};

/// Composite Specification implementation for AND
template<typename T>
struct AndSpecification : Specification<T>
{
  Specification<T>& first;
  Specification<T>& second;

  AndSpecification(Specification<T>& first, Specification<T>& second)
    : first{ first }, second{ second }
  {
  }

  bool is_satisfied(T* item) override
  {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }
};

#endif  //SPECIFICATION_H

/**
 * @file .h
 *
 * @brief Declaration of the  class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef SPECIFICATION_H
#define SPECIFICATION_H

namespace OpenClosed
{

enum class Color;
enum class Size;
struct Product;

/// Specification interface
template <typename T>
class Specification
{
public:
  virtual ~Specification() = default;

  virtual bool isSatisfied(T* item) = 0;
};

/// Specification implementation for Color
class ColorSpecification : public virtual Specification<Product>
{
public:
  explicit ColorSpecification(const Color color)
  : m_color{ color }
  {
  }

  bool isSatisfied(Product* item) override;

private:
  Color m_color;
};

/// Specification implementation for Size
class SizeSpecification : public virtual Specification<Product>
{
public:
  explicit SizeSpecification(const Size size)
  : m_size{ size }
  {
  }

  bool isSatisfied(Product* item) override;

private:
  Size m_size;
};

/// Composite Specification implementation for AND
template <typename T>
class AndSpecification : public virtual Specification<T>
{
public:
  AndSpecification(Specification<T>& first, Specification<T>& second)
  : m_first{ first }
  , m_second{ second }
  {
  }

  bool isSatisfied(T* item) override { return m_first.isSatisfied(item) && m_second.isSatisfied(item); }

private:
  Specification<T>& m_first;
  Specification<T>& m_second;
};

}  // namespace OpenClosed

#endif  //SPECIFICATION_H

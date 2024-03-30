/**
 * @file Specification.h
 *
 * @brief Declaration of the Specification classes for the Open-Closed Principle.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef SPECIFICATION_H
#define SPECIFICATION_H

namespace OpenClosed
{

// Forward declarations
enum class Color;
enum class Size;
struct Product;

/**
 * @brief Filter specification interface.
 *
 * @tparam Type The type of the filter.
 */
template <typename Type>
class Specification
{
public:
  virtual ~Specification() = default;

  virtual bool isSatisfied(Type* item) = 0;
};

/**
 * @brief Filter specification implementation for the color of a product.
 */
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

/**
 * @brief Filter specification implementation for the size of a product.
 */
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

/**
 * @brief Composite filter Specification implementation for the AND operation.
 *
 * @tparam Type The type of the specification.
 */
template <typename Type>
class AndSpecification : public virtual Specification<Type>
{
public:
  AndSpecification(Specification<Type>& first, Specification<Type>& second)
  : m_first{ first }
  , m_second{ second }
  {
  }

  bool isSatisfied(Type* item) override { return m_first.isSatisfied(item) && m_second.isSatisfied(item); }

private:
  Specification<Type>& m_first;
  Specification<Type>& m_second;
};

}  // namespace OpenClosed

#endif  //SPECIFICATION_H

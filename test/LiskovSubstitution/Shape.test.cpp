/**
* @file .test.cpp
*
* @brief Implementation of the unit tests for the .
*
* @author spjuanjoc
* @date   2023-01-19
*/

#include "LiskovSubstitution/Shape.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;
using namespace LiskovSubstitution;

/**
 * @brief Liskov Substitution Principle.
 *
 * square is different from rectangle. Factory instead
 */
TEST(LSPTests, ispdrawObjects_rectangles_objectsPoints)
{
  // Arrange

  Shape square    = RectangleFactory::createSquare(5);
  Shape rectangle = RectangleFactory::createRectangle(2, 3);

  if (rectangle.isSquare())
  {
    std::cout << "rectangle is square\n";
  }
  else
  {
    std::cout << "rectangle is not square\n";
  }
  if (square.isSquare())
  {
    std::cout << "square is square\n";
  }
  else
  {
    std::cout << "square is not square\n";
  }

  std::cout << "Square size is: " << square.getHeight() << "\n";
  std::cout << "Square area is: " << square.area() << "\n";
  std::cout << "Shape height is: " << rectangle.getHeight() << "\n";
  std::cout << "Shape width is: " << rectangle.get_width() << "\n";
  rectangle.setWidth(4);
  std::cout << "Shape new width is: " << rectangle.get_width() << "\n";
  rectangle.setHeight(6);
  std::cout << "Shape new height is: " << rectangle.getHeight() << "\n";

  //  // Arrange
  //  EXPECT_THAT(actual_pets, ContainerEq(expected_pets)) << "all pets must match";
}

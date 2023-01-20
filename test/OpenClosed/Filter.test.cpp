/**
* @file .test.cpp
*
* @brief Implementation of the unit tests for the .
*
* @author spjuanjoc
* @date   2023-01-19
*/


#include "OpenClosed/Filter.h"
#include "OpenClosed/Product.h"
#include "OpenClosed/Specification.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;
using namespace OpenClosed;

/**
 * @brief Open-Closed Principle.
 *
 * DB Filter specific search
 */
TEST(FilterTests, ispdrawObjects_rectangles_objectsPoints)
{
  // Arrange
  Product apple{ "Apple", Color::Green, Size::Small };
  Product tree{ "Tree", Color::Green, Size::Large };
  Product house{ "House", Color::Blue, Size::Large };

  std::vector<Product*> products{ &apple, &tree, &house };

  BetterFilter filter;

  ColorSpecification color(Color::Green);

  auto green_things = filter.filter(products, color);

  for (auto& x : green_things)
  {
    std::cout << x->name << " is color\n";
  }

  std::cout << "OpenClosed with composite specification\n";

  //  ColorSpecification        color(Color::Green);
  SizeSpecification         large(Size::Large);
  AndSpecification<Product> green_and_large{ large, color };

  auto big_green_things = filter.filter(products, green_and_large);

  for (auto& x : big_green_things)
  {
    std::cout << x->name << " is large and color\n";
  }
  // Tree is large and color

  //  // Arrange
  //  EXPECT_THAT(actual_pets, ContainerEq(expected_pets)) << "products pets must match";
}

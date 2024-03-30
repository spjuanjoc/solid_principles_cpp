/**
* @file Filter.test.cpp
*
* @brief Implementation of the unit tests for the Open-Closed Principle.
*
* @author spjuanjoc
* @date   2023-01-19
*/


#include "OpenClosed/IFilter.h"
#include "OpenClosed/Product.h"
#include "OpenClosed/ProductFilter.h"
#include "OpenClosed/Specification.h"

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

using namespace testing;
using namespace OpenClosed;

TEST(FilterTests, createProducts_filterByColor_isGreen)
{
  // Arrange
  Product               apple{ "Apple", Color::Green, Size::Small };
  Product               tree{ "Tree", Color::Green, Size::Large };
  Product               house{ "House", Color::Blue, Size::Large };
  std::vector<Product*> products{ &apple, &tree, &house };
  ProductFilter         filter;
  ColorSpecification    color(Color::Green);

  // Act
  const auto green_things = filter.filter(products, color);

  // Assert
  for (auto& thing : green_things)
  {
    EXPECT_THAT(thing->color, Eq(Color::Green));
  }
}

// Composite specification
TEST(FilterTests, createProducts_filterByColorAndSize_isGreenAndLarge)
{
  // Arrange
  Product                   apple{ "Apple", Color::Red, Size::Small };
  Product                   tree{ "Tree", Color::Green, Size::Large };
  Product                   house{ "House", Color::Blue, Size::Medium };
  std::vector<Product*>     products{ &apple, &tree, &house };
  ProductFilter             filter;
  ColorSpecification        color(Color::Green);
  SizeSpecification         large(Size::Large);
  AndSpecification<Product> green_and_large{ large, color };

  // Act
  const auto big_green_things = filter.filter(products, green_and_large);

  // Assert
  for (auto& thing : big_green_things)
  {
    EXPECT_THAT(thing->color, Eq(Color::Green));
    EXPECT_THAT(thing->size, Eq(Size::Large));
  }
}

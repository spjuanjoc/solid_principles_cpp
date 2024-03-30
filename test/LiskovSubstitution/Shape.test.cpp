/**
* @file Shape.test.cpp
*
* @brief Implementation of the unit tests for the Liskov Substitution Principle.
*
* @author spjuanjoc
* @date   2023-01-19
*/

#include "LiskovSubstitution/Shape.h"

#include <gmock/gmock-matchers.h>
#include <gmock/gmock-more-matchers.h>
#include <gtest/gtest.h>

using namespace testing;
using namespace LiskovSubstitution;

TEST(LSPTests, squareIsNotRectangle)
{
  // Arrange
  Shape square    = RectangleFactory::createSquare(5);
  Shape rectangle = RectangleFactory::createRectangle(2, 3);

  // Act & Assert
  EXPECT_THAT(square.isSquare(), IsTrue());
  EXPECT_THAT(rectangle.isSquare(), IsFalse());
}

TEST(LSPTests, createSquare_getSizes_matches)
{
  // Arrange
  Shape square = RectangleFactory::createSquare(5);

  // Act & Assert
  EXPECT_THAT(square.getHeight(), Eq(5));
  EXPECT_THAT(square.area(), Eq(25));
}

TEST(LSPTests, createRectangle_getSizes_Resized)
{
  // Arrange
  Shape rectangle = RectangleFactory::createRectangle(2, 3);

  // Act & Assert
  EXPECT_THAT(rectangle.getWidth(), Eq(2));
  EXPECT_THAT(rectangle.getHeight(), Eq(3));

  rectangle.setWidth(4);
  rectangle.setHeight(6);
  EXPECT_THAT(rectangle.getWidth(), Eq(4));
  EXPECT_THAT(rectangle.getHeight(), Eq(6));
}

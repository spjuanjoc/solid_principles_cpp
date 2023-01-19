/**
* @file CarMaker.test.cpp
*
* @brief Implementation of the unit tests for the CarMaker.
*
* @author spjuanjoc
* @date   2023-01-19
*/

#include "DependencyInversion/CarReport/CarMaker.h"
#include "DependencyInversion/CarReport/Engine.h"
#include "DependencyInversion/CarReport/Logger/ConsoleLogger.h"
#include "DependencyInversion/CarReport/Reporting/LogReporter.h"

#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace DependencyInversion;
using namespace testing;

/**
 * @brief Dependency Inversion Principle.
 *
 * Related to Dependency injection
 * Report logger: depend on interfaces
 */
TEST(CarMakerTests, drawObjects_rectangles_objectsPoints)
{
  // Arrange
  std::shared_ptr<ConsoleLogger> logger = std::make_shared<ConsoleLogger>();
  std::unique_ptr<Engine>        engine = std::make_unique<Engine>();
  LogReporter                    reporter(*logger);

  // Act
  std::shared_ptr<CarMaker> car = std::make_shared<CarMaker>(std::move(engine), logger);
  reporter.prepareReport();
  logger->writeEntry("writeEntry");

  //  // Arrange
  //  const auto rectangle2 = std::make_shared<DrawableRectangle>(3, 3, 6, 6);
  //  const auto rectangle1 = std::make_shared<DrawableRectangle>(0, 0, 10, 10);
  //  const std::vector<std::shared_ptr<IDrawableObject>> objects{ rectangle1, rectangle2 };
  //
  //  // Act
  //  for (const auto& object : objects)
  //  {
  //    for (const auto& line : *object)
  //    {
  //      const LineToPointAdapter adapter{ line };
  //      const PixelsDrawer       drawer;
  //      draw2dPoints(drawer, adapter.begin(), adapter.end());
  //      std::cout << "+\n";
  //    }
  //  }

  // Assert
  //  EXPECT_THAT(builder.getPet(0), Eq(expected_pets[0])) << "first pet name must match";
  //  EXPECT_THAT(actual_pets, ContainerEq(expected_pets)) << "all pets must match";
}

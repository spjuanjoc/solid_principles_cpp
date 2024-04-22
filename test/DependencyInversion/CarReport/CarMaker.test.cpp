/**
* @file CarMaker.test.cpp
*
* @brief Implementation of the unit tests for the CarMaker for the Dependency Inversion Principle.
*
* @author spjuanjoc
* @date   2023-01-19
*/

#include "DependencyInversion/CarReport/CarMaker.h"

#include "DependencyInversion/CarReport/Engine.h"
#include "DependencyInversion/CarReport/Logger/ConsoleLogger.h"
#include "DependencyInversion/CarReport/Reporting/LogReporter.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace DependencyInversion;
using namespace testing;

TEST(CarMakerTests, drawObjects_rectangles_objectsPoints)
{
  // Arrange
  std::shared_ptr<ConsoleLogger> logger = std::make_shared<ConsoleLogger>();
  std::unique_ptr<Engine>        engine = std::make_unique<Engine>();
  LogReporter                    reporter(*logger);

  // Act
  std::shared_ptr<CarMaker> car = std::make_shared<CarMaker>(std::move(engine), logger);
  reporter.prepareReport();

  // Assert
  EXPECT_THAT(logger->getNumberOfEntries(), Gt(0));
}

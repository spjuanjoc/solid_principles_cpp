/**
* @file RelationshipsReport.test.cpp
*
* @brief Implementation of the unit tests for the RelationshipsReport.
*
* @author spjuanjoc
* @date   2023-01-19
*/

#include "DependencyInversion/RelationshipReport/RelationshipsMaker.h"

#include <iostream>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace DependencyInversion;
using namespace testing;

/**
 * @brief Dependency Inversion Principle.
 *
 * Related to Dependency injection
 * RelationshipsMaker: Depend on abstractions
 */
TEST(RelationshipsMakerTests, sdrawObjects_rectangles_objectsPoints)
{
  // Arrange
  const Person parent{ "Jane" };
  const Person child1{ "Chris" };
  const Person child2{ "Matt" };

  RelationshipsMaker relationships;
  relationships.addParentAndChild(parent, child1);
  relationships.addParentAndChild(parent, child2);

  RelationshipsReporter reporter(relationships);

  reporter.report(parent);

  // Assert
  //  EXPECT_THAT(builder.getPet(0), Eq(expected_pets[0])) << "first pet name must match";
  //  EXPECT_THAT(actual_pets, ContainerEq(expected_pets)) << "all pets must match";
}

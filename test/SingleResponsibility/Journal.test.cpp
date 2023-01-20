/**
* @file .test.cpp
*
* @brief Implementation of the unit tests for the .
*
* @author spjuanjoc
* @date   2023-01-19
*/

#include "SingleResponsibility/Journal.h"

#include "SingleResponsibility/PersistenceManager.hpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;
using namespace SingleResponsibility;

/// \brief Single Responsibility Principle.
/// \example Journal & save_file

/**
 * @brief
 *
 * DB Filter specific search
 */
TEST(JournalTests, ispdrawObjects_rectangles_objectsPoints)
{
  // Arrange

  std::cout << "SingleResponsibility: Single Responsibility Principle\n";

  Journal journal{"My Diary"};
  journal.addEntry("Dear Diary");
  journal.addEntry("I cried today");
  journal.addEntry("I ate a bug");

  PersistenceManager::save(journal, "../Journal.txt");
  PersistenceManager::read("../Journal.txt");

  std::cout << "End SingleResponsibility\n";

  //  // Arrange
  //  EXPECT_THAT(actual_pets, ContainerEq(expected_pets)) << "products pets must match";
}

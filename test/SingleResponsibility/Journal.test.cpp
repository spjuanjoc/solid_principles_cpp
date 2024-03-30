/**
* @file Journal.test.cpp
*
* @brief Implementation of the unit tests for the Single Responsibility Principle.
*
* @author spjuanjoc
* @date   2023-01-19
*/

#include "SingleResponsibility/Journal.h"

#include "SingleResponsibility/PersistenceManager.hpp"

#include <gmock/gmock-matchers.h>
#include <gmock/gmock-more-matchers.h>
#include <gtest/gtest.h>

using namespace testing;
using namespace SingleResponsibility;

TEST(JournalTests, createJournal_addEntries_isSaved)
{
  // Arrange
  const std::string filename{ "../Journal.txt" };
  Journal           journal{ "My Diary" };

  // Act
  journal.addEntry("Dear Diary");
  journal.addEntry("I cried today");
  journal.addEntry("I ate a bug");

  PersistenceManager::save(journal, filename);
  const auto file = PersistenceManager::read(filename);

  // Assert
  EXPECT_THAT(file, Not(IsEmpty()));
}

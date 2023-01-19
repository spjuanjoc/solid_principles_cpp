/**
 * @file main.test.cpp
 *
 * @brief The entry point for the unit tests.
 *
 * @author spjuanjoc
 * @date   2020-09-02
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>

int
main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  testing::InitGoogleMock(&argc, argv);

  return RUN_ALL_TESTS();
}

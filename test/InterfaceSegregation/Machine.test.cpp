/**
* @file Machine.test.cpp
*
* @brief Implementation of the unit tests for the Interface Segregation Principle.
*
* @author spjuanjoc
* @date   2023-01-19
*/

#include "InterfaceSegregation/MultifunctionPrinter/Machine.h"

#include "InterfaceSegregation/MultifunctionPrinter/Fax.h"
#include "InterfaceSegregation/MultifunctionPrinter/Printer.h"
#include "InterfaceSegregation/MultifunctionPrinter/Scanner.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;
using namespace InterfaceSegregation;

TEST(PrinterTests, createMachines_printScanSend_Success)
{
  // Arrange
  std::vector<Document*> documents{};
  auto                   printer1 = std::make_unique<Printer>();
  auto                   scanner1 = std::make_unique<Scanner>();
  auto                   fax1     = std::make_unique<Fax>();

  // Act
  printer1->print(documents);
  scanner1->scan(documents);
  fax1->send(documents);

  // Assert
  EXPECT_THAT(printer1->hasPrinted(), IsTrue());
  EXPECT_THAT(scanner1->hasScanned(), IsTrue());
  EXPECT_THAT(fax1->wasSent(), IsTrue());
}

TEST(PrinterTests, createMachines_dontPrintScanSend_Success)
{
  // Arrange
  std::vector<Document*> documents{};
  auto                   printer1 = std::make_unique<Printer>();
  auto                   scanner1 = std::make_unique<Scanner>();
  auto                   fax1     = std::make_unique<Fax>();

  // Act & Assert
  EXPECT_THAT(printer1->hasPrinted(), IsFalse());
  EXPECT_THAT(scanner1->hasScanned(), IsFalse());
  EXPECT_THAT(fax1->wasSent(), IsFalse());
}

TEST(PrinterTests, createMachine_printScanSend_Success)
{
  // Arrange
  std::vector<Document*> documents{};
  auto                   printer1 = std::make_unique<Printer>();
  auto                   scanner1 = std::make_unique<Scanner>();
  auto                   fax1     = std::make_unique<Fax>();
  Machine                machine1(*printer1, *scanner1, *fax1);

  // Act
  machine1.print(documents);
  machine1.scan(documents);
  machine1.send(documents);

  // Assert
  EXPECT_THAT(machine1.hasPrinted(), IsTrue());
  EXPECT_THAT(machine1.hasScanned(), IsTrue());
  EXPECT_THAT(machine1.wasSent(), IsTrue());
}

TEST(PrinterTests, createMachine_dontPrintScanSend_Success)
{
  // Arrange
  std::vector<Document*> documents{};
  auto                   printer1 = std::make_unique<Printer>();
  auto                   scanner1 = std::make_unique<Scanner>();
  auto                   fax1     = std::make_unique<Fax>();
  Machine                machine1(*printer1, *scanner1, *fax1);

  // Act & Assert
  EXPECT_THAT(machine1.hasPrinted(), IsFalse());
  EXPECT_THAT(machine1.hasScanned(), IsFalse());
  EXPECT_THAT(machine1.wasSent(), IsFalse());
}

/**
* @file .test.cpp
*
* @brief Implementation of the unit tests for the .
*
* @author spjuanjoc
* @date   2023-01-19
*/

#include "InterfaceSegregation/MultifunctionPrinter/Fax.h"
#include "InterfaceSegregation/MultifunctionPrinter/Machine.h"
#include "InterfaceSegregation/MultifunctionPrinter/Printer.h"
#include "InterfaceSegregation/MultifunctionPrinter/Scanner.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace testing;
using namespace InterfaceSegregation;

/**
 * @brief Interface Segregation Principle.
 *
 * Multifunction printer: an interface for each component
 */
TEST(MultifunctionPrinterMachineTests, ispdrawObjects_rectangles_objectsPoints)
{
  // Arrange
  std::cout << "InterfaceSegregation Interface Segregation Principle\n";

  std::vector<Document*> documents{};
  Printer*               printer1 = new Printer();
  Printer                printer2;
  Scanner*               scanner1 = new Scanner();
  Scanner                scanner2;
  Fax*                   fax1 = new Fax();
  Fax                    fax2;
  Machine                machine1(*printer1, *scanner1, *fax1);
  Machine                machine2(printer2, scanner2, fax2);
  Machine*               machine3 = new Machine(*printer1, *scanner1, *fax1);


  // Act
  printer1->print(documents);
  printer2.print(documents);

  scanner1->scan(documents);
  scanner2.scan(documents);

  fax1->send(documents);
  fax2.send(documents);

  machine1.print(documents);
  machine1.scan(documents);
  machine1.send(documents);

  machine2.print(documents);
  machine2.scan(documents);
  machine2.send(documents);

  machine3->print(documents);

  //  // Arrange
  //  EXPECT_THAT(actual_pets, ContainerEq(expected_pets)) << "all pets must match";
}

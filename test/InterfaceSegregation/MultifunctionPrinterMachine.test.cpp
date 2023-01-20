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

/**
 * @brief Interface Segregation Principle.
 *
 * Multifunction printer: an interface for each component
 */
TEST(MultifunctionPrinterMachineTests, ispdrawObjects_rectangles_objectsPoints)
{
  // Arrange

  /// \brief Interface Segregation Principle.
  /// \example Multifunction printer: interface for each
  using namespace InterfaceSegregation;
  std::cout << "InterfaceSegregation Interface Segregation Principle\n";

  Printer*               p = new Printer();
  Printer                p2;
  std::vector<Document*> docs{};
  p->print(docs);
  p2.print(docs);

  Scanner* s = new Scanner();
  Scanner  s2;
  s->scan(docs);
  s2.scan(docs);

  Fax* f = new Fax();
  Fax  f2;
  f->send(docs);
  f2.send(docs);

  Machine m(*p, *s, *f);
  m.print(docs);
  m.scan(docs);
  m.send(docs);

  Machine m2(p2, s2, f2);
  m2.print(docs);
  m2.scan(docs);
  m2.send(docs);

  Machine* m3 = new Machine(*p, *s, *f);
  m3->print(docs);

  std::cout << "End InterfaceSegregation\n";
  // Act

  //  // Arrange
  //  EXPECT_THAT(actual_pets, ContainerEq(expected_pets)) << "all pets must match";
}

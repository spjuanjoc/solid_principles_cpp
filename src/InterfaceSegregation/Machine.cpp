/**
 * @file .h
 *
 * @brief Declaration of the  class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#include "InterfaceSegregation/MultifunctionPrinter/Machine.h"

namespace InterfaceSegregation
{

void
Machine::print(std::vector<Document*> documents)
{
  m_printer.print(documents);
}

void
Machine::scan(std::vector<Document*> documents)
{
  m_scanner.scan(documents);
}

void
Machine::send(std::vector<Document*> documents)
{
  m_fax.send(documents);
}

}  // namespace InterfaceSegregation

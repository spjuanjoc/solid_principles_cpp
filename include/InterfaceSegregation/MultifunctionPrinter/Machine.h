/**
 * @file Machine.h
 *
 * @brief Declaration of the Machine class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef MACHINE_H
#define MACHINE_H

#include "../Document.h"
#include "IMachine.h"

namespace InterfaceSegregation
{


class Machine : public virtual IMachine
{
public:
  Machine(IPrinter& printer, IScanner& scanner, IFax& fax)
  : m_printer{ printer }
  , m_scanner{ scanner }
  , m_fax{ fax }
  {
  }

  void print(std::vector<Document*> documents) override;
  void scan(std::vector<Document*> documents) override;
  void send(std::vector<Document*> documents) override;
  bool hasPrinted() override;
  bool hasScanned() override;
  bool wasSent() override;

private:
  IPrinter& m_printer;
  IScanner& m_scanner;
  IFax&     m_fax;
};

}  // namespace InterfaceSegregation

#endif  //MACHINE_H

//
// Created by juan.castellanos on 10/01/20.
//

#ifndef MACHINE_H
#define MACHINE_H

#include "Document.h"
#include "IMachine.h"

struct Machine : IMachine
{
  IPrinter& _printer;
  IScanner& _scanner;
  IFax&     _fax;

  Machine(IPrinter& printer, IScanner& scanner, IFax& fax)
    : _printer{ printer }, _scanner{ scanner }, _fax{ fax }
  {
  }

  void print(std::vector<Document*> docs) override;
  void scan(std::vector<Document*> docs) override;
  void fax(std::vector<Document*> docs) override;
};
#endif  //MACHINE_H

/**
 * @file Printer.h
 *
 * @brief Declaration of the Printer class for the Interface Segregation Principle.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef PRINTER_H
#define PRINTER_H

#include "IPrinter.h"

#include <iostream>

namespace InterfaceSegregation
{

class Document;

class Printer : public virtual IPrinter
{
public:
  void print([[maybe_unused]] std::vector<Document*> documents) override { has_printed = true; };
  bool hasPrinted() override { return has_printed; };
};

}  // namespace InterfaceSegregation

#endif  //PRINTER_H

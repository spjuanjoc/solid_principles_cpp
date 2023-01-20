/**
 * @file .h
 *
 * @brief Declaration of the  class.
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

  void print(std::vector<Document*> docs) override { std::cout << "Print\n"; };
};

}  // namespace InterfaceSegregation

#endif  //PRINTER_H

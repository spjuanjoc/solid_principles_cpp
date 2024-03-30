/**
 * @file Scanner.h
 *
 * @brief Declaration of the scanner class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef SCANNER_H
#define SCANNER_H

#include "IScanner.h"

#include <iostream>
#include <vector>

namespace InterfaceSegregation
{

class Scanner : public virtual IScanner
{
public:
  void scan([[maybe_unused]] std::vector<Document*> documents) override { has_scanned = true; };
};

}  // namespace InterfaceSegregation

#endif  //SCANNER_H

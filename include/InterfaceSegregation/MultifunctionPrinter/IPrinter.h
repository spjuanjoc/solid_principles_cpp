/**
 * @file IPrinter.h
 *
 * @brief Declaration of the IPrinter interface.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef IPRINTER_H
#define IPRINTER_H

#include <vector>

namespace InterfaceSegregation
{

// Forward declarations
class Document;

class IPrinter
{
public:
  virtual ~IPrinter() = default;

  virtual void print(std::vector<Document*> docs) = 0;
  virtual bool hasPrinted() = 0;

protected:
  bool has_printed{ false };
};

}  // namespace InterfaceSegregation

#endif  //IPRINTER_H

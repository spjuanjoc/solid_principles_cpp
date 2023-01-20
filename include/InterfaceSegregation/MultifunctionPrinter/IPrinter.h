/**
 * @file .h
 *
 * @brief Declaration of the  class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef IPRINTER_H
#define IPRINTER_H

#include <vector>

namespace InterfaceSegregation
{

class Document;

class IPrinter
{
public:
  virtual ~IPrinter() = default;

  virtual void print(std::vector<Document*> docs) = 0;
};

}  // namespace InterfaceSegregation

#endif  //IPRINTER_H

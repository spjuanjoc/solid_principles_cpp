/**
 * @file .h
 *
 * @brief Declaration of the  class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef INTERFACE_SEGREGATION_MULTIFUNCTIONPRINTER_IFAX_H
#define INTERFACE_SEGREGATION_MULTIFUNCTIONPRINTER_IFAX_H

#include <vector>

namespace InterfaceSegregation
{


class Document;

class IFax
{
public:
  virtual ~IFax() = default;

  virtual void send(std::vector<Document*> documents) = 0;
};

}  // namespace InterfaceSegregation

#endif  //INTERFACE_SEGREGATION_MULTIFUNCTIONPRINTER_IFAX_H

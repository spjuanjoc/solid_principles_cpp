/**
 * @file IFax.h
 *
 * @brief Declaration of the IFax interface.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef INTERFACE_SEGREGATION_MULTIFUNCTIONPRINTER_IFAX_H
#define INTERFACE_SEGREGATION_MULTIFUNCTIONPRINTER_IFAX_H

#include <vector>

namespace InterfaceSegregation
{

// Forward declarations
class Document;

class IFax
{
public:
  virtual ~IFax() = default;

  virtual void send(std::vector<Document*> documents) = 0;
  virtual bool wasSent() { return was_sent; };

protected:
  bool was_sent{ false };
};

}  // namespace InterfaceSegregation

#endif  //INTERFACE_SEGREGATION_MULTIFUNCTIONPRINTER_IFAX_H

/**
 * @file Fax.h
 *
 * @brief Declaration of the Fax class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef FAX_H
#define FAX_H

#include "IFax.h"

#include <iostream>
#include <vector>

namespace InterfaceSegregation
{

// Forward declarations
class Document;

class Fax : public virtual IFax
{
public:
  void send(std::vector<Document*> documents) override
  {
    for ([[maybe_unused]] const auto& document : documents)
    {
      //  document.
    }

    was_sent = true;
  };
};

}  // namespace InterfaceSegregation

#endif  //FAX_H

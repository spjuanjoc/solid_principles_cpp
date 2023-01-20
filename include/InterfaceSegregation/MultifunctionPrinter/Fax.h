/**
 * @file .h
 *
 * @brief Declaration of the  class.
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

class Document;

class Fax : public virtual IFax
{
public:
  void send(std::vector<Document*> documents) override
  {
    std::cout << "Sending documents\n";

    for (const auto& document : documents)
    {
//      document.
    }
  };
};

}  // namespace InterfaceSegregation

#endif  //FAX_H

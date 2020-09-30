//
// Created by juan.castellanos on 10/01/20.
//

#ifndef FAX_H
#define FAX_H

#include "IFax.h"
#include <vector>

struct Fax : IFax
{
  void fax(std::vector<Document*> docs) override;
};
#endif  //FAX_H

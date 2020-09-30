//
// Created by juan.castellanos on 10/01/20.
//

#ifndef SCANNER_H
#define SCANNER_H

#include "IScanner.h"
#include <vector>

struct Scanner : IScanner
{
  void scan(std::vector<Document*> docs) override;
};

#endif  //SCANNER_H

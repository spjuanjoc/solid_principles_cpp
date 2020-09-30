//
// Created by juan.castellanos on 10/01/20.
//

#ifndef IPRINTER_H
#define IPRINTER_H

#include <vector>

class Document;

struct IPrinter
{
  virtual void print(std::vector<Document*> docs) = 0;
};

#endif  //IPRINTER_H

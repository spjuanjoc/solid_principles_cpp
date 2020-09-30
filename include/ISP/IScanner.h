//
// Created by juan.castellanos on 10/01/20.
//

#ifndef ISCANNER_H
#define ISCANNER_H

#include <vector>

class Document;

struct IScanner
{
  virtual void scan(std::vector<Document*> docs) = 0;
};


#endif  //ISCANNER_H

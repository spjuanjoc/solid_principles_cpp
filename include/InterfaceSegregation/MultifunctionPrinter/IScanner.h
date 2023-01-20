//
// Created by juan.castellanos on 10/01/20.
//

#ifndef ISCANNER_H
#define ISCANNER_H

#include <vector>

namespace InterfaceSegregation
{

class Document;

class IScanner
{
public:
  virtual ~IScanner() = default;

  virtual void scan(std::vector<Document*> docs) = 0;
};

}  // namespace InterfaceSegregation

#endif  //ISCANNER_H

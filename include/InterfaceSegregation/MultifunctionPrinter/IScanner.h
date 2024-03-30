/**
 * @file IScanner.h
 *
 * @brief Declaration of the IScanner interface.
 *
 * @author spjuanjoc
 * @date   2020-01-10
 */

#ifndef ISCANNER_H
#define ISCANNER_H

#include <vector>

namespace InterfaceSegregation
{

// Forward declarations
class Document;

class IScanner
{
public:
  virtual ~IScanner() = default;

  virtual void scan(std::vector<Document*> docs) = 0;
  virtual bool hasScanned() { return has_scanned; };

protected:
  bool has_scanned{ false };
};

}  // namespace InterfaceSegregation

#endif  //ISCANNER_H

/**
 * @file .h
 *
 * @brief Declaration of the  class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef IMACHINE_H
#define IMACHINE_H

#include "IFax.h"
#include "IPrinter.h"
#include "IScanner.h"

namespace InterfaceSegregation
{


class IMachine : public IPrinter, public IScanner, public IFax
{
public:
  ~IMachine() = default;
};

}  // namespace InterfaceSegregation

#endif  //IMACHINE_H

//
// Created by juan.castellanos on 10/01/20.
//

#ifndef IMACHINE_H
#define IMACHINE_H

#include "IFax.h"
#include "IPrinter.h"
#include "IScanner.h"

struct IMachine : IPrinter, IScanner, IFax
{
};

#endif  //IMACHINE_H

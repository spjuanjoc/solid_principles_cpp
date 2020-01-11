//
// Created by juan.castellanos on 10/01/20.
//

#ifndef DESIGN_PATTERNS_CPP_REPORTING_H
#define DESIGN_PATTERNS_CPP_REPORTING_H

#include "ILogger.h"

class Reporting
{
  /*const*/ ILogger& _logger;

public:
  explicit Reporting(/*const*/ ILogger& logger) : _logger{ logger }
  {
  }

  void prepare_report();
};


#endif  //DESIGN_PATTERNS_CPP_REPORTING_H

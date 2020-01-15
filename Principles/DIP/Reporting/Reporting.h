//
// Created by juan.castellanos on 10/01/20.
//

#ifndef REPORTING_H
#define REPORTING_H

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


#endif  //REPORTING_H

//
// Created by juan.castellanos on 10/01/20.
//

#ifndef DESIGN_PATTERNS_CPP_ILOGGER_H
#define DESIGN_PATTERNS_CPP_ILOGGER_H

#include <string>

struct ILogger
{
  virtual ~ILogger() = default;

  virtual void Log(const std::string& s) = 0;
};

#endif  //DESIGN_PATTERNS_CPP_ILOGGER_H

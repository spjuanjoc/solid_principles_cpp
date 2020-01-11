//
// Created by juan.castellanos on 10/01/20.
//

#ifndef DESIGN_PATTERNS_CPP_CONSOLELOGGER_H
#define DESIGN_PATTERNS_CPP_CONSOLELOGGER_H

#include "ILogger.h"
#include <iostream>
#include <string>

struct ConsoleLogger : ILogger
{
  ConsoleLogger() = default;

  void Log(const std::string& s) override;
};

#endif  //DESIGN_PATTERNS_CPP_CONSOLELOGGER_H

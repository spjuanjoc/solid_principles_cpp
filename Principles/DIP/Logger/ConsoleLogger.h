//
// Created by juan.castellanos on 10/01/20.
//

#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "ILogger.h"
#include <iostream>
#include <string>

struct ConsoleLogger : ILogger
{
  ConsoleLogger() = default;

  void Log(const std::string& s) override;
};

#endif  //CONSOLELOGGER_H

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
  ConsoleLogger() /*{ puts("ConsoleLogger ctor"); }*/= default;
  ~ConsoleLogger() override /*{ puts("ConsoleLogger dtor"); }*/= default;
  ConsoleLogger(const ConsoleLogger&) = default; //{ puts("ConsoleLogger copy ctor"); }
  ConsoleLogger(ConsoleLogger&&) = default; //noexcept { puts("ConsoleLogger move ctor"); }
  ConsoleLogger& operator=(const ConsoleLogger&) = default;
  ConsoleLogger& operator=(ConsoleLogger&&) = default;

  void Log(const std::string& s) override;
};

#endif  //CONSOLELOGGER_H

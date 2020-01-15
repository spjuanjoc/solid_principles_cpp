//
// Created by juan.castellanos on 10/01/20.
//

#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>

struct ILogger
{
  virtual ~ILogger() = default;

  virtual void Log(const std::string& s) = 0;
};

#endif  //ILOGGER_H

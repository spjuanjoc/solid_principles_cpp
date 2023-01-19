/**
 * @file ILogger.h
 *
 * @brief Declaration of the ILogger interface.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef DEPENDENCY_INVERSION_LOGGER_ILOGGER_H
#define DEPENDENCY_INVERSION_LOGGER_ILOGGER_H

#include <string>

namespace DependencyInversion
{

class ILogger
{
public:
  virtual ~ILogger() = default;

  virtual void writeEntry(const std::string& message) = 0;

protected:
  ILogger()                          = default;
  ILogger(const ILogger&)            = default;
  ILogger(ILogger&&)                 = default;
  ILogger& operator=(const ILogger&) = default;
  ILogger& operator=(ILogger&&)      = default;
};

}  // namespace DependencyInversion

#endif  //DEPENDENCY_INVERSION_LOGGER_ILOGGER_H

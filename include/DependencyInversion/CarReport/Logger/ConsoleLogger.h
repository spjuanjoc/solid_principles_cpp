/**
 * @file ConsoleLogger.h
 *
 * @brief Declaration of the ConsoleLogger class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef DEPENDENCY_INVERSION_LOGGER_CONSOLELOGGER_H
#define DEPENDENCY_INVERSION_LOGGER_CONSOLELOGGER_H

#include "ILogger.h"

#include <string>

namespace DependencyInversion
{

class ConsoleLogger : public virtual ILogger
{
public:
  ConsoleLogger()                                = default;
  ~ConsoleLogger() override                      = default;
  ConsoleLogger(const ConsoleLogger&)            = default;
  ConsoleLogger(ConsoleLogger&&)                 = default;
  ConsoleLogger& operator=(const ConsoleLogger&) = default;
  ConsoleLogger& operator=(ConsoleLogger&&)      = default;

  void writeEntry(const std::string& message) override;
  static std::uint32_t getNumberOfEntries();

private:
  static std::uint32_t s_number_of_entries;
};

}  // namespace DependencyInversion

#endif  //DEPENDENCY_INVERSION_LOGGER_CONSOLELOGGER_H

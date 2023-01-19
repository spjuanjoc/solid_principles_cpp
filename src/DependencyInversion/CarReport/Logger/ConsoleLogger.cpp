/**
 * @file ConsoleLogger.cpp
 *
 * @brief Implementation of the ConsoleLogger class.
 *
 * @author  spjuanjoc
 * @date    2020-01-20
 */

#include "DependencyInversion/CarReport/Logger/ConsoleLogger.h"

namespace DependencyInversion
{

void
ConsoleLogger::writeEntry(const std::string& message)
{
  std::cout << "LOG: " << message.c_str() << '\n';
}

}  // namespace DependencyInversion

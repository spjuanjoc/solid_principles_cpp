/**
 * @file ConsoleLogger.cpp
 *
 * @brief Implementation of the ConsoleLogger class.
 *
 * @author  spjuanjoc
 * @date    2020-01-20
 */

#include "DependencyInversion/CarReport/Logger/ConsoleLogger.h"

//#include <iostream>

namespace DependencyInversion
{

std::uint32_t ConsoleLogger::s_number_of_entries = 0;

void
ConsoleLogger::writeEntry([[maybe_unused]] const std::string& message)
{
  //  std::cout << "LOG: " << message.c_str() << '\n';
  ++s_number_of_entries;
}

std::uint32_t
ConsoleLogger::getNumberOfEntries()
{
  return s_number_of_entries;
}

}  // namespace DependencyInversion

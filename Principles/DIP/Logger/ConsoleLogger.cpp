//
// Created by juan.castellanos on 10/01/20.
//

#include "ConsoleLogger.h"

void ConsoleLogger::Log(const std::string& s)
{
  std::cout << "LOG: " << s.c_str() << std::endl;
}

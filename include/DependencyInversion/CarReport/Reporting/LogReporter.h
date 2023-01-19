/**
 * @file LogReporter.h
 *
 * @brief Declaration of the LogReporter class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef DEPENDENCY_INVERSION_REPORTING_LOGREPORTER_H
#define DEPENDENCY_INVERSION_REPORTING_LOGREPORTER_H

#include "DependencyInversion/CarReport/Logger/ILogger.h"

namespace DependencyInversion
{

class LogReporter
{
public:
  explicit LogReporter(ILogger& logger)
  : m_logger{ logger }
  {
  }

  void prepareReport();

private:
  /*const*/ ILogger& m_logger;
};

}  // namespace DependencyInversion

#endif  //DEPENDENCY_INVERSION_REPORTING_LOGREPORTER_H

/**
 * @file LogReporter.cpp
 *
 * @brief Implementation of the LogReporter class.
 *
 * @author  spjuanjoc
 * @date    2020-01-20
 */

#include "DependencyInversion/CarReport/Reporting/LogReporter.h"

namespace DependencyInversion
{

void
LogReporter::prepareReport()
{
  m_logger.writeEntry("Preparing the report");
}

}  // namespace DependencyInversion

/**
 * @file CarMaker.cpp
 *
 * @brief Implementation of the CarMaker class.
 *
 * @author  spjuanjoc
 * @date    2020-01-20
 */

#include "DependencyInversion/CarReport/CarMaker.h"

#include "DependencyInversion/CarReport//Engine.h"
#include "DependencyInversion/CarReport/Logger/ILogger.h"

namespace DependencyInversion
{

CarMaker::CarMaker(std::unique_ptr<Engine> engine, const std::shared_ptr<ILogger>& logger)
: m_engine{ std::move(engine) }
, m_logger{ logger }
{
  logger->writeEntry("making a car");
}

std::ostream&
operator<<(std::ostream& stream, const CarMaker& car_maker)
{
  return stream << "car with engine: " << *car_maker.m_engine;
}

}  // namespace DependencyInversion

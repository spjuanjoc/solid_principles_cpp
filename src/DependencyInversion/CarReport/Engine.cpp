/**
 * @file Engine.cpp
 *
 * @brief Implementation of the Engine class.
 *
 * @author  spjuanjoc
 * @date    2020-01-20
 */

#include "DependencyInversion/CarReport/Engine.h"

namespace DependencyInversion
{

std::ostream&
operator<<(std::ostream& stream, const Engine& engine)
{
  return stream << "volume: " << engine.m_volume << " horse_power: " << engine.m_horse_power;
}

}  // namespace DependencyInversion

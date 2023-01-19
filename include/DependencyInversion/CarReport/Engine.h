/**
 * @file Engine.h
 *
 * @brief Declaration of the Engine class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef DEPENDENCY_INVERSION_ENGINE_H
#define DEPENDENCY_INVERSION_ENGINE_H

#include <ostream>

namespace DependencyInversion
{

class Engine
{
public:
  friend std::ostream& operator<<(std::ostream& stream, const Engine& engine);

private:
  float m_volume{ 5 };
  int   m_horse_power{ 400 };

};

}  // namespace DependencyInversion

#endif  //DEPENDENCY_INVERSION_ENGINE_H

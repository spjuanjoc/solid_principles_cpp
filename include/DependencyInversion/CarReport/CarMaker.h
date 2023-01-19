/**
 * @file CarMaker.h
 *
 * @brief Declaration of the CarMaker class.
 *
 * @author  spjuanjoc
 * @date    2020-01-10
 */

#ifndef DEPENDENCY_INVERSION_CAR_H
#define DEPENDENCY_INVERSION_CAR_H

#include <memory>

namespace DependencyInversion
{

class Engine;
class ILogger;

class CarMaker
{
public:
  CarMaker(std::unique_ptr<Engine> engine, const std::shared_ptr<ILogger>& logger);

  friend std::ostream& operator<<(std::ostream& stream, const CarMaker& car_maker);

private:
  std::unique_ptr<Engine>  m_engine;
  std::shared_ptr<ILogger> m_logger;
};

}  // namespace DependencyInversion

#endif  //DEPENDENCY_INVERSION_CAR_H

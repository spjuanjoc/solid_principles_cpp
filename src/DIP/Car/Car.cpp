//
// Created by juan.castellanos on 10/01/20.
//

#include "DIP/Car/Car.h"
#include "DIP/Car/Engine.h"
#include "DIP/Logger/ILogger.h"

Car::Car(std::unique_ptr<Engine> engine, const std::shared_ptr<ILogger>& logger)
  : engine{ move(engine) }, logger{ logger }
{
  logger->Log("making a car");
}

std::ostream& operator<<(std::ostream& os, const Car& obj)
{
  return os << "car with engine: " << *obj.engine;
}

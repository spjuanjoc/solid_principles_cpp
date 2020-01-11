//
// Created by juan.castellanos on 10/01/20.
//

#ifndef CAR_H
#define CAR_H

#include "ILogger.h"
#include <memory>

struct Engine;
struct ILogger;

struct Car
{
  std::unique_ptr<Engine>  engine;
  std::shared_ptr<ILogger> logger;

  Car(std::unique_ptr<Engine> engine, const std::shared_ptr<ILogger>& logger);

  friend std::ostream& operator<<(std::ostream& os, const Car& obj);
};


#endif  //CAR_H

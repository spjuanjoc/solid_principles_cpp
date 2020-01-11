//
// Created by juan.castellanos on 10/01/20.
//

#include "Engine.h"

std::ostream& operator<<(std::ostream& os, const Engine& obj)
{
  return os << "volume: " << obj.volume << " horse_power: " << obj.horse_power;
}
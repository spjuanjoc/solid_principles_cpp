//
// Created by juan.castellanos on 10/01/20.
//

#ifndef ENGINE_H
#define ENGINE_H

#include <ostream>

struct Engine
{
  float volume      = 5;
  int   horse_power = 400;

  friend std::ostream& operator<<(std::ostream& os, const Engine& obj);
};

#endif  //ENGINE_H

//
// Created by juan.castellanos on 10/01/20.
//

#include "SingleResponsibility/Journal.h"
#include "SingleResponsibility/PersistenceManager.hpp"

namespace SingleResponsibility
{

void
Journal::addEntry(const std::string& entry)
{
  static int count = 1;
  m_entries.push_back(std::to_string(count++) + ": " + entry);
}

std::vector<std::string>
Journal::getEntries() const
{
  return m_entries;
}

}

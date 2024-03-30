/**
 * @file Journal.cpp
 *
 * @brief Definition of the journal creation for the Single Responsibility Principle.
 *
 * @author spjuanjoc
 * @date   2020-01-10
 */

#include "SingleResponsibility/Journal.h"

namespace SingleResponsibility
{

void
Journal::addEntry(const std::string& entry)
{
  static std::int32_t count = 1;
  m_entries.push_back(std::to_string(count++) + ": " + entry);
}

std::vector<std::string>
Journal::getEntries() const
{
  return m_entries;
}

}  // namespace SingleResponsibility

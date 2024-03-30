/**
 * @file Journal.h
 *
 * @brief Declaration of the journal creation for the Single Responsibility Principle.
 *
 * @author spjuanjoc
 * @date   2020-01-10
 */

#ifndef JOURNAL_H
#define JOURNAL_H

#include <string>
#include <utility>
#include <vector>

namespace SingleResponsibility
{

class Journal
{
public:
  explicit Journal(std::string title)
  : m_title{ std::move(title) }
  {
  }

  void addEntry(const std::string& entry);

  std::vector<std::string> getEntries() const;

private:
  std::string              m_title;
  std::vector<std::string> m_entries;
};

}  // namespace SingleResponsibility

#endif  //JOURNAL_H

//
// Created by juan.castellanos on 10/01/20.
//

#ifndef JOURNAL_H
#define JOURNAL_H

#include <iostream>
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

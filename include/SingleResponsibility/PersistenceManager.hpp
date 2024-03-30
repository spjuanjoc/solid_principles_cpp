/**
 * @file PersistenceManager.h
 *
 * @brief Declaration of the manager for the file persistence for the Single Responsibility Principle.
 *
 * @author spjuanjoc
 * @date   2020-01-10
 */

#ifndef PERSISTENCEMANAGER_H
#define PERSISTENCEMANAGER_H

#include <fstream>
#include <iostream>

namespace SingleResponsibility
{


struct PersistenceManager
{
  static void save(const Journal& journal, const std::string& filename)
  {
    std::ofstream file_stream(filename);

    for (const auto& entry : journal.getEntries())
    {
      file_stream << entry << '\n';
    }
  }

  static std::vector<std::string> read(const std::string& filename)
  {
    std::ifstream            file_stream(filename);
    std::vector<std::string> file;
    std::string              line;

    while (std::getline(file_stream, line))
    {
      file.emplace_back(line);
    }

    return file;
  }
};

}  // namespace SingleResponsibility

#endif  //PERSISTENCEMANAGER_H

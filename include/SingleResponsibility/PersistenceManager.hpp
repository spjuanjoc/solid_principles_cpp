//
// Created by juan.castellanos on 10/01/20.
//

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
      file_stream << entry << std::endl;
    }
  }

  static void read(const std::string& filename)
  {
    std::ifstream file_stream(filename);
    std::string   line;
    //    std::string word;

    while (std::getline(file_stream, line))
    {
      //      file_stream >> word;
      std::cout << line << "\n";
    }
  }
};

}  // namespace SingleResponsibility

#endif  //PERSISTENCEMANAGER_H

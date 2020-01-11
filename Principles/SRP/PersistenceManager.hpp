//
// Created by juan.castellanos on 10/01/20.
//

#ifndef PERSISTENCEMANAGER_H
#define PERSISTENCEMANAGER_H

#include <fstream>
#include <iostream>

using std::endl;
using std::ifstream;
using std::ofstream;

struct PersistenceManager
{
  static void save(const Journal& journal, const string& filename)
  {
    ofstream ofs(filename);
    for (auto& s : journal.entries)
    {
      ofs << s << endl;
    }
  }
  static void read(const string& filename)
  {
    ifstream    ifs(filename);
    std::string line;
//    std::string word;
    while (std::getline(ifs, line))
    {
//      ifs >> word;
      std::cout << line << "\n";
    }
  }
};

#endif  //PERSISTENCEMANAGER_H

#include "DependencyInversion/CarReport/CarMaker.h"
#include "DependencyInversion/CarReport/Engine.h"
#include "OCP/Filter.h"
#include "OCP/Product.h"
#include "OCP/Specification.h"
#include "SRP/Journal.h"
#include "SRP/PersistenceManager.hpp"

#include <iostream>

/// \brief Single Responsibility Principle.
/// \example Journal & save_file
void SrpExample()
{
  std::cout << "SRP: Single Responsibility Principle\n";

  Journal journal{"My Diary"};
  journal.add("Dear Diary");
  journal.add("I cried today");
  journal.add("I ate a bug");

  PersistenceManager::save(journal, "../Journal.txt");
  PersistenceManager::read("../Journal.txt");

  std::cout << "End SRP\n";
}

/// \brief Open-Closed Principle.
/// \example DB Filter specific search
void OcpExample()
{
  std::cout << "OCP: Open-Closed Principle\n";

  Product apple{"Apple", Color::Green, Size::Small};
  Product tree{"Tree", Color::Green, Size::Large};
  Product house{"House", Color::Blue, Size::Large};

  vector<Product*> all{&apple, &tree, &house};

  BetterFilter bf;

  ColorSpecification green(Color::Green);

  auto green_things = bf.filter(all, green);
  for (auto& x : green_things)
  {
    std::cout << x->name << " is green" << endl;
  }

  std::cout << "OCP with composite specification\n";

  //  ColorSpecification        green(Color::Green);
  SizeSpecification         large(Size::Large);
  AndSpecification<Product> green_and_large{large, green};

  auto big_green_things = bf.filter(all, green_and_large);
  for (auto& x : big_green_things)
  {
    std::cout << x->name << " is large and green" << endl;
  }

  // Tree is large and green
  std::cout << "End OCP\n";
}





int main()
{
  std::cout << "Hello, Design patterns\n";

  SrpExample();
  std::cout << "\n";
  OcpExample();

  return 0;
}

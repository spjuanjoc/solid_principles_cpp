#include "DIP/Car/Car.h"
#include "DIP/Car/Engine.h"
#include "DIP/Reporting/Reporting.h"
#include "ISP/Fax.h"
#include "ISP/Machine.h"
#include "ISP/Printer.h"
#include "ISP/Scanner.h"
#include "LSP/Rectangle.h"
#include "OCP/Filter.h"
#include "OCP/Product.h"
#include "OCP/Specification.h"
#include "SRP/Journal.h"
#include "SRP/PersistenceManager.hpp"
#include <DIP/Logger/ConsoleLogger.h>
#include <iostream>

/// Single Responsibility Principle
void SrpExample()
{
  std::cout << "SRP: Single Responsibility Principle\n";

  Journal journal{ "My Diary" };
  journal.add("Dear Diary");
  journal.add("I cried today");
  journal.add("I ate a bug");

  PersistenceManager::save(journal, "../Journal.txt");
  PersistenceManager::read("../Journal.txt");

  std::cout << "End SRP\n";
}

/// Open-Closed Principle
void OcpExample()
{
  std::cout << "OCP: Open-Closed Principle\n";

  Product apple{ "Apple", Color::Green, Size::Small };
  Product tree{ "Tree", Color::Green, Size::Large };
  Product house{ "House", Color::Blue, Size::Large };

  vector<Product*> all{ &apple, &tree, &house };

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
  AndSpecification<Product> green_and_large{ large, green };

  auto big_green_things = bf.filter(all, green_and_large);
  for (auto& x : big_green_things)
  {
    std::cout << x->name << " is large and green" << endl;
  }

  // Tree is large and green
  std::cout << "End OCP\n";
}

/// Liskov Substitution Principle
void LspExample()
{
  std::cout << "LSP Liskov Substitution Principle\n";

  Rectangle square    = RectangleFactory::create_square(5);
  Rectangle rectangle = RectangleFactory::create_rectangle(2, 3);

  if (rectangle.is_square())
  {
    std::cout << "rectangle is square\n";
  }
  else
  {
    std::cout << "rectangle is not square\n";
  }
  if (square.is_square())
  {
    std::cout << "square is square\n";
  }
  else
  {
    std::cout << "square is not square\n";
  }

  std::cout << "Square size is: " << square.get_height() << "\n";
  std::cout << "Square area is: " << square.area() << "\n";
  std::cout << "Rectangle height is: " << rectangle.get_height() << "\n";
  std::cout << "Rectangle width is: " << rectangle.get_width() << "\n";
  rectangle.set_width(4);
  std::cout << "Rectangle new width is: " << rectangle.get_width() << "\n";
  rectangle.set_height(6);
  std::cout << "Rectangle new height is: " << rectangle.get_height() << "\n";

  std::cout << "End LSP \n";
}

/// Interface Segregation Principle
void IspExample()
{
  std::cout << "ISP Interface Segregation Principle\n";

  Printer*               p = new Printer();
  Printer                p2;
  std::vector<Document*> docs{};
  p->print(docs);
  p2.print(docs);

  Scanner* s = new Scanner();
  Scanner  s2;
  s->scan(docs);
  s2.scan(docs);

  Fax* f = new Fax();
  Fax  f2;
  f->fax(docs);
  f2.fax(docs);

  Machine m(*p, *s, *f);
  m.print(docs);
  m.scan(docs);
  m.fax(docs);

  Machine m2(p2, s2, f2);
  m2.print(docs);
  m2.scan(docs);
  m2.fax(docs);

  Machine* m3 = new Machine(*p, *s, *f);
  m3->print(docs);

  std::cout << "End ISP\n";
}

/// Dependency Inversion Principle
/// Dependency injection
void DipExample()
{
  std::cout << "DIP Dependency Injection Principle\n";

  std::shared_ptr<ConsoleLogger> logger = std::make_shared<ConsoleLogger>();
  std::unique_ptr<Engine>        engine = std::make_unique<Engine>();

  std::shared_ptr<Car> car = std::make_shared<Car>(std::move(engine), logger);

  Reporting r(*logger);
  r.prepare_report();

  std::cout << "End DIP\n";
}

int main()
{
  std::cout << "Hello, Design patterns\n";

  SrpExample();
  std::cout << "\n";
  OcpExample();
  std::cout << "\n";
  LspExample();
  std::cout << "\n";
  IspExample();
  std::cout << "\n";
  DipExample();

  return 0;
}

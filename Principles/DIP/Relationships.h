//
// Created by juan.castellanos on 24/05/20.
//

#ifndef DIP_RELATIONSHIPS_H
#define DIP_RELATIONSHIPS_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

// A. High-level modules should not depend on low-level modules.
//    Both should depend on abstractions.
// B. Abstractions should not depend on details.
//    Details should depend on abstractions.

enum class Relationship
{
  parent,
  child,
  sibling
};

struct Person
{
  std::string name;
};

struct RelationshipBrowser // Research abstraction
{
  virtual std::vector<Person> find_all_children_of(const std::string& name) = 0;
};

struct Relationships : RelationshipBrowser // low-level module
{
  std::vector<std::tuple<Person, Relationship, Person>> relations;

  void add_parent_and_child(const Person& parent, const Person& child)
  {
    relations.push_back({ parent, Relationship::parent, child });
    relations.push_back({ child, Relationship::child, parent });
  }

  std::vector<Person> find_all_children_of(const std::string& name) override
  {
    std::vector<Person> result;
    for (auto&& [first, rel, second] : relations)
    {
      if (first.name == name && rel == Relationship::parent)
      {
        result.push_back(second);
      }
    }

    return result;
  }
};

struct Research // high-level module
{
  Research(RelationshipBrowser& browser)
  {
    for (auto&& child : browser.find_all_children_of("John"))
    {
      std::cout << "John" << " has a child called " << child.name << '\n';
    }
  }
//  Research(Relationships& rels)  // It works but high-level should NOT depend on low-level!
//  {
//    auto& relations = rels.relations;
//    for (auto&& [first, rel, second] : relations)
//    {
//      if (first.name == "John" && rel == Relationship::parent)
//      {
//        std::cout << first.name << " has a child called " << second.name << '\n';
//      }
//    }
//  }
};

#endif  //DIP_RELATIONSHIPS_H

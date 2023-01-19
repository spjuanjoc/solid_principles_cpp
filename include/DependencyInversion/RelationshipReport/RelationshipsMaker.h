/**
 * @file RelationshipsMaker.h
 *
 * @brief Declaration of the RelationshipsMaker class.
 *
 * @author  spjuanjoc
 * @date    2020-05-24
 */

#ifndef DEPENDENCY_INVERSION_RELATIONSHIPS_H
#define DEPENDENCY_INVERSION_RELATIONSHIPS_H

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

namespace DependencyInversion
{

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

/**
 * @brief
 * RelationshipsReporter abstraction
 */
class IRelationshipBrowser
{
public:
  virtual ~IRelationshipBrowser() = default;

  virtual std::vector<Person> findAllChildrenOf(const Person& person) = 0;
};

/**
 * @brief
 * low-level module
 */
class RelationshipsMaker : public virtual IRelationshipBrowser
{
public:
  void addParentAndChild(const Person& parent, const Person& child)
  {
    m_relationships.push_back({ parent, Relationship::parent, child });
    m_relationships.push_back({ child, Relationship::child, parent });
  }

  std::vector<Person> findAllChildrenOf(const Person& person) override
  {
    std::vector<Person> result;

    for (auto&& [parent, relationship, child] : m_relationships)
    {
      if (parent.name == person.name && relationship == Relationship::parent)
      {
        result.push_back(child);
      }
    }

    return result;
  }

private:
  std::vector<std::tuple<Person, Relationship, Person>> m_relationships;
};

/**
 * @brief
 * high-level module
 */
class RelationshipsReporter
{
public:
  explicit RelationshipsReporter(IRelationshipBrowser& browser)
  : m_browser(browser){};

  void report(const Person& person) const
  {
    for (auto&& child : m_browser.findAllChildrenOf(person))
      std::cout << person.name << " has a child called " << child.name << '\n';
  }

    /*RelationshipsReporter(RelationshipsMaker& relationships)  // It works but high-level should NOT depend on low-level!
    {
      auto& relations = relationships.m_relationships;
      for (auto&& [first, rel, second] : relations)
      {
        if (first.name == "John" && rel == Relationship::parent)
        {
          std::cout << first.name << " has a child called " << second.name << '\n';
        }
      }
    }*/

private:
  IRelationshipBrowser& m_browser;
};

}  // namespace DependencyInversion

#endif  //DEPENDENCY_INVERSION_RELATIONSHIPS_H

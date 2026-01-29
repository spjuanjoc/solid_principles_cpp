# Solid Principles in Cpp

SOLID principles in C++ from the book by Dmitri Nesteruk.
These are five basic principles for object-oriented design to make it more
understandable, flexible, and maintainable.

## SRP: Single Responsibility Principle

- A class should have only one reason for being modified.

e.g. Create a journal and save it to a file.
The way of saving the file shouldn't modify the journal class.

## OCP: Open-Closed Principle

- A class should be open to extension but closed to modification.

e.g. A database filter specific search.

## LSP: Liskov Substitution Principle

- A child class must not alter the behavior of its parent class.
- A parent object could be replaced by a child instance without altering the
  proper behavior of the program.

e.g. A square is not a rectangle.
Use a Factory to create each.

## ISP: Interface Segregation Principle

- Client should not be forced to depend upon interfaces they don't use.
- Multiple client specific interfaces are better than one general purpose
  interface.

e.g. Multifunction printer: An interface for each component.

## DIP: Dependency Inversion Principle

- Depend on abstractions, not on implementations.
- High-level modules should not depend on low-level modules. Both should depend
  on abstractions.
- Abstractions should not depend on details. Details should depend on
  abstractions.

e.g. Report logger: Depend on interfaces.

---

## Requirements

- CMake > 3.24
- A C++20 compliant compiler
- Conan 2.x

## Build

```shell
mkdir build && cd build
cmake .. -DENABLE_TESTS=True -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=/abs/path/to/cmake/conan_provider.cmake -DCMAKE_BUILD_TYPE=Debug
cmake --build .
```

## Test

Run the tests from `./build`:

```shell
cd build
ctest -V
```

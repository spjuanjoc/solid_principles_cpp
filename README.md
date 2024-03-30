# Solid Principles in Cpp

SOLID principles in C++

## SRP: Single Responsibility Principle

Create a journal, and save it to a file.
A class should have only one reason for being modified.


## OCP: Open-Closed Principle

Open to extension, closed to modification.  
Database filter specific search.  


## LSP: Liskov Substitution Principle

A square is not a rectangle.
Use a Factory to create each.

## ISP: Interface Segregation Principle

Multifunction printer: Create an interface for each component.

## DIP: Dependency Inversion Principle

- High-level modules should not depend on low-level modules. Both should depend
  on abstractions.
- Abstractions should not depend on details. Details should depend on
  abstractions.

Example:  
Report logger: Depend on interfaces.

## To compile

Requires:
- CMake
- Conan version lower than 2.0
- A c++20 compliant compiler

When using conan 2.0: [cmake-conan](https://github.com/conan-io/cmake-conan) is
not yet compatible with conan 2.0, before loading the cmake project (to
e.g. `./build`) run:

```bash
conan profile show
conan install . --output-folder=build --build=missing
```

For conan < 2.0:

```bash
mkdir build
cd build
cmake .. -DCMAKE_MODULE_PATH=$PWD -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=True -G Ninja
cmake --build .
```

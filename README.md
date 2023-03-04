# Solid Principles in Cpp

SOLID principles in C++

## SRP: Single Responsibility Principle

Journal & Save File

## OCP: Open-Closed Principle

DB Filter specific search

## LSP: Liskov Substitution Principle

A square is not a rectangle.
Use a Factory to create each.

## ISP: Interface Segregation Principle

Multifunction printer: Create an interface for each component

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
- Conan 2.0
- A c++20 compliant compiler

Since [cmake-conan](https://github.com/conan-io/cmake-conan) is not yet
compatible with conan 2.0, before loading the cmake project (to
e.g. `./build`) run:

    conan profile show
    conan install . --output-folder=build --build=missing

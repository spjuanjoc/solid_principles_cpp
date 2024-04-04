# Solid Principles in Cpp

SOLID principles in C++ from the book by Dmitri Nesteruk.

## SRP: Single Responsibility Principle

A class should have only one reason for being modified.

e.g. Create a journal and save it to a file.
The way of saving the file shouldn't modify the journal class.


## OCP: Open-Closed Principle

A class should be Open to extension but closed to modification.  

e.g. A database filter specific search.  


## LSP: Liskov Substitution Principle

A child class must not alter the behavior of its parent class

e.g. A square is not a rectangle.
Use a Factory to create each.

## ISP: Interface Segregation Principle

Client should not be forced to depend upon interfaces they don't use.

e.g. Multifunction printer: An interface for each component.

## DIP: Dependency Inversion Principle

- High-level modules should not depend on low-level modules. Both should depend
  on abstractions.
- Abstractions should not depend on details. Details should depend on
  abstractions.

e.g. Report logger: Depend on interfaces.

---

## To Build

Requires:
- CMake > 3.15
- Conan < 2.0
- A C++20 compliant compiler

```shell
mkdir build
cd build
cmake .. -DCMAKE_MODULE_PATH=$PWD -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=True -G Ninja
cmake --build .
```

Run the tests from `./build`:

```shell
ctest -V
```

## Notes

When using conan 2.0: [cmake-conan](https://github.com/conan-io/cmake-conan) is
not yet compatible with conan 2.0, before loading the cmake project (to
e.g. `./build`) run:

```shell
conan profile show
conan install . --output-folder=build --build=missing
```

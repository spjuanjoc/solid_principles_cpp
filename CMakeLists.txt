cmake_minimum_required(VERSION 3.15)
project(solid_principles_cpp)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        main.cpp
        Principles/SRP/Journal.h
        Principles/SRP/Journal.cpp
        Principles/OCP/Specification.cpp
        Principles/OCP/Filter.cpp
        Principles/LSP/Rectangle.cpp
        Principles/ISP/Printer.cpp
        Principles/ISP/Scanner.cpp
        Principles/ISP/Fax.cpp
        Principles/ISP/Document.cpp
        Principles/ISP/Machine.cpp
        Principles/DIP/Reporting/Reporting.cpp
        Principles/DIP/Logger/ConsoleLogger.cpp
        Principles/DIP/Car/Engine.cpp
        Principles/DIP/Car/Car.cpp
        )

# To get the headers
include_directories(Principles)
include_directories(Principles/DIP/Logger)

add_executable(${PROJECT_NAME} ${SOURCES})

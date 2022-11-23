cmake_minimum_required(VERSION 3.16.3)

project(HomeWork_CMake)

add_executable(HomeWork_CMake main.cc src/Polynomial.cc)

target_include_directories(HomeWork_CMake PRIVATE "./include")

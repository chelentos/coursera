cmake_minimum_required(VERSION 3.10) #checking CMake version

project(crs) #name of the project

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

include_directories(./includes)

add_library(DataBase ./src/DataBase.cpp)
target_compile_features(DataBase PRIVATE cxx_std_11)

add_executable(db_use ./src/db_use.cpp)

target_link_libraries(db_use DataBase)
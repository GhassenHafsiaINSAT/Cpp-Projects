cmake_minimum_required(VERSION 3.9)

project(MyFirstCMakeProject)

add_executable(calc main.cpp)

install(TARGETS calc DESTINATION bin)
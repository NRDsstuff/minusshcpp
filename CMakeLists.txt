cmake_minimum_required(VERSION 3.0)

project(minusshcpp)

add_executable(minusshcpp main.cpp)

install(TARGETS minusshcpp RUNTIME DESTINATION bin)

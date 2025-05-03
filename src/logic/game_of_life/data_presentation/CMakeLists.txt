cmake_minimum_required(VERSION 3.20)

add_library(datalib rule.cpp cell.cpp)

target_include_directories(datalib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

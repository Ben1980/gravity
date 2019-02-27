cmake_minimum_required(VERSION 3.1...3.13)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(gravity VERSION 0.2.0
    DESCRIPTION "N-Body-Problem project of https://thoughts-on-cpp.com"
    LANGUAGES CXX)

add_library(Catch2 INTERFACE)
target_include_directories(Catch2 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/extern/catch2)

include(CTest)
add_subdirectory(solver solver)
add_subdirectory(solverTest solverTest)

set_property(TARGET solver solverTest PROPERTY CXX_STANDARD 17)
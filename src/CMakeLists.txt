cmake_minimum_required(VERSION 3.1...3.13)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(gravity VERSION 0.1.0
    DESCRIPTION "N-Body-Problem project of https://thoughts-on-cpp.com"
    LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")
include(GNUInstallDirs)
find_package(Catch 2.6.0 REQUIRED)
if(CATCH_FOUND)
    message(STATUS "Building interpreter tests using Catch v${CATCH_VERSION}")
else()
    message(STATUS "Catch not detected. Interpreter tests will be skipped. Install Catch headers"
        " manually or use `cmake -DDOWNLOAD_CATCH=1` to fetch them automatically.")
    return()
endif()

add_library(Catch INTERFACE)
target_include_directories(Catch 
    INTERFACE
    ${CATCH_INCLUDE_DIR})

add_subdirectory(solver src/solver)
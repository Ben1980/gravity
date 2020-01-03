cmake_minimum_required(VERSION 3.1...3.14)
project(gravity)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -std=c++17 -O3")

include(CTest)
add_subdirectory(app)
add_subdirectory(solver)
add_subdirectory(solverTest)
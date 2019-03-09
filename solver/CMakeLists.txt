add_library(solver
        src/solver.cpp
        include/particle.h
        include/particleBuilder.h
        src/particleBuilder.cpp
        include/types.h
        src/particle.cpp)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/extern/tbb")

find_package(TBB REQUIRED)
target_include_directories(solver
        PUBLIC
        include
        ${TBB_INCLUDE_DIRS})

target_link_libraries(solver
        ${TBB_LIBRARIES})
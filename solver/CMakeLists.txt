add_library(solver
        src/solver.cpp
        include/particle.h
        include/particleBuilder.h
        src/particleBuilder.cpp
        include/types.h
        src/particle.cpp)

find_package(Threads)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/extern/pstl")

find_package(TBB CONFIG REQUIRED)
target_link_libraries(solver PRIVATE TBB::tbb ${CMAKE_THREAD_LIBS_INIT} ${TBB_IMPORTED_TARGETS})

target_include_directories(solver
        PUBLIC
        include
        ${CMAKE_SOURCE_DIR}/extern/pstl)
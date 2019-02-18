add_library(solver
    SHARED
    src/solver.cpp)

target_include_directories(solver 
    PUBLIC 
    include)
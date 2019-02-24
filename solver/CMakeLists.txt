add_library(solver
    SHARED
    src/solver.cpp include/particle.h)

target_include_directories(solver 
    PUBLIC 
    include)
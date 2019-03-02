add_library(solver
    src/solver.cpp include/particle.h include/particleBuilder.h src/particleBuilder.cpp include/types.h src/types.cpp)

target_include_directories(solver 
    PUBLIC 
    include)
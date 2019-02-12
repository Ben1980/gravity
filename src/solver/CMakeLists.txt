add_library(solver
    SHARED
    src/solver.cpp)

target_include_directories(solver 
    PUBLIC 
    include)

add_executable(solverTest test/test-main.cpp)
target_link_libraries(solverTest Catch)

add_test(NAME solverTest COMMAND solverTest)
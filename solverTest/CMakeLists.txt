add_executable(solverTest 
    src/test-main.cpp
    src/solverTest.cpp)
target_link_libraries(solverTest
    Catch2
    solver)

enable_testing()
add_test(NAME solverTest COMMAND solverTest)
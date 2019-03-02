add_executable(solverTest 
    src/test-main.cpp
    src/solverTest.cpp src/vectorTest.cpp)

target_link_libraries(solverTest
    Catch2
    solver)

enable_testing()
add_test(NAME solverTest COMMAND solverTest)
add_test(NAME vectorTest COMMAND vectorTest)
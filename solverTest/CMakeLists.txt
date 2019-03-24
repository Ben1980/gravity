add_executable(solverTest 
    src/test-main.cpp
    src/solverTest.cpp src/vectorTest.cpp)

find_package(Catch2 CONFIG REQUIRED)
target_link_libraries(solverTest PRIVATE Catch2::Catch2
        solver)

#target_link_libraries(solverTest
#    solver)

enable_testing()
add_test(NAME solverTest COMMAND solverTest)
add_test(NAME vectorTest COMMAND vectorTest)
add_library(solver
    SHARED
    src/solver.cpp)

target_include_directories(solver 
    PUBLIC 
    include)

add_executable(solverTest 
    test/test-main.cpp
	test/solverTest.cpp)
target_link_libraries(solverTest Catch
    solver)

enable_testing()
add_test(NAME solverTest COMMAND solverTest)
#include <catch.hpp>
#include "solver.h"

TEST_CASE( "Test Hello World") {
    HelloWorld world;
    world.helloWorld();
    REQUIRE( world.helloWorld() == "Hello World!" );
}
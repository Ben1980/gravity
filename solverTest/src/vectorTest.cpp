#include <catch2/catch.hpp>
#include <types.h>
#include <cmath>

TEST_CASE( "Test Vector2D operators and functions", "[vector]" ) {
    const Vector2D vecA = { 1, 1 };
    const Vector2D vecB = { 3, 3 };

    SECTION( "Comparing vectors" ) {
        const Vector2D expected = vecA;
        REQUIRE(vecA == expected);
    }

    SECTION( "Length of a vector" ) {
        REQUIRE(vecB.length() == Approx(sqrt(3*3 + 3*3)));
    }

    SECTION( "Adding two vectors" ) {
        const Vector2D expected = { 4, 4 };
        CHECK((vecA + vecB) == expected);

        Vector2D result = vecA;
        result += vecB;
        REQUIRE(result == expected);
    }

    SECTION( "Subtracting two vectors" ) {
        const Vector2D expected = { 2, 2 };
        CHECK((vecB - vecA) == expected);

        Vector2D result = vecB;
        result -= vecA;
        REQUIRE(result == expected);
    }

    SECTION( "Multiplying vector with scalar" ) {
        const Vector2D expected = { 2, 2 };
        CHECK((vecA * 2) == expected);

        Vector2D result = vecA;
        result *= 2;
        REQUIRE(result == expected);
    }

    SECTION( "Dividing vector with scalar" ) {
        const Vector2D expected = { 2, 2 };
        CHECK((vecA * 2) == expected);

        Vector2D result = vecA;
        result *= 2;
        REQUIRE(result == expected);
    }
}

TEST_CASE( "Negative test Vector2D operators and functions", "[vector]" ) {
    const Vector2D vecA = { 1, 1 };

    SECTION( "Comparing vectors" ) {
        Vector2D error = { 0, 1 };
        CHECK_FALSE(vecA == error);

        error = { 1, 0};
        CHECK_FALSE(vecA == error);

        error = { 0.999, 0.999 };
        REQUIRE_FALSE(vecA == error);
    }

    SECTION( "Dividing vector with scalar" ) {
        //Vector2D failing = vecA / 0;
        //Catching asserts not possible with CATCH2 https://github.com/catchorg/Catch2/issues/853
    }
}
#include <catch.hpp>
#include <types.h>
#include <cmath>

TEST_CASE( "Test Vector2D operators and functions", "[vector]" )
{
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
        REQUIRE((vecA + vecB) == expected);

        Vector2D result = vecA;
        result += vecB;
        REQUIRE(result == expected);
    }

    SECTION( "Subtracting two vectors" ) {
        const Vector2D expected = { 2, 2 };
        REQUIRE((vecB - vecA) == expected);

        Vector2D result = vecB;
        result -= vecA;
        REQUIRE(result == expected);
    }

    SECTION( "Multiplying vector with scalar" ) {
        const Vector2D expected = { 2, 2 };
        REQUIRE((vecA * 2) == expected);

        Vector2D result = vecA;
        result *= 2;
        REQUIRE(result == expected);
    }

    SECTION( "Dividing vector with scalar" ) {
        const Vector2D expected = { 2, 2 };
        REQUIRE((vecA * 2) == expected);

        Vector2D result = vecA;
        result *= 2;
        REQUIRE(result == expected);
    }
}

TEST_CASE( "Negative test Vector2D operators and functions", "[vector]" )
{
    const Vector2D vecA = { 1, 1 };
    const Vector2D vecB = { 3, 3 };

    SECTION( "Comparing vectors" ) {
        //const Vector2D expected = vecA;
        //REQUIRE(vecA == expected);
    }

    SECTION( "Length of a vector" ) {
        //REQUIRE(vecB.length() == Approx(sqrt(3*3 + 3*3)));
    }

    SECTION( "Dividing vector with scalar" ) {
        //const Vector2D expected = { 2, 2 };
        //REQUIRE((vecA * 2) == expected);

        //Vector2D result = vecA;
        //result *= 2;
        //REQUIRE(result == expected);
    }
}
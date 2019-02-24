#include <catch.hpp>
#include "solver.h"
#include "particle.h"

#include <vector>

TEST_CASE( "Explicit euler algorithm with two mass points", "[euler]" ) {

    Solver solver;

    Particle particleA = ParticleBuilder()
            .position()
            .velocity()
            .acceleration()
            .mass()
            .build();

    Particle particleB = ParticleBuilder()
            .position()
            .velocity()
            .acceleration()
            .mass()
            .build();

    std::vector<Particle> particles = { particleA, particleB };

    const double EPSILON = 1e-3;

    SECTION( "Two still standing mass points are attracting each other" ) {
        std::vector<Particle> result = solver.solve(particles, EPSILON);


    }
}
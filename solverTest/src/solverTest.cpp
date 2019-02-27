#include <catch.hpp>
#include "solver.h"
#include "particle.h"

#include "particleBuilder.h"
#include <vector>

TEST_CASE( "Explicit euler algorithm with two point mass", "[euler]" ) {

    Solver solver;

    ParticleBuilder particleBuilder;

    const Particle particleA = particleBuilder
            .position({0.5, 0})
            .mass(1e10)
            .build();

    const Particle particleB = particleBuilder
            .position({-0.5, 0})
            .mass(1e10)
            .build();

    const std::vector<Particle> particles = { particleA, particleB };

    const double EPSILON = 1e-3;

    SECTION( "Two still standing point mass are attracting each other in x-direction" ) {
        const double acceleration = -0.6674079993; //m/s^2
        const double velocity = -0.06674079993; //m/s
        const double position = 0.48665184; //m

        std::vector<Particle> result = solver.solve(particles, EPSILON);

        const Particle &particle = result[0];
        REQUIRE(particle.acceleration.x == Approx(acceleration));
        REQUIRE(particle.velocity.x == Approx(velocity));
        REQUIRE(particle.position.x == Approx(position));
    }
}
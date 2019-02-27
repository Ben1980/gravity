#include <catch.hpp>
#include "solver.h"
#include "particle.h"

#include "particleBuilder.h"
#include <vector>

double Inverse(double value) { return -value; }

Particle GenerateStandardParticle(double xPosition, double yPosition)
{
    ParticleBuilder particleBuilder;

    return particleBuilder
            .position({xPosition, yPosition})
            .mass(1e10)
            .build();
}

TEST_CASE( "Explicit euler algorithm with two point mass", "[euler]" )
{
    Solver solver;

    const std::vector<Particle> particlesX = { GenerateStandardParticle(0.5, 0),
                                               GenerateStandardParticle(-0.5, 0)};

    const std::vector<Particle> particlesY = { GenerateStandardParticle(0, 0.5),
                                               GenerateStandardParticle(0, -0.5)};

    const double EPSILON = 1e-3;

    //Solution
    const double acceleration = -0.6674079993; //m/s^2
    const double velocity = -0.06674079993; //m/s
    const double position = 0.48665184; //m

    SECTION( "Two still standing point mass are attracting each other in x-direction" ) {
        std::vector<Particle> result = solver.solve(particlesX, EPSILON);

        Particle &particle = result.front();
        REQUIRE(particle.acceleration.x == Approx(acceleration));
        REQUIRE(particle.velocity.x == Approx(velocity));
        REQUIRE(particle.position.x == Approx(position));

        particle = result.back();
        REQUIRE(particle.acceleration.x == Approx(Inverse(acceleration)));
        REQUIRE(particle.velocity.x == Approx(Inverse(velocity)));
        REQUIRE(particle.position.x == Approx(Inverse(position)));
    }

    SECTION( "Two still standing point mass are attracting each other in y-direction" ) {
        std::vector<Particle> result = solver.solve(particlesY, EPSILON);

        Particle &particle = result.front();
        REQUIRE(particle.acceleration.y == Approx(acceleration));
        REQUIRE(particle.velocity.y == Approx(velocity));
        REQUIRE(particle.position.y == Approx(position));

        particle = result.back();
        REQUIRE(particle.acceleration.y == Approx(Inverse(acceleration)));
        REQUIRE(particle.velocity.y == Approx(Inverse(velocity)));
        REQUIRE(particle.position.y == Approx(Inverse(position)));
    }
}
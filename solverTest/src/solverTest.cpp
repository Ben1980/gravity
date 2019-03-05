#include <catch.hpp>
#include "solver.h"
#include "particle.h"

#include "particleBuilder.h"
#include <vector>

double Inverse(double value) { return -value; }

Particle GenerateStandardParticle(double xPosition, double yPosition) {
    ParticleBuilder particleBuilder;

    return particleBuilder
            .position({xPosition, yPosition})
            .mass(1e10)
            .build();
}

TEST_CASE( "Explicit euler algorithm with two point mass", "[euler]" ) {
    const double EPSILON = 0.1;
    Solver solver(EPSILON);

    const std::vector<Particle> particlesX = { GenerateStandardParticle(0.5, 0),
                                               GenerateStandardParticle(-0.5, 0)};

    const std::vector<Particle> particlesY = { GenerateStandardParticle(0, 0.5),
                                               GenerateStandardParticle(0, -0.5)};

    //Solution
    const double acceleration = -0.6674079993; //m/s^2
    const double velocity = -0.06674079993; //m/s
    const double position = 0.48665184; //m

    SECTION( "Two still standing point mass are attracting each other in x-direction" ) {
        std::vector<Particle> result = solver.solve(particlesX);

        Particle &particle = result.front();
        CHECK(particle.getAcceleration().x == Approx(acceleration));
        CHECK(particle.getVelocity().x == Approx(velocity));
        CHECK(particle.getPosition().x == Approx(position));

        particle = result.back();
        CHECK(particle.getAcceleration().x == Approx(Inverse(acceleration)));
        CHECK(particle.getVelocity().x == Approx(Inverse(velocity)));
        REQUIRE(particle.getPosition().x == Approx(Inverse(position)));
    }

    SECTION( "Two still standing point mass are attracting each other in y-direction" ) {
        std::vector<Particle> result = solver.solve(particlesY);

        Particle &particle = result.front();
        CHECK(particle.getAcceleration().y == Approx(acceleration));
        CHECK(particle.getVelocity().y == Approx(velocity));
        CHECK(particle.getPosition().y == Approx(position));

        particle = result.back();
        CHECK(particle.getAcceleration().y == Approx(Inverse(acceleration)));
        CHECK(particle.getVelocity().y == Approx(Inverse(velocity)));
        REQUIRE(particle.getPosition().y == Approx(Inverse(position)));
    }
}

TEST_CASE("Benchmarking euler", "[benchmark]") {
    const double EPSILON = 0.1;
    Solver solver(EPSILON);

    ParticleBuilder particleBuilder;
    std::vector<Particle> particles = particleBuilder.build(100);
    BENCHMARK("Benchmarking with 100 particles") {
        particles = solver.solve(particles);
    }

    particles = particleBuilder.build(1000);
    BENCHMARK("Benchmarking with 1000 particles") {
        particles = solver.solve(particles);
    }

    particles = particleBuilder.build(10000);
    BENCHMARK("Benchmarking with 10K particles") {
        particles = solver.solve(particles);
    }

    particles = particleBuilder.build(100000);
    BENCHMARK("Benchmarking with 100K particles") {
        particles = solver.solve(particles);
    }
}
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
        CHECK(particle.getAcceleration()[Coordinate::X] == Approx(acceleration));
        CHECK(particle.getVelocity()[Coordinate::X] == Approx(velocity));
        CHECK(particle.getPosition()[Coordinate::X] == Approx(position));

        particle = result.back();
        CHECK(particle.getAcceleration()[Coordinate::X] == Approx(Inverse(acceleration)));
        CHECK(particle.getVelocity()[Coordinate::X] == Approx(Inverse(velocity)));
        REQUIRE(particle.getPosition()[Coordinate::X] == Approx(Inverse(position)));
    }

    SECTION( "Two still standing point mass are attracting each other in y-direction" ) {
        std::vector<Particle> result = solver.solve(particlesY);

        Particle &particle = result.front();
        CHECK(particle.getAcceleration()[Coordinate::Y] == Approx(acceleration));
        CHECK(particle.getVelocity()[Coordinate::Y] == Approx(velocity));
        CHECK(particle.getPosition()[Coordinate::Y] == Approx(position));

        particle = result.back();
        CHECK(particle.getAcceleration()[Coordinate::Y] == Approx(Inverse(acceleration)));
        CHECK(particle.getVelocity()[Coordinate::Y] == Approx(Inverse(velocity)));
        REQUIRE(particle.getPosition()[Coordinate::Y] == Approx(Inverse(position)));
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

    particles = particleBuilder.build(200);
    BENCHMARK("Benchmarking with 200 particles") {
        particles = solver.solve(particles);
    }

    particles = particleBuilder.build(400);
    BENCHMARK("Benchmarking with 400 particles") {
        particles = solver.solve(particles);
    }

    particles = particleBuilder.build(800);
    BENCHMARK("Benchmarking with 800 particles") {
        particles = solver.solve(particles);
    }

    particles = particleBuilder.build(1600);
    BENCHMARK("Benchmarking with 1.6K particles") {
        particles = solver.solve(particles);
    }

    particles = particleBuilder.build(3200);
    BENCHMARK("Benchmarking with 3.2K particles") {
        particles = solver.solve(particles);
    }

    particles = particleBuilder.build(6400);
    BENCHMARK("Benchmarking with 6.4K particles") {
        particles = solver.solve(particles);
    }

    particles = particleBuilder.build(12800);
    BENCHMARK("Benchmarking with 12.8K particles") {
        particles = solver.solve(particles);
    }

    particles = particleBuilder.build(25600);
    BENCHMARK("Benchmarking with 25.6K particles") {
        particles = solver.solve(particles);
    }
}
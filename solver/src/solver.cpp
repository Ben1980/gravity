#include "solver.h"
#include "particle.h"
#include <cmath>
#include <algorithm>
#include <solver.h>


const double Solver::G = 6.67408e-11;
const double Solver::EPSILON = 1e-3;

Solver::Solver(double mEpsilon) : mEpsilon(mEpsilon) {}

std::vector<Particle> Solver::solve(const std::vector<Particle> &particles) const {
    std::vector<Particle> solution = calculateAcceleration(particles);
    solution = calculateVelocity(solution);
    solution = calculatePosition(solution);

    return solution;
}

std::vector<Particle> Solver::calculateAcceleration(const std::vector<Particle> &particles) const {
    std::vector<Particle> solution(particles.size());

    std::transform(begin(particles), end(particles), begin(solution), [&particles](const Particle &particle) {
        return AccumulateAcceleration(particles, particle);
    });

    return solution;
}

std::vector<Particle> Solver::calculateVelocity(const std::vector<Particle> &particles) const {
    std::vector<Particle> solution(particles.size());

    std::transform(begin(particles), end(particles), begin(solution), [epsilon = mEpsilon](Particle particle) {
        const Vector2D v0 = particle.getVelocity();
        particle.setVelocity(v0 + particle.getAcceleration()*epsilon);

        return particle;
    });

    return solution;
}

std::vector<Particle> Solver::calculatePosition(const std::vector<Particle> &particles) const {
    std::vector<Particle> solution(particles.size());

    std::transform(begin(particles), end(particles), begin(solution), [epsilon = mEpsilon](Particle particle) {
        const Vector2D v = particle.getVelocity();
        const Vector2D r0 = particle.getPosition();
        particle.setPosition(r0 + v*epsilon + particle.getAcceleration()*epsilon*epsilon);

        return particle;
    });

    return solution;
}

Particle Solver::AccumulateAcceleration(const std::vector<Particle> &particles, const Particle &particle) {
    Particle particleA = particle;
    const double e3 = EPSILON*EPSILON*EPSILON;

    std::for_each(begin(particles), end(particles), [&particleA, e3](const Particle &particleB) {
        if(particleA != particleB) {
            const double M = CalculateEquivalentMass(particleA, particleB);
            const Vector2D r = particleB.getPosition() - particleA.getPosition();
            const double rLength = r.length();
            const double r3 = fabs(rLength*rLength*rLength);

            const Vector2D a0 = particleA.getAcceleration();
            particleA.setAcceleration(a0 + G*M*r/(r3 + e3));
        }
    });

    return particleA;
}

double Solver::CalculateEquivalentMass(const Particle &particleA, const Particle &particleB) {
    const double massA = particleA.getMass();
    const double massB = particleB.getMass();

    return massA*massB/massA;
}

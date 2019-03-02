#include "solver.h"
#include "particle.h"
#include <cmath>
#include <algorithm>

const double Solver::G = 6.67408e-11;
const double Solver::EPSILON = 1e-3;

Solver::Solver(double mEpsilon) : mEpsilon(mEpsilon) {}

std::vector<Particle> Solver::solve(const std::vector<Particle> &particles) const
{
    std::vector<Particle> solution = calculateAcceleration(particles);

    return solution;
}

std::vector<Particle> Solver::calculateAcceleration(const std::vector<Particle> &particles) const
{
    std::vector<Particle> solution(particles.size());

    std::transform(begin(particles), end(particles), begin(solution), [&particles](const Particle &particle) {
        return accumulateAcceleration(particles, particle, G);
    });

    return solution;
}

Particle Solver::accumulateAcceleration(const std::vector<Particle> &particles, const Particle &particle, double G)
{
    Particle particleA = particle;
    const double e3 = EPSILON*EPSILON*EPSILON;

    std::for_each(begin(particles), end(particles), [&particleA, G, e3](const Particle &particleB) {
        if(particleA != particleB) {
            const double M = CalculateEquivalentMass(particleA, particleB);
            const Vector2D r = particleB.position - particleA.position;
            const double rLength = r.length();
            const double r3 = fabs(rLength*rLength*rLength);

            particleA.acceleration += G*M*r/(r3 + e3);
        }
    });

    return particleA;
}

const double Solver::CalculateEquivalentMass(const Particle &particleA, const Particle &particleB) {
    const double massA = particleA.mass;
    const double massB = particleB.mass;

    return massA*massB/massA;
}

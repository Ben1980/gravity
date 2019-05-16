#include "solver.h"
#include "particle.h"
#include <cmath>
#include <cassert>
#include <include/pstl/execution>
#include <include/pstl/algorithm>

const double Solver::G = 6.67408e-11;
const double Solver::EPSILON3 = 1e-9;

Solver::Solver(double mEpsilon) : mEpsilon(mEpsilon) {}

std::vector<Particle> Solver::solve(const std::vector<Particle> &particles) const {
    std::vector<Particle> solution(particles.size());

    const double epsilon2 = mEpsilon*mEpsilon;
    std::transform(pstl::execution::par_unseq, begin(particles), end(particles), begin(solution), [&particles, epsilon2, epsilon = mEpsilon](Particle particle) {
        particle = AccumulateAcceleration(particles, particle);

        const Vector2D v0 = particle.getVelocity();
        particle.setVelocity(v0 + particle.getAcceleration()*epsilon);

        const Vector2D v = particle.getVelocity();
        const Vector2D r0 = particle.getPosition();
        particle.setPosition(r0 + v*epsilon + particle.getAcceleration()*epsilon2);

        return particle;
    });

    return solution;
}

Particle Solver::AccumulateAcceleration(const std::vector<Particle> &particles, Particle particle) {
    std::for_each(begin(particles), end(particles), [&particle](const Particle &particleB) {
        if(particle != particleB) {
            const double M = CalculateEquivalentMass(particle, particleB);
            const Vector2D r = particleB.getPosition() - particle.getPosition();
            const double rLength = r.length();
            const double r3 = fabs(rLength*rLength*rLength);

            const Vector2D a0 = particle.getAcceleration();
            particle.setAcceleration(a0 + G*M*r/(r3 + EPSILON3));
        }
    });

    return particle;
}

double Solver::CalculateEquivalentMass(const Particle &particleA, const Particle &particleB) {
    const double massA = particleA.getMass();
    assert(massA > 0);

    const double massB = particleB.getMass();

    return massA*massB/massA;
}

#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include "types.h"

class Particle;

class Solver {
public:
    explicit Solver(double mEpsilon);

    std::vector<Particle> solve(const std::vector<Particle> &particles) const;

private:
    std::vector<Particle> calculateAcceleration(const std::vector<Particle> &particles) const;
    std::vector<Particle> calculateVelocity(const std::vector<Particle> &particles) const;
    std::vector<Particle> calculatePosition(const std::vector<Particle> &particles) const;
    static Particle AccumulateAcceleration(const std::vector<Particle> &particles, const Particle &particle);
    static double CalculateEquivalentMass(const Particle &particleA, const Particle &particleB);

    static const double G;
    static const double EPSILON;
    double mEpsilon;
};

#endif
#ifndef SOLVER_H
#define SOLVER_H

#include <vector>

class Particle;

class Solver {
public:
    std::vector<Particle> solve(const std::vector<Particle> &particles, double epsilon) const;
};

#endif
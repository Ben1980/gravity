#include "controller.h"

#include "../../solver/include/solver.h"
#include "../../solver/include/particleBuilder.h"
#include <iterator>

Controller::Controller(QObject *parent)
    : QObject(parent)
{
}

void Controller::randomizeClicked(int numberOfParticles, int numberOfSteps, double epsilon) {
    std::vector<Particle> particles = ParticleBuilder().build(numberOfParticles);
    mParticles.reserve(numberOfParticles*numberOfSteps);

    Solver solver(epsilon);

    for(int step = 0; step < numberOfSteps; step++) {
        mParticles.insert(mParticles.end(), particles.begin(), particles.end());
        particles = solver.solve(particles);
    }
}
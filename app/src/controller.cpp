#include "controller.h"

#include "../../solver/include/solver.h"
#include "../../solver/include/particleBuilder.h"

Controller::Controller(QObject *parent)
    : QObject(parent)
{
}

void Controller::randomizeClicked(int numberOfParticles, int numberOfSteps, double epsilon) {
    mParticles = generateParticles(numberOfParticles, numberOfSteps);

    Solver solver(epsilon);

    for(int step = 1; step < numberOfSteps; step++) {
        mParticles[step] = solver.solve(mParticles[step - 1]);
    }
}

std::vector<std::vector<Particle>> Controller::generateParticles(int numberOfParticles, int numberOfSteps) const {
    std::vector<std::vector<Particle>> particles(numberOfSteps);

    particles.front() = ParticleBuilder().build(numberOfParticles);

    return particles;
}
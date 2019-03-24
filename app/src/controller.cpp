#include "controller.h"

#include <iostream>


Controller::Controller(double epsilon, QObject *parent)
    : QObject(parent)//, mSolver(std::make_unique<Solver>(epsilon))
{

}

void Controller::randomizeClicked(int numberOfParticles, int numberOfSteps, double epsilon) {
    std::cout << numberOfParticles << std::endl;
    std::cout << numberOfSteps << std::endl;
    std::cout << epsilon << std::endl;
}
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <memory>
//#include "solver.h"
//#include <queue>
//#include "particle.h"



class Controller : public QObject {
    Q_OBJECT
public:
    explicit Controller(double epsilon, QObject *parent = nullptr);

public slots:
    void randomizeClicked(int numberOfParticles, int numberOfSteps, double epsilon);

private:
    //std::unique_ptr<Solver> mSolver;
    //std::queue<std::vector<Particle>> mParticleQueue;
};

#endif

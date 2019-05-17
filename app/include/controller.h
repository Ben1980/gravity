#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../../solver/include/particle.h"
#include <QObject>
#include <vector>

class Controller : public QObject {
    Q_OBJECT

public:
    explicit Controller(QObject *parent = nullptr);

public slots:
    void randomizeClicked(int numberOfParticles, int numberOfSteps, double epsilon);

private:
    std::vector<std::vector<Particle>> generateParticles(int numberOfParticles, int numberOfSteps) const;

    std::vector<std::vector<Particle>> mParticles;
};

#endif

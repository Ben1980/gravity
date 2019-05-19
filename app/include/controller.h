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
    std::vector<Particle> getParticles() const { return mParticles; }

private:
    std::vector<Particle> mParticles;
};

#endif

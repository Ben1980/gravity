#ifndef GRAVITY_PARTICLEVIEWER_H
#define GRAVITY_PARTICLEVIEWER_H

#include <QtQuick/QQuickItem>
#include "../../solver/include/particle.h"
#include "controller.h"

class ParticleRenderer;

class ParticleViewer : public QQuickItem {
    Q_OBJECT
    Q_PROPERTY(qreal t READ t WRITE setT NOTIFY tChanged)

public:
    ParticleViewer();
    qreal t() const { return mT; }
    void setT(qreal t);

signals:
    void tChanged();

public slots:
    void sync();
    void cleanup();
    void randomizeClicked(int numberOfParticles, int numberOfSteps, double epsilon);
    //void updateParticleSystem(const std::vector<std::vector<Particle>> *timeDependentParticles);

private slots:
    void handleWindowChanged(QQuickWindow *win);

private:
    qreal mT;
    ParticleRenderer *mRenderer;
    Controller mController;
};

#endif //GRAVITY_PARTICLEVIEWER_H

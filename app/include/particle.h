#ifndef PARTICLE_H
#define PARTICLE_H

#include <QQuickItem>
#include "renderer.h"

class Particle : public QQuickItem {
    Q_OBJECT
    Q_PROPERTY(qreal t READ t WRITE setT NOTIFY tChanged)

public:
    Particle();

    qreal t() const { return m_t; }
    void setT(qreal t);

signals:
    void tChanged();

public slots:
    void update();
    void cleanup();
    void randomizeClicked(int numberOfParticles, int numberOfSteps, double epsilon);

private slots:
    void handleWindowChanged(QQuickWindow *win);

private:
    qreal m_t;
    Renderer *m_renderer;
};

#endif
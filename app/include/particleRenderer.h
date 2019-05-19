#ifndef GRAVITY_PARTICLERENDERER_H
#define GRAVITY_PARTICLERENDERER_H

#include <QtGui/QOpenGLFunctions>
#include <QtQuick/QQuickWindow>
#include <glm/vec2.hpp>
#include <glm/vec4.hpp>
#include "../../solver/include/particle.h"
#include <vector>

class QOpenGLShaderProgram;

class ParticleRenderer : public QObject, protected QOpenGLFunctions {
    Q_OBJECT

public:
    ParticleRenderer();
    ~ParticleRenderer() final;
    void setT(qreal t) { mT = t; }
    void setViewportSize(const QSize &size) { mViewportSize = size; }
    void setWindow(QQuickWindow *window) { mWindow = window; }
    void updateParticleSystem(const std::vector<Particle> &timeDependentParticles);

public slots:
    void paint();

private:
    QSize mViewportSize;
    qreal mT;
    QOpenGLShaderProgram *mProgram;
    QQuickWindow *mWindow;
    std::vector<Particle> mParticles;
};

#endif //GRAVITY_PARTICLERENDERER_H

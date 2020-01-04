#include "particle.h"
#include <QtQuick>

Particle::Particle()
    : m_t(0), m_renderer(nullptr) {
    connect(this, &QQuickItem::windowChanged, this, &Particle::handleWindowChanged);
}

void Particle::cleanup()
{
    if(m_renderer) {
        delete m_renderer;
        m_renderer = nullptr;
    }
}

void Particle::handleWindowChanged(QQuickWindow *win) {
    if (win) {
        connect(win, &QQuickWindow::beforeSynchronizing, this, &Particle::update, Qt::DirectConnection);
        connect(win, &QQuickWindow::sceneGraphInvalidated, this, &Particle::cleanup, Qt::DirectConnection);
        win->setClearBeforeRendering(false);
    }
}

void Particle::update() {
    if (!m_renderer) {
        m_renderer = new Renderer();
        connect(window(), &QQuickWindow::beforeRendering, m_renderer, &Renderer::paint, Qt::DirectConnection);
    }
    m_renderer->setViewportSize(window()->size() * window()->devicePixelRatio());
    m_renderer->setT(m_t);
    m_renderer->setWindow(window());
}

void Particle::setT(qreal t) {
    if (fabs(t - m_t) <= std::numeric_limits<qreal>::min()) return;

    m_t = t;
    emit tChanged();

    if (window()) {
        window()->update();
    }
}

void Particle::randomizeClicked(int numberOfParticles, int numberOfSteps, double epsilon) {
    // mController.randomizeClicked(numberOfParticles, numberOfSteps, epsilon);
    // if(mRenderer) {
    //     mRenderer->updateParticleSystem(mController.getParticles());
    // }


}
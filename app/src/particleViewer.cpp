#include "particleViewer.h"
#include <QtQuick/qquickwindow.h>
#include "particleRenderer.h"

ParticleViewer::ParticleViewer()
    : mT(0), mRenderer(nullptr) {
    connect(this, &QQuickItem::windowChanged, this, &ParticleViewer::handleWindowChanged);
}

void ParticleViewer::handleWindowChanged(QQuickWindow *win) {
    if (win) {
        connect(win, &QQuickWindow::beforeSynchronizing, this, &ParticleViewer::sync, Qt::DirectConnection);
        connect(win, &QQuickWindow::sceneGraphInvalidated, this, &ParticleViewer::cleanup, Qt::DirectConnection);
        win->setClearBeforeRendering(false);
    }
}

void ParticleViewer::sync() {
    if (!mRenderer) {
        mRenderer = new ParticleRenderer();
        connect(window(), &QQuickWindow::beforeRendering, mRenderer, &ParticleRenderer::paint, Qt::DirectConnection);
    }
    mRenderer->setViewportSize(window()->size() * window()->devicePixelRatio());
    mRenderer->setT(mT);
    mRenderer->setWindow(window());
}

void ParticleViewer::cleanup() {
    if (mRenderer) {
        delete mRenderer;
        mRenderer = nullptr;
    }
}

void ParticleViewer::setT(qreal t) {
    if (t == mT) return;

    mT = t;
    emit tChanged();

    if (window()) {
        window()->update();
    }
}
void ParticleViewer::randomizeClicked(int numberOfParticles, int numberOfSteps, double epsilon) {
    mController.randomizeClicked(numberOfParticles, numberOfSteps, epsilon);
    if(mRenderer) {
        mRenderer->updateParticleSystem(mController.getParticles());
    }


}
/*void ParticleViewer::updateParticleSystem(const std::vector<std::vector<Particle>> *timeDependentParticles) {
    if(mRenderer) {
        mRenderer->updateParticleSystem(timeDependentParticles);
    }
}*/


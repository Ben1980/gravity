#include <particleRenderer.h>
#include <QtGui/QOpenGLShaderProgram>

ParticleRenderer::ParticleRenderer()
    : mT(0), mProgram(nullptr), mWindow(nullptr) {}

ParticleRenderer::~ParticleRenderer() {
    delete mProgram;
}

void ParticleRenderer::paint() {
    if (!mProgram) {
        initializeOpenGLFunctions();

        mProgram = new QOpenGLShaderProgram();
        mProgram->addCacheableShaderFromSourceCode(QOpenGLShader::Vertex,
                                                    "attribute highp vec4 vertices;"
                                                    "varying highp vec2 coords;"
                                                    "void main() {"
                                                    "    gl_Position = vertices;"
                                                    "    coords = vertices.xy;"
                                                    "    gl_PointSize = 20.0f;"
                                                    "}");
        mProgram->addCacheableShaderFromSourceCode(QOpenGLShader::Fragment,
                                                    "uniform lowp float t;"
                                                    "varying highp vec2 coords;"
                                                    "void main() {"
                                                    "    lowp float i = 1. - (pow(abs(coords.x), 4.) + pow(abs(coords.y), 4.));"
                                                    "    i = smoothstep(t - 0.8, t + 0.8, i);"
                                                    "    i = floor(i * 20.) / 20.;"
                                                    "    gl_FragColor = vec4(0.0,255.0,0.0,255.0);"
                                                    "}");

        mProgram->bindAttributeLocation("vertices", 0);
        mProgram->link();
    }
    mProgram->bind();

    mProgram->enableAttributeArray(0);

    if(!mParticles.empty()) {
        std::vector<QVector2D> vec(mParticles.size());
        double maxX = 0;
        double maxY = 0;
        for(int i = 0; i < vec.size(); i++) {
            vec[i].setX(mParticles[i].getPosition()[Coordinate::X]);
            vec[i].setY(mParticles[i].getPosition()[Coordinate::Y]);

            if(fabs(vec[i].x()) > maxX) maxX = fabs(vec[i].x());
            if(fabs(vec[i].y()) > maxY) maxY = fabs(vec[i].y());
        }

        for(QVector2D &element : vec) {
            element.setX(element.x()/maxX);
            element.setY(element.y()/maxY);
        }

        mProgram->setAttributeArray(0, &vec[0]);
        /*float values[] = {
                -1, -1, 0,
                1, -1, 0,
                -1, 1, 0,
                1, 1, 0
        };
        mProgram->setAttributeArray(0, GL_FLOAT, values, 3);*/


    }

    mProgram->setUniformValue("t", (float) mT);

    glViewport(0, 0, mViewportSize.width(), mViewportSize.height());

    glDisable(GL_DEPTH_TEST);

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    glEnable(GL_PROGRAM_POINT_SIZE);
    glDrawArrays(GL_POINTS, 0, 4);

    mProgram->disableAttributeArray(0);
    mProgram->release();

    mWindow->resetOpenGLState();
}

void ParticleRenderer::updateParticleSystem(const std::vector<Particle> &timeDependentParticles) {
    mParticles = timeDependentParticles;
}


#include <QGuiApplication>
#include <QQuickView>
//#include <QQmlApplicationEngine>
//#include <QQmlContext>
//#include "particleViewer.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickView view;
    view.setSource(QUrl("qrc:///main.qml"));
    //view.show();

    return app.exec();

    /*QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //qmlRegisterType<ParticleViewer>("ParticleViewer", 1, 0, "ParticleViewer");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return QGuiApplication::exec();*/
}

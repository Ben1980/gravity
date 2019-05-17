#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <controller.h>
#include "viewer.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Squircle>("Viewer", 1, 0, "Squircle");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    Controller controller;
    engine.rootContext()->setContextProperty("controller", &controller);

    return QGuiApplication::exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "zroundbuttonitem.h"
#include <QList>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("untitled100", "Main");

    return app.exec();
}

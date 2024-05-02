#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "learnqtlogo.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<LearnQtLogo>("guide.learnqt.logos",1,0,"Logo");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/PaintingQMLItems/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

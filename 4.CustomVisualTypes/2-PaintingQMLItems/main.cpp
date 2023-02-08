#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "learnqtlogo.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<LearnQtLogo>("com.blikoon.logos",1,0,"Logo");


    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/2-PaintingQMLItems/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

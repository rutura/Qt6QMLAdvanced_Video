#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include "stairchart.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //qmlRegisterType<StairChart>("com.blikoon.charts",1,0,"StairChart");


    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/BarChart/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

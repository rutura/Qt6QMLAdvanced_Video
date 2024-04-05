#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include "stair.h"
//#include "stairchart.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //qmlRegisterType<StairChart>("com.blikoon.charts",1,0,"StairChart");
    //qmlRegisterType<Stair>("com.blikoon.charts",1,0,"Stair");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/BarchartListProps/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

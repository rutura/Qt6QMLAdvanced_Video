#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // qmlRegisterSingletonType(QUrl("qrc:/4-QMLSingleton/QmlSingleton.qml"),
    //                          "com.blikoon.qmlsingleton",1,0,"QMLSingleton");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/com/blikoon/qmlsingleton/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

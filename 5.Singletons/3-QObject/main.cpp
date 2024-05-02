#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include "singletonclass.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    /*
    qmlRegisterSingletonType<SingletonClass>("com.blikoon1.singletondata1", 1, 0, "MyApi",
                                             SingletonClass::singletonProvider);
    */

    /*
    qmlRegisterSingletonType<SingletonClass>("com.blikoon1.singletondata1", 1, 0, "MyApi",
                                             [](QQmlEngine *engine, QJSEngine *scriptEngine)->QObject *{
                                                 Q_UNUSED(engine)
                                                 Q_UNUSED(scriptEngine)

                                                 SingletonClass * example = new SingletonClass();
                                                 return example;
                                             });
    */

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/QObject/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

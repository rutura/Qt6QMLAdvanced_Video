#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include "singletonclass.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    /*
        qmlRegisterSingletonType("com.blikoon.singletondata",1,0,"MyApi", // It's important that MyApi here starts with uppercase, otherwise you'll get errors.
                                 SingletonClass::singletonProvider);
        */


       qmlRegisterSingletonType("com.blikoon.singletondata",1,0,"MyApi",  //It's important that MyApi here starts with upppercase, otherwise you'll get errors.
                                [](QQmlEngine *engine, QJSEngine *scriptEngine)->QJSValue{
           Q_UNUSED(scriptEngine)
           int mValue = 5;

           QJSValue jsValue = engine->newObject();
           jsValue.setProperty("someProperty",mValue);

           //Put in an array
           QJSValue mArray = engine->newArray(3);
           for (unsigned int i = 1; i <= 3; ++i) {
               mArray.setProperty(i, i*5);
           }

           jsValue.setProperty("mArray",mArray);

           return jsValue;

       });

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/com/blikoon/singletondata/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

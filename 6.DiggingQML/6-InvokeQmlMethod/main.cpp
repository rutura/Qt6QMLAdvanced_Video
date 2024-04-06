/*
 *  Showing how to call a qml function nested down in the tree structure.
 *      Now we can do this because we can parse qml from C++ and find the
 *      item containing our js function.
 *
 * */

#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/InvokeQmlMethod/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;

    QObject * rootObject = engine.rootObjects()[0];

    QObject * funcContext = rootObject->findChild<QObject*>("deep2");

    if( funcContext){
        qDebug() << "Found the object";
        QVariant returnValue;
        QVariant parameter = "C++ Parameter";

        QMetaObject::invokeMethod(funcContext,"qmlFunction",
                                  Q_RETURN_ARG(QVariant,returnValue),
                                  Q_ARG(QVariant,parameter)
                                  );
        qDebug() << "This is C++, return value is : " << returnValue.toString();

    }

    return app.exec();
}

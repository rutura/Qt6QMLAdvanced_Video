#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/InvokeQmlMethod/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    if(engine.rootObjects().empty()){
        return -1;
    }

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

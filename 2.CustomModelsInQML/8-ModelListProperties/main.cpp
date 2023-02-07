#include <QGuiApplication>
#include <QQmlContext>
#include <QQuickStyle>
#include <QQmlApplicationEngine>
#include "datasource.h"
#include "personmodel.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
        QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;


    qmlRegisterType<Person>("com.blikoon.models",1,0,"Person");
    qmlRegisterType<PersonModel>("com.blikoon.models",1,0,"PersonModel");

    //    PersonModel mModel;
    //    DataSource * ds = new DataSource(&mModel);
    //    mModel.setDataSource(ds);

    //     engine.rootContext()->setContextProperty("myModel",&mModel);
    //     engine.rootContext()->setContextProperty("myDataSource",ds);

    const QUrl url(u"qrc:/8-ModelListProperties/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

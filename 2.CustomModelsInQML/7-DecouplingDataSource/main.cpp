#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include "personmodel.h"
#include "datasource.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;

    PersonModel mModel;
    DataSource * ds = new DataSource(&mModel);
    mModel.setDataSource(ds);

    engine.rootContext()->setContextProperty("myModel",&mModel);
    engine.rootContext()->setContextProperty("myDataSource",ds);


    const QUrl url(u"qrc:/7-DecouplingDataSource/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

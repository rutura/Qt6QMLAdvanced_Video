#include <QNetworkRequest>
#include <QQmlContext>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include "appwrapper.h"

AppWrapper::AppWrapper(QObject *parent) : QObject(parent)
{

}
bool AppWrapper::initialize(QGuiApplication * app)
{
    DataSource * ds = new DataSource(this);
    mPostModel.setDatasource(ds);
    mEngine.rootContext()->setContextProperty("myModel",&mPostModel);
    mEngine.rootContext()->setContextProperty("myDatasource",ds);


    const QUrl url(u"qrc:/RestApiClientV2/Main.qml"_qs);
    QObject::connect(&mEngine, &QQmlApplicationEngine::objectCreated,
                        app, [url](QObject *obj, const QUrl &objUrl) {
           if (!obj && url == objUrl)
               QCoreApplication::exit(-1);
       }, Qt::QueuedConnection);
    mEngine.load(url);

    if (mEngine.rootObjects().isEmpty()){
        return false;
    }else{
        return true;
    }
}


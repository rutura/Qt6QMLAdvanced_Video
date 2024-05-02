#include "appwrapper.h"

AppWrapper::AppWrapper(QObject *parent)
    : QObject{parent}
{

}

bool AppWrapper::initialize()
{
    const QUrl url(u"qrc:/CatchQmlSignal/Main.qml"_qs);
    mEngine.load(url);

    if (mEngine.rootObjects().isEmpty())
        return false;

    QObject * rootObject = mEngine.rootObjects()[0];// The object that contains the signal on the QML side.
    connect(rootObject,SIGNAL(qmlSignal(QString,QVariant)),
            this,SLOT(respondToClick(QString,QVariant)));

    return true;

}

void AppWrapper::respondToClick(QString msg, const QVariant &object)
{
    qDebug() << "The message is : " << msg;

    QObject * mObject = object.value<QObject*>();

    qDebug() << "The property is : " << mObject->property("mProp").toString();
}

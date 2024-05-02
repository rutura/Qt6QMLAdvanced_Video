#include <QGuiApplication>
#include <QQuickView>
#include <QQuickItem>
#include <QQmlProperty>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    QQuickView view;
    view.setSource(QUrl("qrc:/qml/main.qml"));
    view.show();


    QObject * rootObject = view.rootObject();
    qDebug() << "Root object name is : " << rootObject->objectName();


    //Hijack the qml and change it before handing  control over
    //to the event loop.
    QObject * object = rootObject->findChild<QObject*>("rect");
    if( object){
        QQuickItem * item = qobject_cast<QQuickItem*>(object);

        //Modify its properties
        QColor color(Qt::blue);
        item->setProperty("color",color);
        item->setProperty("width",QVariant::fromValue(600));
        item->setProperty("height",QVariant::fromValue(600));
        QQmlProperty::write(item,"height",QVariant::fromValue(800));
    }

    return a.exec();
}

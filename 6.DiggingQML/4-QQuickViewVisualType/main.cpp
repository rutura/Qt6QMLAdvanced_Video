/*
 *      . Showing how to manipulate a visualized qml type with QQuickView
 *      . Notice that we use QGui appliation in main.cpp
 *          QCoreApplication has no visualization capabilities.
 *
 *      .Again this app starts out as a console application and we bring in the
 *          modules we need and change main.cpp to use QGuiApplication.
 *
 *      . See qt 5 course for reference where needed and improvise.
 *
 * */

#include <QGuiApplication>
#include <QQuickView>
#include <QQuickItem>
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
    }

    return a.exec();
}

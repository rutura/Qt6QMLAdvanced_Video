/*
 *
 *  ATTENTION : The flow to get things working in thi project :
 *          . Create a console app
 *          . Click on Projects -> Run and check run in terminal to see the terminal window.
 *          . Add a resource file named qml
 *          . Put your qml file in a folder named qml
 *          . Add the qml/main.qml file to the resource file
 *          . Load the qml file from the resource file using the shown syntax
 *
 *
 *
 *      . We use QQmlEngine to read and parse and qml file from C++ .
 *      .   We have the ability to  :
 *          . Read qml properties from C++
 *          . Write and modify qml properties from C++. Please note that the changes
 *              are not written back to the qml file on your drive, but on the qml
 *              tree representation in memory.
 *
 *       . All starts by getting hold of the root object :
 *              .     QQmlComponent component(&engine,"qrc:/qml/main.qml");
                QObject * rootObject = component.create();

                . In this case, we set up a resource file named qml, and in it, we
                    have a qml file named main.qml, it's what we're parsing. Notice
                    the syntax to go and get what's in the resource file.

         . For what we want to do here work, remember that you need the Core,Gui and Qml
            modules that you're bringing in in the CMakeLists.txt file.

         . Use the Qt5 course as a reference and improvise.
 *
 *
 * */


#include <QCoreApplication>
#include <QDebug>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QQmlProperty>
#include <QColor>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QQmlEngine engine;
    QQmlComponent component(&engine,"qrc:/qml/main.qml");
    QObject * rootObject = component.create();

    qDebug() << "Object name is : " << rootObject->objectName();
    //Print the number of children in the qml file
    qDebug() << "Children count : " << rootObject->children().count();

    //Read Child1
    QObject * child1 = rootObject->findChild<QObject * > ("Child1");


    if( child1){
        qDebug() << "Age is : " << 			QQmlProperty::read(child1,"age").toInt();	// Syntax #1
        qDebug() << "Age is : " << 			child1->property("age").toInt();				// Syntax #2



        qDebug() << "Names : " << child1->property("names").toString();
    }else {
        qDebug() << "Could not get object with object name Child1";
    }

    //Manipulate rect
    QObject * childRect = rootObject->findChild<QObject*>("childRect");

    if( childRect){
        qDebug() << "The  rect width is " << childRect->property("width").toInt();
        qDebug() << "The rect color is :" << childRect->property("color").toString();
        qDebug() << "The  rect height is " << childRect->property("height").toInt();

        //Modif rect properties
        QColor color(Qt::red);

        childRect->setProperty("width",QVariant::fromValue(600));
        QQmlProperty::write(childRect,"height",QVariant::fromValue(600));
        childRect->setProperty("color",color);

        qDebug() << "Printing out new rect properties";
        qDebug() << "The  rect width is " << childRect->property("width").toInt();
        qDebug() << "The rect color is :" << childRect->property("color").toString();
        qDebug() << "The  rect height is " << childRect->property("height").toInt();
    }

    //Find children
    QList<QObject * > children = rootObject->findChildren<QObject *> ("Child2");


    if( children.count()> 0){
        qDebug() << "Got some children, printing their cars :";
        foreach (QObject * object, children) {
            qDebug() << "The car brand is : " << object->property("car").toString();
        }
    }

    //Recursive and direct children
    QList<QObject * > deepChildren = rootObject->findChildren<QObject *> ("deepChild",Qt::FindDirectChildrenOnly);// Default Recursive
    if ( deepChildren.count( ) > 0){
        qDebug() << "Found " << deepChildren.count()  << " deepChildren, printing out their levels : ";
        foreach (QObject * object, deepChildren) {
            qDebug() << "The child level is : " << object->property("level").toString();
        }
    }

    return a.exec();
}

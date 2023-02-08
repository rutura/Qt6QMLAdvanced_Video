/*
    . Exposing singleton data from QML :
        . Put the data in a QML file
        . expose like we do in the main.cpp file :
            .     qmlRegisterSingletonType(QUrl("qrc:/4-QMLSingleton/QmlSingleton.qml"),
                             "com.blikoon.qmlsingleton",1,0,"QMLSingleton");

        . Notice that you have to figure out the path of the qml file in your resources,
            one can steal from the Qt boilerplate code though :-)

  */

import QtQuick
import com.blikoon.qmlsingleton 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Singleton QML Demo")

       Component.onCompleted: {
           console.log(QMLSingleton.testProperty)
       }
}

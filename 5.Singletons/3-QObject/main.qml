/*
        . Exposing Q_PROPERTY based data to propagate changes
            easily to QML

        . Good for data that changes frequently

        . Flow:
            . Show static method with qmlRegister*
                . MyApi has to sart with uppercase
            . Show lambda with qmlRegister*
                . MyApi has to start with uppercase.
            . Rely on QML_ELEMENT and QML_SINGLETON
                . When we do this, we take out the qmlRegister* calls
                . We create a property myApi (starts with lowercase) on the QML side
                . We create the singleton and assign it to the property.
  */

import QtQuick
import com.blikoon1.singletondata1 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Singleton QObject Demo")
    property var myApi: SingletonClass //We instantiate the class object on the QML side.


    //This works with qmlRegister*
       Rectangle {
           id : rect1
           width: 200
           height: 200
           radius: 10
           color: "red"

           Text {
               id: mText1
               anchors.centerIn: parent
               color: "white"
               font.pointSize: 30
               text: MyApi.someProperty
           }
       }

       //We use this when the object is instantiated on the QML side.
       //We use this when all the qmlRegister* calls are commented out in the main.cpp file.
       Rectangle {
           id : rect2
           anchors.left : rect1.right
           width: 200
           height: 200
           radius: 10
           color: "dodgerblue"

           Text {
               id: mText2
               anchors.centerIn: parent
               color: "white"
               font.pointSize: 30
               text: myApi.someProperty
           }
       }
}

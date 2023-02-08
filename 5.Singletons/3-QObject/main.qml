/*
        . Exposing Q_PROPERTY based data to propagate changes
            easily to QML

        . Good for data that changes frequently

  */

import QtQuick
import com.blikoon1.singletondata1 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Singleton QObject Demo")

       Rectangle {
           id : rect1
           width: 200
           height: 200
           radius: 20
           color: "red"

           Text {
               id: mText1
               anchors.centerIn: parent
               color: "white"
               font.pointSize: 30
               text: MyApi.someProperty
           }
       }

       Rectangle {
           id : rect2
           anchors.left : rect1.right
           width: 200
           height: 200
           radius: 20
           color: "dodgerblue"

           Text {
               id: mText2
               anchors.centerIn: parent
               color: "white"
               font.pointSize: 30
               text: MyApi.someProperty
           }
       }
}

/*

        . Exposing simple stringLists as models from C++ for use in QML
        . Use the docs and the Qt5 course as reference.


  */

import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("StringList Model Demo")

       ListView{
           id : mListView
           anchors.fill: parent

           model: continentModel
           delegate: Rectangle {
               height: 50
               radius: 10
               color: "dodgerblue"
               border.color: "cyan"
               width: parent.width
               Text {
                   text: modelData
                   font.pointSize: 20
                   anchors.centerIn: parent
                   anchors.horizontalCenter: parent.horizontalCenter
               }
           }
       }
}

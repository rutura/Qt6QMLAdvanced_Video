/*

        . Exposing simple stringLists as models from C++ for use in QML
        . Use the docs and the Qt5 course as reference.


  */

import QtQuick

Window {
    id: rootId
    width: 640
    height: 480
    visible: true
    title: qsTr("StringList Model Demo")

    ListView{
        id : mListViewId
        anchors.fill: parent

        //model: continentModel
        //model: itemList1
        model: itemList2
        delegate: Rectangle {
            height: 50
            radius: 10
            color: "dodgerblue"
            border.color: "cyan"
            width: (parent === null ?  rootId.width  : parent.width) // To avoid property of null errors when
                                                                     // ListView is temporarity destroyed
            Text {
                text: modelData
                font.pointSize: 20
                anchors.centerIn: parent
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
}

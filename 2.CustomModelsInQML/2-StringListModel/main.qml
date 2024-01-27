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

        model: continentModel
        delegate: Rectangle {
            height: 50
            radius: 10
            color: "dodgerblue"
            border.color: "cyan"
            width: (parent === null ?  rootId.width  : parent.width) // To avoid property of null errors when ListView is temporarity destroyed
            Text {
                text: modelData
                font.pointSize: 20
                anchors.centerIn: parent
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

    // Column{
    //     spacing: 20
    //     anchors.fill: parent
    //     ListView{
    //         id : mListView
    //         // anchors.fill: parent
    //         width: parent.width
    //         height: parent.height / 3

    //         model: continentModel
    //         delegate: Rectangle {
    //             height: 50
    //             radius: 10
    //             color: "dodgerblue"
    //             border.color: "cyan"
    //             width: (parent === null ?  rootId.width  : parent.width) // To avoid property of null errors when ListView is temporarity destroyed
    //             Text {
    //                 text: modelData
    //                 font.pointSize: 20
    //                 anchors.centerIn: parent
    //                 anchors.horizontalCenter: parent.horizontalCenter
    //             }
    //         }
    //     }
    //     ListView{
    //         id : mListView1
    //         // anchors.fill: parent
    //         width: parent.width
    //         height: parent.height / 3

    //         model: itemList1
    //         delegate: Rectangle {
    //             height: 50
    //             radius: 10
    //             color: "dodgerblue"
    //             border.color: "cyan"
    //             width: (parent === null ?  rootId.width  : parent.width)
    //             Text {
    //                 text: modelData
    //                 font.pointSize: 20
    //                 anchors.centerIn: parent
    //                 anchors.horizontalCenter: parent.horizontalCenter
    //             }
    //         }
    //     }
    //     ListView{
    //         id : mListView2
    //         // anchors.fill: parent
    //         width: parent.width
    //         height: parent.height / 3

    //         model: itemList2
    //         delegate: Rectangle {
    //             height: 50
    //             radius: 10
    //             color: "dodgerblue"
    //             border.color: "cyan"
    //             width: (parent === null ?  rootId.width  : parent.width)
    //             Text {
    //                 text: modelData
    //                 font.pointSize: 20
    //                 anchors.centerIn: parent
    //                 anchors.horizontalCenter: parent.horizontalCenter
    //             }
    //         }
    //     }
    // }
}

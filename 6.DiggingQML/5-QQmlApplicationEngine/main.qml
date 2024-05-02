import QtQuick
import QtQuick.Controls

Window {
    objectName: "rootWindow"
    width: 640
    height: 480
    visible: true
    title: qsTr("QQmlApplicationEngine")

    Rectangle {
        id : rect1
        objectName: "rect"
        width: 100
        height: 100
        color: "green"
    }

    Rectangle {
        id : rect2
        anchors.top : rect1.bottom
        anchors.topMargin: 3
        objectName: "rect"
        width: 100
        height: 100
        color: "blue"
    }

    TextArea{
        id : mTextArea
        objectName: "myTextArea"
        text : "Some QML text";
        font.pointSize: 20
        anchors.left: rect1.right;
    }

    Rectangle {
        id : rect3
        anchors.left: rect1.right
        anchors.top: mTextArea.bottom
        objectName: "rect3"
        color: "yellowgreen"
        width: rect4.width //The binding is defined here
        height: 100
    }

    Rectangle {
        id : rect4
        anchors.left: rect1.right
        anchors.top: rect3.bottom
        objectName: "rect4"
        color : "beige"
        width: 100
        height: 100

        MouseArea{
            anchors.fill: parent
            onClicked: {
                rect4.width = rect4.width+20
            }
        }
    }
}

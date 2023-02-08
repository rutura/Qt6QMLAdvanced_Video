/*
        . Shoing the flow when one is working on a regular Qt Quick Project
        . Same things we've been doing with QQmlEngine apply.
        . The only diff is that now we're basing our work on QQmlApplicationEngine.
            How does it differ from QQmlEngine? I invite you to look that up in the docs.
            May be set that up as an exercise.

        . Use the Qt5 course as a reference and improvise.


  */


import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    objectName: "rootWindow"
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

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


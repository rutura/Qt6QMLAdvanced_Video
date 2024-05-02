import QtQuick
import guide.learnqt.logos

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Custom Visual Types")

    Logo{
        id: logo1Id
        text:  "Learn Qt"
        bgColor: "dodgerblue"
        textColor: "red"
    }

    Logo{
        id : logo2Id
        anchors.top : logo1Id.bottom
        anchors.topMargin: 20
        text: "Go Fluid"
        bgColor: "beige"
        textColor: "black"
        topic: Logo.QTQUICK
    }


}

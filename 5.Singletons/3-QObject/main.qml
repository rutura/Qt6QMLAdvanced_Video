import QtQuick
//import com.blikoon1.singletondata1

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QObject")

     property var myApi: SingletonClass //We instantiate the class object on the QML side.

    /*
       Rectangle {
           id : rect1Id
           width: 200
           height: 200
           radius: 10
           color: "red"

           Text {
               id: mText1Id
               anchors.centerIn: parent
               color: "white"
               font.pointSize: 30
               text: MyApi.someProperty
           }
       }

       Rectangle {
           id : rect2Id
           width: 200
           height: 200
           radius: 10
           anchors.left: rect1Id.right
           anchors.leftMargin: 20
           color: "blue"

           Text {
               id: mText2Id
               anchors.centerIn: parent
               color: "white"
               font.pointSize: 30
               text: MyApi.someProperty
           }
       }
       */

    Rectangle {
        id : rect1Id
        width: 200
        height: 200
        radius: 10
        color: "red"

        Text {
            id: mText1Id
            anchors.centerIn: parent
            color: "white"
            font.pointSize: 30
            text: myApi.someProperty
        }
    }

    Rectangle {
        id : rect2Id
        width: 200
        height: 200
        radius: 10
        anchors.left: rect1Id.right
        anchors.leftMargin: 20
        color: "blue"

        Text {
            id: mText2Id
            anchors.centerIn: parent
            color: "white"
            font.pointSize: 30
            text: myApi.someProperty
        }
    }

}

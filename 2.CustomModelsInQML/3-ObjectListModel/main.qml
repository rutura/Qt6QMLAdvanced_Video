import QtQuick
import ObjectListModel
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Object List Model")

    ListView{
        id : mListView
        anchors.fill: parent
        //model : personModel
        model : modelId
        delegate: Rectangle {
            height: 90
            radius: 10
            color : "gray"
            border.color: "cyan"
            width: root.width
            RowLayout{
                anchors.fill: parent
                anchors.margins: 20
                TextField{
                    text : names
                    Layout.fillWidth: true
                    background: Rectangle{
                        color:"white"
                    }
                }
                SpinBox{
                    editable: true
                    value : age
                    Layout.fillWidth: true
                    background: Rectangle{
                        color:"white"
                    }
                }
                Rectangle{
                    width : 50
                    height: 50
                    color: favoriteColor

                }
            }
        }
    }

    ListModel{
        id : modelId
        ListElement {
            names : "Daniel Sten"; favoriteColor : "blue"; age : 10
        }
        ListElement {
            names : "Stevie Wongers"; favoriteColor : "cyan"; age : 23
        }
        ListElement {
            names : "Nicholai Ven"; favoriteColor : "red"; age : 33
        }
        ListElement {
            names : "William Glen"; favoriteColor : "yellowgreen"; age : 45
        }
    }
}

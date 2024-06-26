import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id : root
    width: 640
    height: 480
    visible: true
    title: qsTr("Rest Client V2")

    ColumnLayout{
        anchors.fill: parent
        spacing: 0

        ListView{
            id : mListView
            model : myModel
            delegate: Rectangle{

                width : root.width
                height: textId.implicitHeight+30
                color: "beige"
                border.color: "yellowgreen"
                radius: 5

                Text {
                    width : parent.width
                    height: parent.height
                    id : textId
                    anchors.centerIn: parent
                    text : post // The role we exposed in C++
                    //text : modelData // Can also use  this
                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
            }
            Layout.fillHeight: true
            Layout.fillWidth: true
        }



        Button {
            id : mButton1
            text : "Fetch"
            Layout.fillWidth: true
            onClicked: {
                myDatasource.fetchPosts()
            }

        }
        Button {
            id : mButton2
            text : "RemoveLast"
            Layout.fillWidth: true
            onClicked: {
                myDatasource.removeLastPost()

            }

        }
    }


}

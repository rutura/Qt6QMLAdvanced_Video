import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Editable object list model")
    ListView{
        id : mListView
        anchors.fill: parent
        model : myModel
        delegate: Rectangle {
            height: 90
            radius: 10
            color : "gray"
            border.color: "cyan"
            width: parent.width
            RowLayout{
                anchors.fill: parent
                anchors.margins: 20
                TextField{
                    text : names
                    Layout.fillWidth: true
                    background: Rectangle{
                        color : "white"
                    }

                    onEditingFinished: {
                        Wrapper.setNames(index,text)
                    }
                }
                SpinBox{
                    editable: true
                    value : age
                    Layout.fillWidth: true
                    background : Rectangle{
                        color : "white"
                    }

                    onValueChanged: {
                        if( value === model.age){

                        }else{
                            Wrapper.setAge(index,value)
                        }
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

    Button{
        id : mButton
        width: parent.width
        anchors.bottom: parent.bottom
        height: 50
        text : "Add Person"
        onClicked: {
            Wrapper.addPerson()
        }
    }
}

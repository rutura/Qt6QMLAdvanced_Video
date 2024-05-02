import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QProperty Edits")
    ListView{
        id : mListView
        anchors.fill: parent
        model : Wrapper.mypersons
        delegate: Rectangle {
            height: 90
            radius: 5
            color : "gray"// Can also do modelData.favoriteColor directly but adding model makes it clear where the data is coming from. More readable
            border.color: "cyan"
            width: parent.width
            RowLayout{
                anchors.fill: parent
                anchors.margins: 20
                TextField{
                    text : modelData.names
                    Layout.fillWidth: true
                    background : Rectangle{
                        color : "white"
                    }

                    onEditingFinished: {
                        Wrapper.setNames(index,text)
                    }
                }
                SpinBox{
                    editable: true
                    value : modelData.age
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
                    color: modelData.favoriteColor
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

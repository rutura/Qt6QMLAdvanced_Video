import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import DecouplingDataSource

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Abstract List Model")

    ColumnLayout{
        anchors.fill: parent
        PersonModel{
            id: modelId
        }

        ListView{
            id : mListView
            Layout.fillWidth: true
            Layout.fillHeight: true
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
                            color : "white"
                        }

                        onEditingFinished: {
                            console.log("Editing finished, new text is :"+ text + " at index :" + index)
                            model.names = text //The roles here are defined in model class

                        }
                    }

                    SpinBox{
                        id : mSpinbox
                        editable: true
                        Layout.fillWidth: true
                        background : Rectangle{
                            color : "white"
                        }

                        onValueChanged: {
                            model.age = value;
                        }
                        Component.onCompleted: {
                            mSpinbox.value = age
                        }
                    }
                    Rectangle{
                        width : 50
                        height: 50
                        color: favoriteColor
                        MouseArea{
                            anchors.fill: parent
                            ColorDialog{
                                id: colorDialog
                                title: "Please choose a color"
                                onAccepted: {
                                    console.log("You chose: " + colorDialog.selectedColor)
                                    model.favoriteColor = colorDialog.selectedColor
                                }
                                onRejected: {
                                    console.log("Canceled")

                                }
                            }

                            onClicked: {
                                colorDialog.open()

                            }
                        }
                    }
                }
            }
        }


        RowLayout{
            width : parent.width
            Button{
                Layout.fillWidth: true
                height: 50
                text : "Add Person";
                onClicked: {
                    input.openDialog()
                }
                InputDialog{
                    id : input
                    onInputDialogAccepted: {
                        console.log("Here in main, dialog accepted");
                        console.log( " names : " + personNames + " age :" + personAge)
                        modelId.addPerson(personNames,personAge,"yellowgreen")
                    }
                }

            }
            Button{
                Layout.fillWidth: true
                height: 50
                text : "Remove Last";
                onClicked: {
                    modelId.removeLastItem()
                }
            }
        }
    }
}

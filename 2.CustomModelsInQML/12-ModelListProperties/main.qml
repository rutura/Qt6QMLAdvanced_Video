/*

        . Refactoring the code to use :
            . object list
            . default properties

        . Use the Qt 5 course as a reference and improvise.

  */

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import com.blikoon.models

Window {
    id : root
    width: 640
    height: 480
    visible: true
    minimumWidth: 400
    minimumHeight: 600
    title: qsTr("Hello World")

    PersonModel{
        id : mModeId
        Person{
            names: "Steve Barker"
            favoriteColor: "blue"
            age : 34
        }
        Person{
            names: "John Snow"
            favoriteColor: "yellow"
            age : 33
        }
        Person{
            names: "Daniel Gakwaya"
            favoriteColor: "green"
            age : 23
        }

        /*
        persons: [

            Person{
                names: "Daniel Gakwaya"
                favoriteColor: "yellow"
                age : 34
            },
            Person{
                names: "Gwiza Luna"
                favoriteColor: "blue"
                age : 1
            },
            Person{
                names: "Steve Barker"
                favoriteColor: "yellowgreen"
                age : 22
            }

        ]
        */
    }


    ColumnLayout{
        anchors.fill: parent
        ListView{
            id : mListView
            Layout.fillWidth: true
            Layout.fillHeight: true

            model : mModeId
            delegate: Rectangle {
                height: 90
                radius: 10
                color : "gray"// Can also do modelData.favoriteColor directly but adding model makes it clear where the data is coming from. More readable
                border.color: "cyan"
                width: root.width
                RowLayout{
                    anchors.fill: parent
                    anchors.margins: 20

                    TextField{
                        text : names
                        Layout.fillWidth: true
                        background : Rectangle{
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
                            color: "white"
                        }

                        onValueChanged: {
                            model.age = value;
                        }
                        Component.onCompleted: {
                            mSpinbox.value = model.age
                        }
                    }
                    Rectangle{
                        width : 50
                        height: 50
                        color: model.favoriteColor
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
                        mModeId.addPerson(personNames,"yellowgreen",personAge)
                    }
                }


            }
            Button{
                Layout.fillWidth: true
                height: 50
                text : "Remove Last";
                onClicked: {
                    mModeId.removeLastItem()
                }
            }
        }
    }
}

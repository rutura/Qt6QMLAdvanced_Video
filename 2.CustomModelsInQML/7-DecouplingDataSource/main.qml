/*
        . Decoupling the actual data storage from the model API
        . We set up a separate class for data storage and expose
            its object as a model member

         . The model now provides a clean api for the view to see the data
            trough,
         . All data manipulations will happend through the data source.
         . Reference the Slides from the Qt 5 course and improvise.


  */


import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs
import DecouplingDataSource

Window {
    id : root
    width: 640
    height: 480
    visible: true
    minimumWidth: 400
    minimumHeight: 600
    title: qsTr("External Data Source")


    ColumnLayout{
        anchors.fill: parent

        PersonModel{
            id: myModel
        }

        ListView{
            id : mListView
            Layout.fillWidth: true
            Layout.fillHeight: true

            model : myModel
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
                            color : "white"
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
                        //myDataSource.addPerson(personNames,personAge)
                        myModel.addPerson(personNames,"yellowgreen",personAge)
                    }
                }


            }
            Button{
                Layout.fillWidth: true
                height: 50
                text : "Remove Last";
                onClicked: {
                    myModel.removeLastItem()
                }
            }
        }
    }

}

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id : rootId
    function openDialog(){
        inputDialog.open()
    }

    property alias personNames : addPerNamesField.text
    property alias personAge: addPerAgeField.value
    signal inputDialogAccepted

    Dialog {
        id: inputDialog

        x: (parent.width - width) / 2
        y: (parent.height - height) / 2

        width: parent.width/2 //Breaks the binding loop introduced in Qt 5.12.
        parent: Overlay.overlay

        focus: true
        modal: true
        title: "Person data"
        standardButtons: Dialog.Ok | Dialog.Cancel

        ColumnLayout {
            spacing: 20
            anchors.fill: parent
            Label {
                elide: Label.ElideRight
                text: "Please enter the data:"
                Layout.fillWidth: true
            }
            TextField {
                id : addPerNamesField
                focus: true
                placeholderText: "Names"
                Layout.fillWidth: true
            }
            SpinBox {
                editable: true
                id : addPerAgeField
                value : 13
                Layout.fillWidth: true
            }

        }

        onAccepted: {
            console.log("Accepted adding person")
            rootId.inputDialogAccepted()

        }
        onRejected: {
            console.log("Rejected adding person")
        }
    }



}


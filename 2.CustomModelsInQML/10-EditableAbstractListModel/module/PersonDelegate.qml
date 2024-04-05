import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    height: 90
    radius: 10
    color: "gray"
    border.color: "cyan"
    width: parent === null ? 480 : parent.width

    required property string names
    required property string favoriteColor
    required property int age
    required property int index

    signal spinBoxValueChanged(var value);
    signal textFieldTextChanged(var text);

    RowLayout {
        anchors.fill: parent
        anchors.margins: 20
        TextField {
            id: textFieldId
            text: names
            Layout.fillWidth: true
            background: Rectangle {
                color: "white"
            }
            onEditingFinished: {
                textFieldTextChanged(text)
            }
        }
        SpinBox {
            id: spinBoxId
            editable: true
            value: age
            Layout.fillWidth: true
            background: Rectangle {
                color: "white"
            }
            onValueChanged: {
                spinBoxValueChanged(value);
            }
        }
        Rectangle {
            id: rectangleId
            width: 50
            height: 50
            color: favoriteColor
        }
    }
}

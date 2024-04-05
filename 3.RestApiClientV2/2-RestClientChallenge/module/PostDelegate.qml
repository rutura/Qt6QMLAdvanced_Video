import QtQuick
import QtQuick.Controls

Rectangle {
    id: delegateId
    required property var model

    width: root.width
    height: textId.implicitHeight + 30
    color: "beige"
    border.color: "yellowgreen"
    radius: 5

    Text {
        id: textId
        width: parent.width
        height: parent.height
        anchors.centerIn: parent
        text: model.title
        font.pointSize: 13
        wrapMode: Text.WordWrap
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
    }
}

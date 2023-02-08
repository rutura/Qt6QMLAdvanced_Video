import QtQuick 2.12
import QtQuick.Window
import QtQuick.Controls

Window {
    visible: true
    width: 640
    height: 480
    objectName: "ROOT OBJECT"
    title: qsTr("Hello World")

    signal qmlSignal(string value,variant mVar);

    QtObject{
        id : mPayload
        property string mProp: "QML payload data"
    }

    Button{
        id : mButton;
        text : "Button1"
        objectName: "button1"

        onClicked: {
            //Emit the signal
            qmlSignal("QML parameter",mPayload)
        }
    }
}

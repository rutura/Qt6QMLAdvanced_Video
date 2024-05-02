import QtQuick
import QtQuick.Controls

Window {
    objectName: "ROOT OBJECT"
    width: 640
    height: 480
    visible: true
    title: qsTr("Catch QML Signal")

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

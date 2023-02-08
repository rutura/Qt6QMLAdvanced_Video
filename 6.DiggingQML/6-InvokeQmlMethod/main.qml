import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Invoke QML Method")

    Item{
        objectName: "deep1";
        Item{
            objectName: "deep2"
            function qmlFunction(value){
                console.log("QML function called, the parameter is :"+ value);
                return "Return value from QML";
            }
        }
    }
}

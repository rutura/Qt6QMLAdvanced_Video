import QtQuick

Window {
    width: 640
    height: 480
    visible: true
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

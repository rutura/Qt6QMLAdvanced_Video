import QtQuick
import QtQuick.Controls
import com.blikoon.singletondata

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Singleton QJSValue Demo")
    //property var myApi: SingletonClass.getJsValue() // It's important that myApi starts with lowercase, otherwise you'll get errors.

        Button{
            id : button1Id
            text : "Click Me."
            onClicked: {
                console.log(MyApi.someProperty);

                //console.log(M yApi.mArray[0]) // Prints undefined, we din't set up anything with key 0.
                console.log(MyApi.mArray[1]) //Prints the first value

                MyApi.mArray.forEach(function(element){
                    console.log(element)
                })

            }
        }

        //Use this with the getJsValue() method
    /*
        Button{
            id : button2Id
            text : "Click Me Again!"
            //anchors.top: button1Id.bottom
            anchors.topMargin: 20
            onClicked: {
                console.log(myApi.someProperty);

                //console.log(myApi.mArray[0]) // Prints undefined, we din't set up anything with key 0.
                console.log(myApi.mArray[1]) //Prints the first value

                myApi.mArray.forEach(function(element){
                    console.log(element)
                })

            }
        }

        */
}

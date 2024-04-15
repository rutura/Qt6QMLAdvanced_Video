/*
        ATTENTION : The explanations you have for qmlRegisterSingletonType
            are not convincing. Read the docs more when making the slides
            may be as chatgpt to explain more ?


        . QJSvalue used to expose singleton static data to QML
        . Flow :
            . Set up wrapper class with singletonProvider method
                the method doesn't have to be named singletonProvider explicitely.
            . Store data in a QJSvalue object that  you return

            . Expose the provider to QML using :
                    .        qmlRegisterSingletonType("com.blikoon.singletondata",1,0,"MyApi",
                                SingletonClass::singletonProvider);

            . You can also directly expose a lambda.

             . Use the data in QML :
                         Button{
                            id : mButton
                            text : "Click Me"
                            onClicked: {
                                console.log(MyApi.someProperty);
                                //console.log(MyApi.mArray[0])
                                MyApi.mArray.forEach(function(element){
                                    console.log(element)
                                })
                            }
                        }


             . Additional way by Erick: Resource: https://doc.qt.io/qt-6/qjsvalue.html

                . You set up a method from the singleton class, here it's named getJsValue().

                    . This project creates a QJSValue in c++ and shares it with QML.

                        . You get an instance of QMLEngine associated with the current QObject.
                          ```cpp
                                  auto engine = qmlEngine(this);
                            ```
                    . Create QJSValue(s) using the acquired engines and associated names
                    . Access them simply in qml like any other variable.

             . This is useful for static data that doesn't change much.


             . ATTENTION:
                . The first two ways that use qmlRegister* work with the first button that goes through MyApi.

                . The last way that goes through getJsValue uses QML_ELEMENT AND QML_SINGLETON, work with the second button.
                . Keep this in mind to avoid errors.

  */

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

                //console.log(M yApi.mArray[0]) // Prints undefined, we din't set up anything with key 0.
                console.log(MyApi.mArray[1]) //Prints the first value

                MyApi.mArray.forEach(function(element){
                    console.log(element)
                })

            }
        }


        //Use this with the getJsValue() method
        Button{
            id : button2Id
            text : "Click Me Again!"
            anchors.top: button1Id.bottom
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
}

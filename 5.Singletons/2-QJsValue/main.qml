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

             . This is useful for static data that doesn't change much.

             . Addition by Erick: Resource: https://doc.qt.io/qt-6/qjsvalue.html

                    This project creates a QJSValue in c++ and shares it with QML.

                    ## Docs

                    - get an instance of QMLEngine associated with the current QObject.
                          ```cpp
                                  auto engine = qmlEngine(this);
                            ```
                    - Create QJSValue(s) using the acquired engines and associated names
                    - Access them simply in qml like any other variable.

  */

import QtQuick
import QtQuick.Controls
import com.blikoon.singletondata

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Singleton QJSValue Demo")
    property var myApi: SingletonClass.getJsValue()

        Button{
            id : mButton
            text : "Click Me"
            onClicked: {
                console.log(myApi.someProperty);
                //console.log(myApi.mArray[0])
                myApi.mArray.forEach(function(element){
                    console.log(element)
                })
            }
        }
        Button{
            id : mButton2
            anchors.top: mButton.bottom
            text : "Click Me2"
            onClicked: {
                console.log(myApi.someProperty);
                //console.log(myApi.mArray[0])
                myApi.mArray.forEach(function(element){
                    console.log(element)
                })
            }
        }
}

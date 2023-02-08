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

  */

import QtQuick
import QtQuick.Controls 2.5
import com.blikoon.singletondata 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Singleton QJSValue Demo")

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
        Button{
            id : mButton2
            anchors.top: mButton.bottom
            text : "Click Me2"
            onClicked: {
                console.log(MyApi.someProperty);
                //console.log(MyApi.mArray[0])
                MyApi.mArray.forEach(function(element){
                    console.log(element)
                })
            }
        }
}

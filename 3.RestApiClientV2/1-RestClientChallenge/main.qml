/*
        . Challenge Rest client storing the data in a model  :
            . API endpoint :
                    const QUrl API_ENDPOINT("https://jsonplaceholder.typicode.com/posts");

            . Take ref from Qt 5 explanations
            . Break this in steps :
                    . Use the rest client from the intermediate course as a starting point
                    . The challenge is to refactor it and store downloaded data into a C++ model
                    . Setting post and datasource classes
                        . Steal starter code from  RectClientV1 from the
                            Intermediate course and build from there.
                    . Setting up the model class
                    . Feeding to QML


            . Further challenges:
                . Use the rest additions from Qt6.7 to download the data
                . Refactor the model to be instantiable from the QML side
                    . You'll have to make a lot of design decisions of your own:
                            . Using QML_ELEMENT or qmlRegisterType
                            . Where the data source is instantiated?
                                . You can create it in C++
                                . You can also expose it as instantiable from QML and assign it as a property to the
                                    model on the QML side.


  */

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id : root
    width: 640
    height: 480
    visible: true
    title: qsTr("Rest Client V2")

    ColumnLayout{
        anchors.fill: parent
        spacing: 0

        ListView{
            id : mListView
            model : myModel
            delegate: Rectangle{

                width : root.width
                height: textId.implicitHeight+30
                color: "beige"
                border.color: "yellowgreen"
                radius: 5

                Text {
                    width : parent.width
                    height: parent.height
                    id : textId
                    anchors.centerIn: parent
                    text : post // The role we exposed in C++
                    //text : modelData // Can also use  this
                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
            }
            Layout.fillHeight: true
            Layout.fillWidth: true
        }



        Button {
            id : mButton1
            text : "Fetch"
            Layout.fillWidth: true
            onClicked: {
                myDatasource.fetchPosts()
            }

        }
        Button {
            id : mButton2
            text : "RemoveLast"
            Layout.fillWidth: true
            onClicked: {
                myDatasource.removeLastPost()

            }

        }
    }


}

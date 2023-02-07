/*
        . Exploring object list models :

                . We have a QObject based Person class
                . We create a list of person objects from C++
                . Expose the list to QML as a context property :
                    .     engine.rootContext()->setContextProperty("personModel",
                                                     QVariant::fromValue(personList));

                . We can now use the model in a ListView in QML :
                           ListView{
                                ...
                               //model : personModel
                               //model : mModelId
                               ...
                           }
                . We also set up a delegate that read person properties for name,age and favoritecolor
                    The delegate can read these properties directly because it can get them from the
                    view's model.


                . Show that you can also set up a similar model exclusively from QML :
                       ListModel{
                           id : mModelId
                           ListElement {
                               names : "Daniel Sten"; favoriteColor : "blue"; age : 10
                           }
                           ListElement {
                               names : "Stevie Wongers"; favoriteColor : "cyan"; age : 23
                           }
                           ListElement {
                               names : "Nicholai Ven"; favoriteColor : "red"; age : 33
                           }
                           ListElement {
                               names : "William Glen"; favoriteColor : "yellowgreen"; age : 45
                           }
                       }


                  . For simple models, it's better to just have the data in QML right away.
                    But sometimes the data is exclusively coming from C++ and this is one way
                    you can feed the data to QML.





  */

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    id : root
    width: 640
    height: 480
    visible: true
    title: qsTr("Object List Model Demo")

       ListView{
           id : mListView
           anchors.fill: parent
           //model : personModel
           model : mModelId
           delegate: Rectangle {
               height: 90
               radius: 10
               color : "gray"
               border.color: "cyan"
               width: root.width
               RowLayout{
                   anchors.fill: parent
                   anchors.margins: 20
                   TextField{
                       text : names
                       Layout.fillWidth: true
                       background: Rectangle{
                           color:"white"
                       }
                   }
                   SpinBox{
                       editable: true
                       value : age
                       Layout.fillWidth: true
                       background: Rectangle{
                           color:"white"
                       }
                   }
                   Rectangle{
                       width : 50
                       height: 50
                       color: favoriteColor

                   }
               }
           }
       }

       ListModel{
           id : mModelId
           ListElement {
               names : "Daniel Sten"; favoriteColor : "blue"; age : 10
           }
           ListElement {
               names : "Stevie Wongers"; favoriteColor : "cyan"; age : 23
           }
           ListElement {
               names : "Nicholai Ven"; favoriteColor : "red"; age : 33
           }
           ListElement {
               names : "William Glen"; favoriteColor : "yellowgreen"; age : 45
           }
       }
}

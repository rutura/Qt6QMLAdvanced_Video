/*
        . Editable object list model through Q_PROPERTY
        . We expose the list as a Q_PROPERTY as well :
                . Q_PROPERTY(QList<QObject*> mypersons READ mypersons
                            WRITE setMypersons NOTIFY mypersonsChanged)

        . Now changes to a single person are propagated through the Q_PROPERTY
            mechanism and only one person is changed without trigerring a reset
            of the entire list as a context property as we did in the last lecture

        . Since the list is exposed as a Q_PROPERTY itself, we emit the
                mypersonsChanged
          signal when we add change the list by adding elements, or
            removing elements if we chose to do so.

        . Add an exercise for the app to support removing items.

        . Improvise

  */

import QtQuick
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Editable object list model through Q_PROPERTIES")

      ListView{
          id : mListView
          anchors.fill: parent
          model : Wrapper.mypersons
          delegate: Rectangle {
              height: 90
              radius: 5
              color : "gray"// Can also do modelData.favoriteColor directly but adding model makes it clear where the data is coming from. More readable
              border.color: "cyan"
              width: parent.width
              RowLayout{
                  anchors.fill: parent
                  anchors.margins: 20
                  TextField{
                      text : modelData.names
                      Layout.fillWidth: true
                      background : Rectangle{
                          color : "white"
                      }

                      onEditingFinished: {
                          Wrapper.setNames(index,text)
                      }
                  }
                  SpinBox{
                      editable: true
                      value : modelData.age
                      Layout.fillWidth: true
                      background : Rectangle{
                          color : "white"
                      }

                      onValueChanged: {
                          if( value === model.age){
                          }else{
                              Wrapper.setAge(index,value)
                          }
                      }
                  }
                  Rectangle{
                      width : 50
                      height: 50
                      color: modelData.favoriteColor
                  }
              }
          }
      }

      Button{
          id : mButton
          width: parent.width
          anchors.bottom: parent.bottom
          height: 50
          text : "Add Person"
          onClicked: {
              Wrapper.addPerson()
          }
      }
}

/*
        This lecture builds on 3a-ObjectListModel by making the provided list editable. This is done with help of signals of the delegate's components.

        __Note__:
        - To make ```QQmlListProperty<Person>``` property  editable one of its three properties should be enabled. Resource: https://doc.qt.io/qt-6/qqmllistproperty.html#QML_LIST_PROPERTY_ASSIGN_BEHAVIOR_APPEND
            ```cpp
                ...
                QML_LIST_PROPERTY_ASSIGN_BEHAVIOR_APPEND
                Q_PROPERTY(QQmlListProperty<Person> persons READ getPersons NOTIFY personsChanged)
                ...
            ```
- A signal is important in order to refresh list on changes.
- ```QQmlListProperty``` translates into a js ```list``` in qml that can can be manipulated normally as an array in js. Resource: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array
-
  */

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import myModule

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Object List Model Demo")
    PersonList {
        id: personListModelId
    }
    ListView {
        id: mListView
        anchors.fill: parent
        // model : personModel // c++ model exposed as context property in main
        // model : mModelId // model created in qml
        // model: DummyListModel{}  // model creaated in qml but exposed from module myModule
        model: personListModelId.persons // c++ model exposed via module
        delegate: Component {
            // refactored delegated exposed via a module and wrapped a QQmlComponent
            PersonDelegate {
                onTextFieldTextChanged: text => {
                    // console.log("TextField text changed");
                    if (text !== null) {
                        personListModelId.persons[index].names = text;
                    }
                }
                onSpinBoxValueChanged: value => {
                    // console.log("Spinbox value changed");
                    if (value !== null) {
                        personListModelId.persons[index].age = value;
                    }
                }
            }
        }
        // setup for an in-place delegate
        // delegate: Rectangle {
        //     height: 90
        //     radius: 10
        //     color : "gray"
        //     border.color: "cyan"
        //     width: root.width
        //     RowLayout{
        //         anchors.fill: parent
        //         anchors.margins: 20
        //         TextField{
        //             text : names
        //             Layout.fillWidth: true
        //             background: Rectangle{
        //                 color:"white"
        //             }
        //         }
        //         SpinBox{
        //             editable: true
        //             value : age
        //             Layout.fillWidth: true
        //             background: Rectangle{
        //                 color:"white"
        //             }
        //         }
        //         Rectangle{
        //             width : 50
        //             height: 50
        //             color: favoriteColor

        //         }
        //     }
        // }
    }

    // ListModel{
    //     id : mModelId
    //     ListElement {
    //         names : "Daniel Sten"; favoriteColor : "blue"; age : 10
    //     }
    //     ListElement {
    //         names : "Stevie Wongers"; favoriteColor : "cyan"; age : 23
    //     }
    //     ListElement {
    //         names : "Nicholai Ven"; favoriteColor : "red"; age : 33
    //     }
    //     ListElement {
    //         names : "William Glen"; favoriteColor : "yellowgreen"; age : 45
    //     }
    // }

    property var randomPerson: Person {
        names: "John Doe from QML"
        favoriteColor: ["Red", "Blue", "Green", "Yellow"][Math.floor(Math.random() * 4)]
        age: Math.floor(Math.random() * 50) + 20
    }
    Button {
        id: mButton
        width: parent.width
        anchors.bottom: parent.bottom
        height: 50
        text: "Add Person"
        onClicked: {
            // console.log("Length before push: " + personListModelId.persons.length);
            // console.log("random person: {" + randomPerson.names+ ", " + randomPerson.favoriteColor + ", " + randomPerson.age + "}")
            personListModelId.persons.push(randomPerson);
            personListModelId.refresh();
            // console.log("Length after push: " + personListModelId.persons.length);
        }
    }
}

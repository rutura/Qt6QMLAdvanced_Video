/*

This lecture builds on 6a-AbstractListModel by demonstrating how to edit an object in the list model.


- Create an invokable method in qml to get the current object based on the current index of the model.
- Assign new values to the properties of the model.
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
    ListView {
        id: mListView
        anchors.fill: parent
        model: PersonListModel {
            id: personListModelId
        }
        delegate: Component {
            PersonDelegate {
                onSpinBoxValueChanged: value => {
                    if (value !== null) {
                        var currentPerson = personListModelId.get(index);
                        currentPerson.age = value;
                        // console.log("Current person: " + currentPerson.names + ", " + currentPerson.age)
                    }
                }
                onTextFieldTextChanged: text => {
                    if (text !== null) {
                        var currentPerson = personListModelId.get(index);
                        currentPerson.names = text;
                        // console.log("Current person: " + currentPerson.names + ", " + currentPerson.age)
                    }
                }
            }
        }
    }
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
            personListModelId.addPerson(randomPerson);
        }
    }
}

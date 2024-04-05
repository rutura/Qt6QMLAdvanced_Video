/*
    This lecture creates a ```QList``` of ```Person``` QObjects and  provides the list as a  ```QQmlListProperty```


    - Initializes a list of QObjects of type Person(inherits from QObject) in the constructor of ```PersonList```.
    - The list is then exposed as a property of ```PersonList``` as follows
          Q_PROPERTY(QQmlListProperty<Person> persons READ getPersons CONSTANT)
          CONSTANT property means we the property is a constant. Resource:[https://doc.qt.io/qt-6/properties.html](https://doc.qt.io/qt-6/properties.html)
    - ListView delegate ```PersonDelegate``` takes the properties of  ```Person``` objects and dsplays in its components.
    - Demonstrate how we can still create a list model in qml, import and use it.
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
        model: personListModelId.persons // c++ model exposed via module

        delegate: PersonDelegate{}
    }

}

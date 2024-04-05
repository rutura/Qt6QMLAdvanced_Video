/*

This lecture builds on 4a- EditableObjectListModel by replacing the list provider in 4a with a list model in c++.

- List model is an instantiable type taking advantage of the QML_ELEMENT macro.
- We also set it up as part of an external module.
- List model inherits from ```QAbstractListModel```,  a chilf QObject. This means, its meta object is accessible in QML.
- Creates roles based on the properties of Person model.
  - The rolenames used should match those required by the delegate as shown below
```qml
# PersonDelegate
...
required property string names
required property string favoriteColor
required property int age
required property int index
...
```
```cpp
# PersonListModel
...
  enum Role {
    PersonNameRole = Qt::UserRole + 1,
    PersonFavoriteColorRole,
    PersonAgeRole
  };
...
QHash<int, QByteArray> PersonListModel::roleNames() const
{
    static const QHash<int, QByteArray> result  {
        {PersonNameRole, "names"},
        {PersonFavoriteColorRole, "favoriteColor"},
        {PersonAgeRole, "age"}
    };
    return result;
}
...
  ```

- overrides data and count providers.
- To add a model to the list, the insertion procedure should be guared with
```cpp
  beginInsertRows(QModelIndex(), mPersonList.length(), mPersonList.length()); // beging guard
  mPersonList << person;//  insertion
  endInsertRows();// end guard
```
  - You can also ```beginResetModel()``` and ```endResetModel``` if you are adding a whole list.


- The model is imported and used in qml just like any other model.

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
            PersonDelegate {}
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
            personListModelId.addPerson(randomPerson)
        }
    }
}

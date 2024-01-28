# 4a- EditableObjectListModel

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




# 6a-AbstractListModel 

This lecture builds on 4a- EditableObjectListModel by replacing the list provider in 4a with a list model in c++. 

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
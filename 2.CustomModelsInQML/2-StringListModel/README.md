# 2-StringListModel 

- Exposing simple stringLists as models from C++ for use in QML
- Use the docs and the Qt5 course as reference.

## Changes

- Added support to expose more than one model using 
  ```cpp 
  setContextProperties(QList<PropertyPair>)
  ```
- Demonstrated how to use [reference Initialization](https://en.cppreference.com/w/cpp/language/reference_initialization) to compact initialization. 
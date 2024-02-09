# 2-QJSValue

Resource: https://doc.qt.io/qt-6/qjsvalue.html

This project creates a QJSValue in c++ and shares it with QML. 

## Docs 

- get an instance of QMLEngine associated with the current QObject. 
  ```cpp 
  auto engine = qmlEngine(this);
  ```
- Create QJSValue(s) using the acquired engines and associated names
- Access them simply in qml like any other variable. 
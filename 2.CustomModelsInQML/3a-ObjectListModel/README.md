# 3a-ObjectsModel
 - Exploring object list models :

    - We have a QObject based Person class
    - We create a list of person objects from C++
    - Expose the list to QML as a context property :
    ```cpp
      engine.rootContext()->setContextProperty("personModel",
                                            QVariant::fromValue(personList));

    ```
    - We can now use the model in a ListView in QML :
     ```qml
     ListView{
            ...
            //model : personModel
            //model : mModelId
            ...
        }
    ```
                   
    - We also set up a delegate that read person properties for name,age and favoritecolor
        - The delegate can read these properties directly because it can get them from the
            view's model.
   - Show that you can also set up a similar model exclusively from QML :

        ```qml 

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
        ```

        - For simple models, it's better to just have the data in QML right away.
            But sometimes the data is exclusively coming from C++ and this is one way
            you can feed the data to QML.

## Changes 


- made the person model a module using cmake's 
```cmake
...
qt_add_qml_module(${LIB_NAME}
    URI ${MODULE_NAME}
    VERSION 1.0
    RESOURCE_PREFIX /
    SOURCES
        ${MODULE_SRC_FILES}
    QML_FILES
        ${MODULE_QML_FILES}
    OUTPUT_DIRECTORY
      "${CMAKE_BINARY_DIR}/${MODULE_NAME}"
)
...
```

- Demonstrated how the delegate can also be part of the module 
- Demonstrated how you can still expose the qml list model from a module
- Finally the list of objects from a module





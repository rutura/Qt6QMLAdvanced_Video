/*
    . Exposing singleton data from QML :

        . Flow:
            . Set up a new QML file: QmlSingleton and put in the content
            . Add the needed properties in the CMakeLists.txt file:
                    set_source_files_properties(QmlSingleton.qml PROPERTIES
                        QT_QML_SINGLETON_TYPE TRUE
                    )
                    qt_target_qml_sources(appQMLSingleton
                        QML_FILES QmlSingleton.qml
                    )
            . Import the module in the main.qml file:
                . import com.blikoon.qmlsingleton
            . Use it in the onCompleted handler.
            Resource:
                - https://doc.qt.io/qt-6/cmake-source-file-property-qt-qml-singleton-type.html
                - https://doc.qt.io/qt-6/qt-target-qml-sources.html#qt-target-qml-sources-example

            ## Changes
                - updated cmake to set the source file properties of the ```Singleton``` qml file.

  */

import QtQuick
import com.blikoon.qmlsingleton

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Singleton QML Demo")

    Component.onCompleted: {
        console.log(QmlSingleton.testProperty);
    }
}

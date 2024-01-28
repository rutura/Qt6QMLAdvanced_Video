set(MODULE_NAME myModule)
set(LIB_NAME ${MODULE_NAME}Lib) 

qt_add_library(${LIB_NAME} STATIC)

set_target_properties(${LIB_NAME} PROPERTIES AUTOMOC ON)
target_link_libraries(${LIB_NAME} PRIVATE Qt6::Quick)

list(APPEND MODULE_SRC_FILES person.h person.cpp)
list(APPEND MODULE_QML_FILES PersonDelegate.qml DummyListModel.qml)

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

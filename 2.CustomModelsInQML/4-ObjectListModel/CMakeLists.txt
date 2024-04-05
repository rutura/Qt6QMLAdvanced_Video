cmake_minimum_required(VERSION 3.16)

project(4-ObjectListModel VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick QuickControls2 REQUIRED)

qt_add_executable(appObjectListModel
    main.cpp
)

add_subdirectory(module)

qt_add_qml_module(appObjectListModel
    URI ObjectListModel
    VERSION 1.0
    QML_FILES main.qml 
)

set_target_properties(appObjectListModel PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN3a2_EXECUTABLE TRUE
)

target_compile_definitions(appObjectListModel
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(appObjectListModel
    PRIVATE Qt6::Quick
    PRIVATE Qt6::QuickControls2
    PRIVATE myModuleLibplugin
)

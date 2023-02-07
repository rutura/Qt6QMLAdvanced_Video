cmake_minimum_required(VERSION 3.16)

project(3-ObjectListModel VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick QuickControls2 REQUIRED)

qt_add_executable(app3-ObjectListModel
    main.cpp person.h person.cpp
)

qt_add_qml_module(app3-ObjectListModel
    URI 3-ObjectListModel
    VERSION 1.0
    QML_FILES main.qml 
)

set_target_properties(app3-ObjectListModel PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(app3-ObjectListModel
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(app3-ObjectListModel
    PRIVATE Qt6::Quick
    PRIVATE Qt6::QuickControls2)

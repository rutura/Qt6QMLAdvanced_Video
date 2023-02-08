cmake_minimum_required(VERSION 3.16)

project(4-BarchartListProps VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(app4-BarchartListProps
    main.cpp stair.h stair.cpp stairchart.h stairchart.cpp
)

qt_add_qml_module(app4-BarchartListProps
    URI 4-BarchartListProps
    VERSION 1.0
    QML_FILES main.qml 
)

set_target_properties(app4-BarchartListProps PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(app4-BarchartListProps
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(app4-BarchartListProps
    PRIVATE Qt6::Quick)

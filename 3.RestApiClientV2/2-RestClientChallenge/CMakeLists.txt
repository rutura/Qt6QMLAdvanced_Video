cmake_minimum_required(VERSION 3.16)

project(2-RestClientChallenge VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick QuickControls2 REQUIRED)

qt_add_executable(app2-RestClientChallenge
    main.cpp post.h post.cpp postmodel.h postmodel.cpp datasource.h datasource.cpp appwrapper.h appwrapper.cpp
)

qt_add_qml_module(app2-RestClientChallenge
    URI 2-RestClientChallenge
    VERSION 1.0
    QML_FILES main.qml 
)

set_target_properties(app2-RestClientChallenge PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(app2-RestClientChallenge
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(app2-RestClientChallenge
    PRIVATE Qt6::Quick
    PRIVATE Qt6::QuickControls2)

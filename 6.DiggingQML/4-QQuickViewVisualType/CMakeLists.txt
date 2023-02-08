cmake_minimum_required(VERSION 3.14)

project(4-QQuickViewVisualType LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick Qml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick Qml)

add_executable(4-QQuickViewVisualType
  main.cpp qml.qrc
)
target_link_libraries(4-QQuickViewVisualType Qt${QT_VERSION_MAJOR}::Core
Qt${QT_VERSION_MAJOR}::Quick
Qt${QT_VERSION_MAJOR}::Qml)

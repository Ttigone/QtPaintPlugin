cmake_minimum_required(VERSION 3.16)

project(testPlugin LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

add_library(testPlugin SHARED
  testPlugin_global.hpp
  TestPlugin.cpp
  TestPlugin.hpp
  paintersharedinterface.h
  test.json
)

target_link_libraries(testPlugin PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)

target_compile_definitions(testPlugin PRIVATE TESTPLUGIN_LIBRARY)

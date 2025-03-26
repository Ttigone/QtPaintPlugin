cmake_minimum_required(VERSION 3.16)

project(TextPlugin LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Gui Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Gui Core)

add_library(${PROJECT_NAME} STATIC
  TextPlugin.cpp
  TextPlugin.h
  painterinterface.h
  info.json
)

# 启用位置独立代码，静态插件需要
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)


if(WIN32)
    target_link_options(${PROJECT_NAME} PRIVATE -static -static-libgcc -static-libstdc++)
endif()

# 添加Qt插件定义
target_compile_definitions(${PROJECT_NAME} PRIVATE
    QT_STATICPLUGIN
    TEXTPLUGIN_LIBRARY
)

target_compile_definitions(TextPlugin PRIVATE QT_PLUGIN)

target_include_directories(${PROJECT_NAME} PRIVATE "${PARENT_DIR}/source/")

target_link_libraries(${PROJECT_NAME}
PUBLIC
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Core
)

# 获取目标链接的库
get_target_property(LINKED_LIBS ${PROJECT_NAME} LINK_LIBRARIES)
# 输出链接库列表
message("${PROJECT_NAME} Link: ${LINKED_LIBS}")

configure_file(info.json ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/info.json COPYONLY)

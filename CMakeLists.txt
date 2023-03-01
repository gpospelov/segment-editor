cmake_minimum_required(VERSION 3.13.5)
project(coa-qml-sandbox VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

option(COA_USE_QT6 "Compile with Qt6" ON)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(configuration)

add_subdirectory(src)
add_subdirectory(test)


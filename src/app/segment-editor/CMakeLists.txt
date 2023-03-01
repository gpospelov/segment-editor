set(executable_name segment-editor)

add_executable(${executable_name} main.cpp ${CMAKE_CURRENT_LIST_DIR}/qml/segment-editor.qrc)

target_link_libraries(${executable_name} PUBLIC Qt${QT_VERSION_MAJOR}::Qml  segment-editor-core)
target_include_directories(${executable_name} PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>)

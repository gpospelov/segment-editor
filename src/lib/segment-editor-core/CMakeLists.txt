set(library_name segment-editor-core)

add_library(${library_name} SHARED "")
add_subdirectory(segment-editor)

target_link_libraries(${library_name} PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)

target_include_directories(${library_name} PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>)

include(CTest)
include(GNUInstallDirs)

# -----------------------------------------------------------------------------
# Directories
# -----------------------------------------------------------------------------

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

file(MAKE_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# -----------------------------------------------------------------------------
# Dependencies
# -----------------------------------------------------------------------------

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Threads)

if (COA_USE_QT6)
  find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets Core Gui Qml Test)
else()
  find_package(QT NAMES Qt5 REQUIRED COMPONENTS Widgets Core Gui Qml Test)
endif()

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Core Gui Qml Test)
message(STATUS "Qt${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}.${QT_VERSION_PATCH} found")
message(STATUS " Includes: ${Qt${QT_VERSION_MAJOR}Widgets_INCLUDE_DIRS}")
get_target_property(QtWidgets_location Qt${QT_VERSION_MAJOR}::Core LOCATION_Release)
message(STATUS " Core library: ${QtWidgets_location}")

find_package(Threads)

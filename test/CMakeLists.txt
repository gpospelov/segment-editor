enable_testing()

find_package(GTest 1.10 QUIET CONFIG)

if (GTest_FOUND)
  message(STATUS "Found GTest: suitable version \"${GTest_VERSION}\", with minimum required \"1.10\"" )
else()
  message(STATUS "GTest with version >= \"1.10\" was not found, fetching from internet" )
  fetch_googletest()
endif()

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Core Test REQUIRED)
find_package(Threads)
include(GoogleTest)

add_subdirectory(testsegment-editor-core)

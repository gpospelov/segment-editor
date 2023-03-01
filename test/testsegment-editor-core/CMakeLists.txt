set(test testsegment-editor-core)

file(GLOB source_files "*.cpp")
file(GLOB include_files "*.h")

add_executable(${test} ${source_files} ${include_files})

target_link_libraries(${test} PRIVATE pthread GTest::gtest GTest::gmock segment-editor-core)

gtest_discover_tests(${test})

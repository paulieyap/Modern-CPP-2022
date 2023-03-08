find_package(Catch2 REQUIRED)
include(Catch)

set(TEST_BINARY ${PROJECT_NAME}_ci_test)
add_executable(${TEST_BINARY} test_serialize.cpp test_convert_dataset.cpp)
target_link_libraries(${TEST_BINARY} homework_5 Catch2::Catch2WithMain)
catch_discover_tests(${TEST_BINARY} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

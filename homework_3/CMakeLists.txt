cmake_minimum_required(VERSION 3.1)
project(homework_3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(TEST_BINARY ${PROJECT_NAME})

enable_testing()
add_subdirectory(tests) 

add_library(homework_3_h src/html_writer.cpp src/image_browser.cpp)
add_executable(main src/homework_3.cpp)
target_link_libraries (main PRIVATE homework_3_h) 

add_library(homework_3 INTERFACE)
target_link_libraries (homework_3 INTERFACE homework_3_h) 
target_include_directories(homework_3 INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/api>)

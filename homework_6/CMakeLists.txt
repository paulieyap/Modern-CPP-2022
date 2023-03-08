cmake_minimum_required(VERSION 3.1)
project(homework_6)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

# set(TEST_BINARY ${PROJECT_NAME})

# add_subdirectory(src)

# add_library(homework_6_lib src/image_class.cpp src/io_tools.cpp io_tools/io_tools.cpp)
# add_library(image_class src/image_class.cpp)
# add_library(io_tools src/io_tools.cpp)

# add_library(homework_6_lib image_class io_tools)
# set( CMAKE_CXX_FLAGS " -Wall -Wextra ")
add_library(homework_6_lib src/image_class.cpp src/io_tools.cpp)

add_executable(main src/main.cpp)
target_link_libraries (main PUBLIC homework_6_lib) 
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fPIC")

add_library(homework_6 INTERFACE)
target_link_libraries (homework_6 INTERFACE homework_6_lib) 
target_include_directories(homework_6 INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_compile_features (homework_6 INTERFACE cxx_std_17)

enable_testing()
add_subdirectory(tests) 
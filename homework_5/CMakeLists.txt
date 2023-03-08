cmake_minimum_required(VERSION 3.1)
project(homework_5)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)



find_package(OpenCV 4.6 REQUIRED)
if(OpenCV_FOUND)
  message(STATUS "Found OpenCV version ${OpenCV_VERSION}")
  message(STATUS "OpenCV directories: ${OpenCV_INCLUDE_DIRS}")
else()
  message(FATAL_ERROR "OpenCV not found, please read the README.md")
endif(OpenCV_FOUND)



add_library(homework_5_lib src/convert_dataset.cpp src/serialize.cpp)
target_link_libraries (homework_5_lib PUBLIC ${OpenCV_LIBS}) 

add_executable(main src/main.cpp)
target_link_libraries (main PUBLIC homework_5_lib) 

add_library(homework_5 INTERFACE)
target_link_libraries (homework_5 INTERFACE homework_5_lib) 
target_include_directories(homework_5 INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_compile_features (homework_5 INTERFACE cxx_std_17 )

enable_testing()
add_subdirectory(tests) 

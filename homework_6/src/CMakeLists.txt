
add_library(image_class image_class.cpp)
add_library(io_tools io_tools.cpp)

target_link_libraries(image_class io_tools)

add_executable(main main.cpp)

target_link_libraries(main image)

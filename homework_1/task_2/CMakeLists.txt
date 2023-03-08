cmake_minimum_required(VERSION 3.1)  
project(test_ipb_arithmetic)               
set(CMAKE_CXX_STANDARD 17)         

file(MAKE_DIRECTORY ../results/lib)
file(MAKE_DIRECTORY ../results/bin)
file(MAKE_DIRECTORY install)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../results/bin")

include_directories ( include/ )

add_library (ipb_arithmetic src/subtract.cpp src/sum.cpp)

add_executable(test_ipb_arithmetic src/main.cpp) #main.o

target_link_libraries (test_ipb_arithmetic ipb_arithmetic)

execute_process(COMMAND ../results/bin/test_ipb_arithmetic)

#file(COPY build/results/bin/test_ipb_arithmetic DESTINATION ./results/bin)
add_custom_target(run
    COMMAND /results/bin/test_ipb_arithmetic
    # DEPENDS binary
    # WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
set(CMAKE_INSTALL_PREFIX ./install)

install(DIRECTORY include DESTINATION ./install)
#install(DIRECTORY ../results/lib DESTINATION ../install)
#install(TARGETS test_ipb_arithmetic)


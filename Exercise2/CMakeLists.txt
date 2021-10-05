cmake_minimum_required(VERSION 3.10)
# Uncomment if required:
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Exercise3)

add_executable(exercise3
    main.cpp
    state_machine.cpp
    stimuli.cpp
)

target_include_directories(exercise3
    PRIVATE $ENV{SYSTEMC_HOME}/include/
)

find_library(SYSTEMC_LIBRARY 
    NAMES systemc
    PATHS $ENV{SYSTEMC_HOME}/lib-$ENV{SYSTEMC_TARGET_ARCH}/
)

target_link_libraries(exercise3
    PRIVATE ${SYSTEMC_LIBRARY}
)

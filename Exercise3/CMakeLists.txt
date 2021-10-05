cmake_minimum_required(VERSION 3.10)
# Uncomment if required:
#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Exercise6)

add_executable(exercise6
    main.cpp
    memory.h
    processor.h
    bus.h
    
    stimuli1.txt
    stimuli2.txt
)

target_include_directories(exercise6
    PRIVATE $ENV{SYSTEMC_HOME}/include/
)

find_library(SYSTEMC_LIBRARY 
    NAMES systemc
    PATHS $ENV{SYSTEMC_HOME}/lib-$ENV{SYSTEMC_TARGET_ARCH}/
)

target_link_libraries(exercise6
    PRIVATE ${SYSTEMC_LIBRARY}
)

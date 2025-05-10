
cmake_minimum_required(VERSION 3.10)
project(RubiksCube2x2)

set(CMAKE_CXX_STANDARD 17)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
if (NOT SFML_FOUND)
    message(FATAL_ERROR "SFML not found. Please set SFML_ROOT environment variable.")
endif()
include_directories(${SFML_INCLUDE_DIR})

set(SOURCE_FILES
    main.cpp
    cube2x2.cpp
    cube_logic.cpp
)

add_executable(RubiksCube2x2 ${SOURCE_FILES})

target_link_libraries(RubiksCube2x2
    sfml-graphics
    sfml-window
    sfml-system
)
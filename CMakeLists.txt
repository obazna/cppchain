cmake_minimum_required(VERSION 3.0.0)
project(cppchain VERSION 0.1.0)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

# Tests
include(CTest)
enable_testing()

# External dependencies
add_subdirectory(lib EXCLUDE_FROM_ALL)

# It is always easier to navigate in an IDE when projects are organized in folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Sources
set(
    SOURCES
    ${PROJECT_SOURCE_DIR}/block.cpp
    ${PROJECT_SOURCE_DIR}/blockchain.cpp
    ${PROJECT_SOURCE_DIR}/cppchain.cpp
)

# Executable
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

# Includes
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE_DIR})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE lib/picosha2)

# Compiler options
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# Libraries
target_link_libraries(${CMAKE_PROJECT_NAME} fmt spdlog)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
cmake_minimum_required (VERSION 3.12)

project(matrix-logging)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-D_UNICODE -DUNICODE)
set(CMAKE_OBJECT_PATH_MAX 512)
enable_testing()

# PrecompiledHeader.cmake from https://github.com/larsch/cmake-precompiled-header
include(./cmake/PrecompiledHeader.cmake)


#[[ ]]
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=gnu++0x)
endif()


# Include sub-projects.

add_subdirectory ("src")
add_subdirectory ("tests")




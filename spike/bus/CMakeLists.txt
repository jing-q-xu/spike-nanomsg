#
# Demonstration CMakeLists.txt for nanomsg demos.
#
# This file shows how one might use nanomsg from a another project
# that is also CMake-driven.
#
# Thanks for the idea goes to @maddouri.
#
cmake_minimum_required (VERSION 2.8.7)

project(demo)

# Call this from your own project's makefile.
find_package(nanomsg CONFIG REQUIRED)
include_directories(../include/)

add_executable(send node.cpp send_demo.cpp)
target_link_libraries(send nanomsg)

add_executable(receive node.cpp receive_demo.cpp)
target_link_libraries(receive nanomsg)

add_executable(duplex node.cpp duplex.cpp)
target_link_libraries(duplex nanomsg)


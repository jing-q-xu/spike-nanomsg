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

add_executable(bus bus.c)
target_link_libraries(bus nanomsg)

add_executable(broker node.cpp broker.cpp broker_demo.cpp)
target_link_libraries(broker nanomsg)

add_executable(client node.cpp client.cpp client_demo.cpp)
target_link_libraries(client nanomsg)


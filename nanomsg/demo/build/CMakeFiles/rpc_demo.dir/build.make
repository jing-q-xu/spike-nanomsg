# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jqxu/code/nanomsg/nanomsg/demo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jqxu/code/nanomsg/nanomsg/demo/build

# Include any dependencies generated for this target.
include CMakeFiles/rpc_demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rpc_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rpc_demo.dir/flags.make

CMakeFiles/rpc_demo.dir/rpc_demo.c.o: CMakeFiles/rpc_demo.dir/flags.make
CMakeFiles/rpc_demo.dir/rpc_demo.c.o: ../rpc_demo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jqxu/code/nanomsg/nanomsg/demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rpc_demo.dir/rpc_demo.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rpc_demo.dir/rpc_demo.c.o   -c /Users/jqxu/code/nanomsg/nanomsg/demo/rpc_demo.c

CMakeFiles/rpc_demo.dir/rpc_demo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rpc_demo.dir/rpc_demo.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/jqxu/code/nanomsg/nanomsg/demo/rpc_demo.c > CMakeFiles/rpc_demo.dir/rpc_demo.c.i

CMakeFiles/rpc_demo.dir/rpc_demo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rpc_demo.dir/rpc_demo.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/jqxu/code/nanomsg/nanomsg/demo/rpc_demo.c -o CMakeFiles/rpc_demo.dir/rpc_demo.c.s

# Object files for target rpc_demo
rpc_demo_OBJECTS = \
"CMakeFiles/rpc_demo.dir/rpc_demo.c.o"

# External object files for target rpc_demo
rpc_demo_EXTERNAL_OBJECTS =

rpc_demo: CMakeFiles/rpc_demo.dir/rpc_demo.c.o
rpc_demo: CMakeFiles/rpc_demo.dir/build.make
rpc_demo: /usr/local/lib/libnanomsg.5.1.0.dylib
rpc_demo: CMakeFiles/rpc_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jqxu/code/nanomsg/nanomsg/demo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable rpc_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rpc_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rpc_demo.dir/build: rpc_demo

.PHONY : CMakeFiles/rpc_demo.dir/build

CMakeFiles/rpc_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rpc_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rpc_demo.dir/clean

CMakeFiles/rpc_demo.dir/depend:
	cd /Users/jqxu/code/nanomsg/nanomsg/demo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jqxu/code/nanomsg/nanomsg/demo /Users/jqxu/code/nanomsg/nanomsg/demo /Users/jqxu/code/nanomsg/nanomsg/demo/build /Users/jqxu/code/nanomsg/nanomsg/demo/build /Users/jqxu/code/nanomsg/nanomsg/demo/build/CMakeFiles/rpc_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rpc_demo.dir/depend

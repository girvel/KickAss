# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/nik/Downloads/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/nik/Downloads/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nik/CLionProjects/KickAss

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nik/CLionProjects/KickAss/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SDL2Test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SDL2Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDL2Test.dir/flags.make

CMakeFiles/SDL2Test.dir/main.c.o: CMakeFiles/SDL2Test.dir/flags.make
CMakeFiles/SDL2Test.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nik/CLionProjects/KickAss/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SDL2Test.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SDL2Test.dir/main.c.o   -c /home/nik/CLionProjects/KickAss/main.c

CMakeFiles/SDL2Test.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SDL2Test.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nik/CLionProjects/KickAss/main.c > CMakeFiles/SDL2Test.dir/main.c.i

CMakeFiles/SDL2Test.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SDL2Test.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nik/CLionProjects/KickAss/main.c -o CMakeFiles/SDL2Test.dir/main.c.s

# Object files for target SDL2Test
SDL2Test_OBJECTS = \
"CMakeFiles/SDL2Test.dir/main.c.o"

# External object files for target SDL2Test
SDL2Test_EXTERNAL_OBJECTS =

SDL2Test: CMakeFiles/SDL2Test.dir/main.c.o
SDL2Test: CMakeFiles/SDL2Test.dir/build.make
SDL2Test: CMakeFiles/SDL2Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nik/CLionProjects/KickAss/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SDL2Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL2Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SDL2Test.dir/build: SDL2Test

.PHONY : CMakeFiles/SDL2Test.dir/build

CMakeFiles/SDL2Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SDL2Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SDL2Test.dir/clean

CMakeFiles/SDL2Test.dir/depend:
	cd /home/nik/CLionProjects/KickAss/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nik/CLionProjects/KickAss /home/nik/CLionProjects/KickAss /home/nik/CLionProjects/KickAss/cmake-build-debug /home/nik/CLionProjects/KickAss/cmake-build-debug /home/nik/CLionProjects/KickAss/cmake-build-debug/CMakeFiles/SDL2Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SDL2Test.dir/depend

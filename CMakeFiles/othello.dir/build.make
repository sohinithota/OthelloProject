# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/16305/Downloads/othello-project-sohinithota

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/16305/Downloads/othello-project-sohinithota

# Include any dependencies generated for this target.
include CMakeFiles/othello.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/othello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/othello.dir/flags.make

CMakeFiles/othello.dir/othello.c.o: CMakeFiles/othello.dir/flags.make
CMakeFiles/othello.dir/othello.c.o: othello.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/16305/Downloads/othello-project-sohinithota/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/othello.dir/othello.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/othello.dir/othello.c.o   -c /mnt/c/Users/16305/Downloads/othello-project-sohinithota/othello.c

CMakeFiles/othello.dir/othello.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/othello.dir/othello.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/16305/Downloads/othello-project-sohinithota/othello.c > CMakeFiles/othello.dir/othello.c.i

CMakeFiles/othello.dir/othello.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/othello.dir/othello.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/16305/Downloads/othello-project-sohinithota/othello.c -o CMakeFiles/othello.dir/othello.c.s

# Object files for target othello
othello_OBJECTS = \
"CMakeFiles/othello.dir/othello.c.o"

# External object files for target othello
othello_EXTERNAL_OBJECTS =

bin/othello: CMakeFiles/othello.dir/othello.c.o
bin/othello: CMakeFiles/othello.dir/build.make
bin/othello: CMakeFiles/othello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/16305/Downloads/othello-project-sohinithota/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bin/othello"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/othello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/othello.dir/build: bin/othello

.PHONY : CMakeFiles/othello.dir/build

CMakeFiles/othello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/othello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/othello.dir/clean

CMakeFiles/othello.dir/depend:
	cd /mnt/c/Users/16305/Downloads/othello-project-sohinithota && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/16305/Downloads/othello-project-sohinithota /mnt/c/Users/16305/Downloads/othello-project-sohinithota /mnt/c/Users/16305/Downloads/othello-project-sohinithota /mnt/c/Users/16305/Downloads/othello-project-sohinithota /mnt/c/Users/16305/Downloads/othello-project-sohinithota/CMakeFiles/othello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/othello.dir/depend

# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kdj6724/Test/DataStructure/Sort/Heap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kdj6724/Test/DataStructure/Sort/Heap/build

# Include any dependencies generated for this target.
include CMakeFiles/sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sort.dir/flags.make

CMakeFiles/sort.dir/src/main.cpp.o: CMakeFiles/sort.dir/flags.make
CMakeFiles/sort.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kdj6724/Test/DataStructure/Sort/Heap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sort.dir/src/main.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sort.dir/src/main.cpp.o -c /Users/kdj6724/Test/DataStructure/Sort/Heap/src/main.cpp

CMakeFiles/sort.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sort.dir/src/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kdj6724/Test/DataStructure/Sort/Heap/src/main.cpp > CMakeFiles/sort.dir/src/main.cpp.i

CMakeFiles/sort.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sort.dir/src/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kdj6724/Test/DataStructure/Sort/Heap/src/main.cpp -o CMakeFiles/sort.dir/src/main.cpp.s

CMakeFiles/sort.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/sort.dir/src/main.cpp.o.requires

CMakeFiles/sort.dir/src/main.cpp.o.provides: CMakeFiles/sort.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/sort.dir/build.make CMakeFiles/sort.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/sort.dir/src/main.cpp.o.provides

CMakeFiles/sort.dir/src/main.cpp.o.provides.build: CMakeFiles/sort.dir/src/main.cpp.o


# Object files for target sort
sort_OBJECTS = \
"CMakeFiles/sort.dir/src/main.cpp.o"

# External object files for target sort
sort_EXTERNAL_OBJECTS =

sort: CMakeFiles/sort.dir/src/main.cpp.o
sort: CMakeFiles/sort.dir/build.make
sort: CMakeFiles/sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kdj6724/Test/DataStructure/Sort/Heap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sort.dir/build: sort

.PHONY : CMakeFiles/sort.dir/build

CMakeFiles/sort.dir/requires: CMakeFiles/sort.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/sort.dir/requires

CMakeFiles/sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sort.dir/clean

CMakeFiles/sort.dir/depend:
	cd /Users/kdj6724/Test/DataStructure/Sort/Heap/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kdj6724/Test/DataStructure/Sort/Heap /Users/kdj6724/Test/DataStructure/Sort/Heap /Users/kdj6724/Test/DataStructure/Sort/Heap/build /Users/kdj6724/Test/DataStructure/Sort/Heap/build /Users/kdj6724/Test/DataStructure/Sort/Heap/build/CMakeFiles/sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sort.dir/depend


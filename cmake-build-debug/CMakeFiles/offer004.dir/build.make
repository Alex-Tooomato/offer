# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/pc/clion-2021.3.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/pc/clion-2021.3.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pc/leetcode/offer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pc/leetcode/offer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/offer004.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/offer004.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/offer004.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/offer004.dir/flags.make

CMakeFiles/offer004.dir/offer突击004.cpp.o: CMakeFiles/offer004.dir/flags.make
CMakeFiles/offer004.dir/offer突击004.cpp.o: ../offer突击004.cpp
CMakeFiles/offer004.dir/offer突击004.cpp.o: CMakeFiles/offer004.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pc/leetcode/offer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/offer004.dir/offer突击004.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/offer004.dir/offer突击004.cpp.o -MF CMakeFiles/offer004.dir/offer突击004.cpp.o.d -o CMakeFiles/offer004.dir/offer突击004.cpp.o -c /home/pc/leetcode/offer/offer突击004.cpp

CMakeFiles/offer004.dir/offer突击004.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/offer004.dir/offer突击004.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pc/leetcode/offer/offer突击004.cpp > CMakeFiles/offer004.dir/offer突击004.cpp.i

CMakeFiles/offer004.dir/offer突击004.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/offer004.dir/offer突击004.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pc/leetcode/offer/offer突击004.cpp -o CMakeFiles/offer004.dir/offer突击004.cpp.s

# Object files for target offer004
offer004_OBJECTS = \
"CMakeFiles/offer004.dir/offer突击004.cpp.o"

# External object files for target offer004
offer004_EXTERNAL_OBJECTS =

offer004: CMakeFiles/offer004.dir/offer突击004.cpp.o
offer004: CMakeFiles/offer004.dir/build.make
offer004: CMakeFiles/offer004.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pc/leetcode/offer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable offer004"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/offer004.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/offer004.dir/build: offer004
.PHONY : CMakeFiles/offer004.dir/build

CMakeFiles/offer004.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/offer004.dir/cmake_clean.cmake
.PHONY : CMakeFiles/offer004.dir/clean

CMakeFiles/offer004.dir/depend:
	cd /home/pc/leetcode/offer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pc/leetcode/offer /home/pc/leetcode/offer /home/pc/leetcode/offer/cmake-build-debug /home/pc/leetcode/offer/cmake-build-debug /home/pc/leetcode/offer/cmake-build-debug/CMakeFiles/offer004.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/offer004.dir/depend


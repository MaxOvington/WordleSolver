# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/MCMO/Documents/CODE/WordleSolver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/MCMO/Documents/CODE/WordleSolver/build

# Include any dependencies generated for this target.
include src/CMakeFiles/graph.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/graph.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/graph.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/graph.dir/flags.make

src/CMakeFiles/graph.dir/graph.cpp.o: src/CMakeFiles/graph.dir/flags.make
src/CMakeFiles/graph.dir/graph.cpp.o: /home/MCMO/Documents/CODE/WordleSolver/src/graph.cpp
src/CMakeFiles/graph.dir/graph.cpp.o: src/CMakeFiles/graph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/MCMO/Documents/CODE/WordleSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/graph.dir/graph.cpp.o"
	cd /home/MCMO/Documents/CODE/WordleSolver/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/graph.dir/graph.cpp.o -MF CMakeFiles/graph.dir/graph.cpp.o.d -o CMakeFiles/graph.dir/graph.cpp.o -c /home/MCMO/Documents/CODE/WordleSolver/src/graph.cpp

src/CMakeFiles/graph.dir/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/graph.dir/graph.cpp.i"
	cd /home/MCMO/Documents/CODE/WordleSolver/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/MCMO/Documents/CODE/WordleSolver/src/graph.cpp > CMakeFiles/graph.dir/graph.cpp.i

src/CMakeFiles/graph.dir/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/graph.dir/graph.cpp.s"
	cd /home/MCMO/Documents/CODE/WordleSolver/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/MCMO/Documents/CODE/WordleSolver/src/graph.cpp -o CMakeFiles/graph.dir/graph.cpp.s

src/CMakeFiles/graph.dir/process.cpp.o: src/CMakeFiles/graph.dir/flags.make
src/CMakeFiles/graph.dir/process.cpp.o: /home/MCMO/Documents/CODE/WordleSolver/src/process.cpp
src/CMakeFiles/graph.dir/process.cpp.o: src/CMakeFiles/graph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/MCMO/Documents/CODE/WordleSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/graph.dir/process.cpp.o"
	cd /home/MCMO/Documents/CODE/WordleSolver/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/graph.dir/process.cpp.o -MF CMakeFiles/graph.dir/process.cpp.o.d -o CMakeFiles/graph.dir/process.cpp.o -c /home/MCMO/Documents/CODE/WordleSolver/src/process.cpp

src/CMakeFiles/graph.dir/process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/graph.dir/process.cpp.i"
	cd /home/MCMO/Documents/CODE/WordleSolver/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/MCMO/Documents/CODE/WordleSolver/src/process.cpp > CMakeFiles/graph.dir/process.cpp.i

src/CMakeFiles/graph.dir/process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/graph.dir/process.cpp.s"
	cd /home/MCMO/Documents/CODE/WordleSolver/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/MCMO/Documents/CODE/WordleSolver/src/process.cpp -o CMakeFiles/graph.dir/process.cpp.s

src/CMakeFiles/graph.dir/entropy.cpp.o: src/CMakeFiles/graph.dir/flags.make
src/CMakeFiles/graph.dir/entropy.cpp.o: /home/MCMO/Documents/CODE/WordleSolver/src/entropy.cpp
src/CMakeFiles/graph.dir/entropy.cpp.o: src/CMakeFiles/graph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/MCMO/Documents/CODE/WordleSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/graph.dir/entropy.cpp.o"
	cd /home/MCMO/Documents/CODE/WordleSolver/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/graph.dir/entropy.cpp.o -MF CMakeFiles/graph.dir/entropy.cpp.o.d -o CMakeFiles/graph.dir/entropy.cpp.o -c /home/MCMO/Documents/CODE/WordleSolver/src/entropy.cpp

src/CMakeFiles/graph.dir/entropy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/graph.dir/entropy.cpp.i"
	cd /home/MCMO/Documents/CODE/WordleSolver/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/MCMO/Documents/CODE/WordleSolver/src/entropy.cpp > CMakeFiles/graph.dir/entropy.cpp.i

src/CMakeFiles/graph.dir/entropy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/graph.dir/entropy.cpp.s"
	cd /home/MCMO/Documents/CODE/WordleSolver/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/MCMO/Documents/CODE/WordleSolver/src/entropy.cpp -o CMakeFiles/graph.dir/entropy.cpp.s

# Object files for target graph
graph_OBJECTS = \
"CMakeFiles/graph.dir/graph.cpp.o" \
"CMakeFiles/graph.dir/process.cpp.o" \
"CMakeFiles/graph.dir/entropy.cpp.o"

# External object files for target graph
graph_EXTERNAL_OBJECTS =

src/libgraph.a: src/CMakeFiles/graph.dir/graph.cpp.o
src/libgraph.a: src/CMakeFiles/graph.dir/process.cpp.o
src/libgraph.a: src/CMakeFiles/graph.dir/entropy.cpp.o
src/libgraph.a: src/CMakeFiles/graph.dir/build.make
src/libgraph.a: src/CMakeFiles/graph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/MCMO/Documents/CODE/WordleSolver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libgraph.a"
	cd /home/MCMO/Documents/CODE/WordleSolver/build/src && $(CMAKE_COMMAND) -P CMakeFiles/graph.dir/cmake_clean_target.cmake
	cd /home/MCMO/Documents/CODE/WordleSolver/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graph.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/graph.dir/build: src/libgraph.a
.PHONY : src/CMakeFiles/graph.dir/build

src/CMakeFiles/graph.dir/clean:
	cd /home/MCMO/Documents/CODE/WordleSolver/build/src && $(CMAKE_COMMAND) -P CMakeFiles/graph.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/graph.dir/clean

src/CMakeFiles/graph.dir/depend:
	cd /home/MCMO/Documents/CODE/WordleSolver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/MCMO/Documents/CODE/WordleSolver /home/MCMO/Documents/CODE/WordleSolver/src /home/MCMO/Documents/CODE/WordleSolver/build /home/MCMO/Documents/CODE/WordleSolver/build/src /home/MCMO/Documents/CODE/WordleSolver/build/src/CMakeFiles/graph.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/graph.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/solly/code/cpp/suite-of-tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/solly/code/cpp/suite-of-tests/build

# Include any dependencies generated for this target.
include CMakeFiles/test_all.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_all.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_all.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_all.dir/flags.make

CMakeFiles/test_all.dir/test.cpp.o: CMakeFiles/test_all.dir/flags.make
CMakeFiles/test_all.dir/test.cpp.o: ../test.cpp
CMakeFiles/test_all.dir/test.cpp.o: CMakeFiles/test_all.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solly/code/cpp/suite-of-tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_all.dir/test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_all.dir/test.cpp.o -MF CMakeFiles/test_all.dir/test.cpp.o.d -o CMakeFiles/test_all.dir/test.cpp.o -c /home/solly/code/cpp/suite-of-tests/test.cpp

CMakeFiles/test_all.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_all.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solly/code/cpp/suite-of-tests/test.cpp > CMakeFiles/test_all.dir/test.cpp.i

CMakeFiles/test_all.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_all.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solly/code/cpp/suite-of-tests/test.cpp -o CMakeFiles/test_all.dir/test.cpp.s

CMakeFiles/test_all.dir/thing_test.cpp.o: CMakeFiles/test_all.dir/flags.make
CMakeFiles/test_all.dir/thing_test.cpp.o: ../thing_test.cpp
CMakeFiles/test_all.dir/thing_test.cpp.o: CMakeFiles/test_all.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solly/code/cpp/suite-of-tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_all.dir/thing_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_all.dir/thing_test.cpp.o -MF CMakeFiles/test_all.dir/thing_test.cpp.o.d -o CMakeFiles/test_all.dir/thing_test.cpp.o -c /home/solly/code/cpp/suite-of-tests/thing_test.cpp

CMakeFiles/test_all.dir/thing_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_all.dir/thing_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solly/code/cpp/suite-of-tests/thing_test.cpp > CMakeFiles/test_all.dir/thing_test.cpp.i

CMakeFiles/test_all.dir/thing_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_all.dir/thing_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solly/code/cpp/suite-of-tests/thing_test.cpp -o CMakeFiles/test_all.dir/thing_test.cpp.s

CMakeFiles/test_all.dir/thing.cpp.o: CMakeFiles/test_all.dir/flags.make
CMakeFiles/test_all.dir/thing.cpp.o: ../thing.cpp
CMakeFiles/test_all.dir/thing.cpp.o: CMakeFiles/test_all.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/solly/code/cpp/suite-of-tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_all.dir/thing.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_all.dir/thing.cpp.o -MF CMakeFiles/test_all.dir/thing.cpp.o.d -o CMakeFiles/test_all.dir/thing.cpp.o -c /home/solly/code/cpp/suite-of-tests/thing.cpp

CMakeFiles/test_all.dir/thing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_all.dir/thing.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/solly/code/cpp/suite-of-tests/thing.cpp > CMakeFiles/test_all.dir/thing.cpp.i

CMakeFiles/test_all.dir/thing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_all.dir/thing.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/solly/code/cpp/suite-of-tests/thing.cpp -o CMakeFiles/test_all.dir/thing.cpp.s

# Object files for target test_all
test_all_OBJECTS = \
"CMakeFiles/test_all.dir/test.cpp.o" \
"CMakeFiles/test_all.dir/thing_test.cpp.o" \
"CMakeFiles/test_all.dir/thing.cpp.o"

# External object files for target test_all
test_all_EXTERNAL_OBJECTS =

test_all: CMakeFiles/test_all.dir/test.cpp.o
test_all: CMakeFiles/test_all.dir/thing_test.cpp.o
test_all: CMakeFiles/test_all.dir/thing.cpp.o
test_all: CMakeFiles/test_all.dir/build.make
test_all: CMakeFiles/test_all.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/solly/code/cpp/suite-of-tests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test_all"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_all.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_all.dir/build: test_all
.PHONY : CMakeFiles/test_all.dir/build

CMakeFiles/test_all.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_all.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_all.dir/clean

CMakeFiles/test_all.dir/depend:
	cd /home/solly/code/cpp/suite-of-tests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/solly/code/cpp/suite-of-tests /home/solly/code/cpp/suite-of-tests /home/solly/code/cpp/suite-of-tests/build /home/solly/code/cpp/suite-of-tests/build /home/solly/code/cpp/suite-of-tests/build/CMakeFiles/test_all.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_all.dir/depend


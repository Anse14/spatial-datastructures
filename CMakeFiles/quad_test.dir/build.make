# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /home/anxy/cursos/EDA/labs/lab5/spatial-datastructures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anxy/cursos/EDA/labs/lab5/spatial-datastructures

# Include any dependencies generated for this target.
include CMakeFiles/quad_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/quad_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/quad_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/quad_test.dir/flags.make

CMakeFiles/quad_test.dir/quad_test.cpp.o: CMakeFiles/quad_test.dir/flags.make
CMakeFiles/quad_test.dir/quad_test.cpp.o: quad_test.cpp
CMakeFiles/quad_test.dir/quad_test.cpp.o: CMakeFiles/quad_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anxy/cursos/EDA/labs/lab5/spatial-datastructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/quad_test.dir/quad_test.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/quad_test.dir/quad_test.cpp.o -MF CMakeFiles/quad_test.dir/quad_test.cpp.o.d -o CMakeFiles/quad_test.dir/quad_test.cpp.o -c /home/anxy/cursos/EDA/labs/lab5/spatial-datastructures/quad_test.cpp

CMakeFiles/quad_test.dir/quad_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/quad_test.dir/quad_test.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anxy/cursos/EDA/labs/lab5/spatial-datastructures/quad_test.cpp > CMakeFiles/quad_test.dir/quad_test.cpp.i

CMakeFiles/quad_test.dir/quad_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/quad_test.dir/quad_test.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anxy/cursos/EDA/labs/lab5/spatial-datastructures/quad_test.cpp -o CMakeFiles/quad_test.dir/quad_test.cpp.s

# Object files for target quad_test
quad_test_OBJECTS = \
"CMakeFiles/quad_test.dir/quad_test.cpp.o"

# External object files for target quad_test
quad_test_EXTERNAL_OBJECTS =

quad_test: CMakeFiles/quad_test.dir/quad_test.cpp.o
quad_test: CMakeFiles/quad_test.dir/build.make
quad_test: lib/libgtest_main.a
quad_test: lib/libgtest.a
quad_test: CMakeFiles/quad_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anxy/cursos/EDA/labs/lab5/spatial-datastructures/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable quad_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quad_test.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=quad_test -D TEST_EXECUTABLE=/home/anxy/cursos/EDA/labs/lab5/spatial-datastructures/quad_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/anxy/cursos/EDA/labs/lab5/spatial-datastructures -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=quad_test_TESTS -D CTEST_FILE=/home/anxy/cursos/EDA/labs/lab5/spatial-datastructures/quad_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake-3.20/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/quad_test.dir/build: quad_test
.PHONY : CMakeFiles/quad_test.dir/build

CMakeFiles/quad_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/quad_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/quad_test.dir/clean

CMakeFiles/quad_test.dir/depend:
	cd /home/anxy/cursos/EDA/labs/lab5/spatial-datastructures && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anxy/cursos/EDA/labs/lab5/spatial-datastructures /home/anxy/cursos/EDA/labs/lab5/spatial-datastructures /home/anxy/cursos/EDA/labs/lab5/spatial-datastructures /home/anxy/cursos/EDA/labs/lab5/spatial-datastructures /home/anxy/cursos/EDA/labs/lab5/spatial-datastructures/CMakeFiles/quad_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/quad_test.dir/depend


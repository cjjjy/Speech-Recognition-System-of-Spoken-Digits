# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.0.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.0.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wengsht/Course/speech/hw/master/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wengsht/Course/speech/hw/master/src/build

# Include any dependencies generated for this target.
include Capture/CMakeFiles/Capture.dir/depend.make

# Include the progress variables for this target.
include Capture/CMakeFiles/Capture.dir/progress.make

# Include the compile flags for this target's objects.
include Capture/CMakeFiles/Capture.dir/flags.make

Capture/CMakeFiles/Capture.dir/AutoCapture.cpp.o: Capture/CMakeFiles/Capture.dir/flags.make
Capture/CMakeFiles/Capture.dir/AutoCapture.cpp.o: ../Capture/AutoCapture.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/wengsht/Course/speech/hw/master/src/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Capture/CMakeFiles/Capture.dir/AutoCapture.cpp.o"
	cd /Users/wengsht/Course/speech/hw/master/src/build/Capture && /usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Capture.dir/AutoCapture.cpp.o -c /Users/wengsht/Course/speech/hw/master/src/Capture/AutoCapture.cpp

Capture/CMakeFiles/Capture.dir/AutoCapture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Capture.dir/AutoCapture.cpp.i"
	cd /Users/wengsht/Course/speech/hw/master/src/build/Capture && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/wengsht/Course/speech/hw/master/src/Capture/AutoCapture.cpp > CMakeFiles/Capture.dir/AutoCapture.cpp.i

Capture/CMakeFiles/Capture.dir/AutoCapture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Capture.dir/AutoCapture.cpp.s"
	cd /Users/wengsht/Course/speech/hw/master/src/build/Capture && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/wengsht/Course/speech/hw/master/src/Capture/AutoCapture.cpp -o CMakeFiles/Capture.dir/AutoCapture.cpp.s

Capture/CMakeFiles/Capture.dir/AutoCapture.cpp.o.requires:
.PHONY : Capture/CMakeFiles/Capture.dir/AutoCapture.cpp.o.requires

Capture/CMakeFiles/Capture.dir/AutoCapture.cpp.o.provides: Capture/CMakeFiles/Capture.dir/AutoCapture.cpp.o.requires
	$(MAKE) -f Capture/CMakeFiles/Capture.dir/build.make Capture/CMakeFiles/Capture.dir/AutoCapture.cpp.o.provides.build
.PHONY : Capture/CMakeFiles/Capture.dir/AutoCapture.cpp.o.provides

Capture/CMakeFiles/Capture.dir/AutoCapture.cpp.o.provides.build: Capture/CMakeFiles/Capture.dir/AutoCapture.cpp.o

Capture/CMakeFiles/Capture.dir/Capture.cpp.o: Capture/CMakeFiles/Capture.dir/flags.make
Capture/CMakeFiles/Capture.dir/Capture.cpp.o: ../Capture/Capture.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/wengsht/Course/speech/hw/master/src/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Capture/CMakeFiles/Capture.dir/Capture.cpp.o"
	cd /Users/wengsht/Course/speech/hw/master/src/build/Capture && /usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Capture.dir/Capture.cpp.o -c /Users/wengsht/Course/speech/hw/master/src/Capture/Capture.cpp

Capture/CMakeFiles/Capture.dir/Capture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Capture.dir/Capture.cpp.i"
	cd /Users/wengsht/Course/speech/hw/master/src/build/Capture && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/wengsht/Course/speech/hw/master/src/Capture/Capture.cpp > CMakeFiles/Capture.dir/Capture.cpp.i

Capture/CMakeFiles/Capture.dir/Capture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Capture.dir/Capture.cpp.s"
	cd /Users/wengsht/Course/speech/hw/master/src/build/Capture && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/wengsht/Course/speech/hw/master/src/Capture/Capture.cpp -o CMakeFiles/Capture.dir/Capture.cpp.s

Capture/CMakeFiles/Capture.dir/Capture.cpp.o.requires:
.PHONY : Capture/CMakeFiles/Capture.dir/Capture.cpp.o.requires

Capture/CMakeFiles/Capture.dir/Capture.cpp.o.provides: Capture/CMakeFiles/Capture.dir/Capture.cpp.o.requires
	$(MAKE) -f Capture/CMakeFiles/Capture.dir/build.make Capture/CMakeFiles/Capture.dir/Capture.cpp.o.provides.build
.PHONY : Capture/CMakeFiles/Capture.dir/Capture.cpp.o.provides

Capture/CMakeFiles/Capture.dir/Capture.cpp.o.provides.build: Capture/CMakeFiles/Capture.dir/Capture.cpp.o

# Object files for target Capture
Capture_OBJECTS = \
"CMakeFiles/Capture.dir/AutoCapture.cpp.o" \
"CMakeFiles/Capture.dir/Capture.cpp.o"

# External object files for target Capture
Capture_EXTERNAL_OBJECTS =

Capture/libCapture.a: Capture/CMakeFiles/Capture.dir/AutoCapture.cpp.o
Capture/libCapture.a: Capture/CMakeFiles/Capture.dir/Capture.cpp.o
Capture/libCapture.a: Capture/CMakeFiles/Capture.dir/build.make
Capture/libCapture.a: Capture/CMakeFiles/Capture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libCapture.a"
	cd /Users/wengsht/Course/speech/hw/master/src/build/Capture && $(CMAKE_COMMAND) -P CMakeFiles/Capture.dir/cmake_clean_target.cmake
	cd /Users/wengsht/Course/speech/hw/master/src/build/Capture && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Capture.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Capture/CMakeFiles/Capture.dir/build: Capture/libCapture.a
.PHONY : Capture/CMakeFiles/Capture.dir/build

Capture/CMakeFiles/Capture.dir/requires: Capture/CMakeFiles/Capture.dir/AutoCapture.cpp.o.requires
Capture/CMakeFiles/Capture.dir/requires: Capture/CMakeFiles/Capture.dir/Capture.cpp.o.requires
.PHONY : Capture/CMakeFiles/Capture.dir/requires

Capture/CMakeFiles/Capture.dir/clean:
	cd /Users/wengsht/Course/speech/hw/master/src/build/Capture && $(CMAKE_COMMAND) -P CMakeFiles/Capture.dir/cmake_clean.cmake
.PHONY : Capture/CMakeFiles/Capture.dir/clean

Capture/CMakeFiles/Capture.dir/depend:
	cd /Users/wengsht/Course/speech/hw/master/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wengsht/Course/speech/hw/master/src /Users/wengsht/Course/speech/hw/master/src/Capture /Users/wengsht/Course/speech/hw/master/src/build /Users/wengsht/Course/speech/hw/master/src/build/Capture /Users/wengsht/Course/speech/hw/master/src/build/Capture/CMakeFiles/Capture.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Capture/CMakeFiles/Capture.dir/depend


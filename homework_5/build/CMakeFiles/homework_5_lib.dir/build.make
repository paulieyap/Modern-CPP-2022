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
CMAKE_SOURCE_DIR = /home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5/build

# Include any dependencies generated for this target.
include CMakeFiles/homework_5_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/homework_5_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/homework_5_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/homework_5_lib.dir/flags.make

CMakeFiles/homework_5_lib.dir/src/convert_dataset.cpp.o: CMakeFiles/homework_5_lib.dir/flags.make
CMakeFiles/homework_5_lib.dir/src/convert_dataset.cpp.o: ../src/convert_dataset.cpp
CMakeFiles/homework_5_lib.dir/src/convert_dataset.cpp.o: CMakeFiles/homework_5_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/homework_5_lib.dir/src/convert_dataset.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/homework_5_lib.dir/src/convert_dataset.cpp.o -MF CMakeFiles/homework_5_lib.dir/src/convert_dataset.cpp.o.d -o CMakeFiles/homework_5_lib.dir/src/convert_dataset.cpp.o -c /home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5/src/convert_dataset.cpp

CMakeFiles/homework_5_lib.dir/src/convert_dataset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/homework_5_lib.dir/src/convert_dataset.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5/src/convert_dataset.cpp > CMakeFiles/homework_5_lib.dir/src/convert_dataset.cpp.i

CMakeFiles/homework_5_lib.dir/src/convert_dataset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/homework_5_lib.dir/src/convert_dataset.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5/src/convert_dataset.cpp -o CMakeFiles/homework_5_lib.dir/src/convert_dataset.cpp.s

CMakeFiles/homework_5_lib.dir/src/serialize.cpp.o: CMakeFiles/homework_5_lib.dir/flags.make
CMakeFiles/homework_5_lib.dir/src/serialize.cpp.o: ../src/serialize.cpp
CMakeFiles/homework_5_lib.dir/src/serialize.cpp.o: CMakeFiles/homework_5_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/homework_5_lib.dir/src/serialize.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/homework_5_lib.dir/src/serialize.cpp.o -MF CMakeFiles/homework_5_lib.dir/src/serialize.cpp.o.d -o CMakeFiles/homework_5_lib.dir/src/serialize.cpp.o -c /home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5/src/serialize.cpp

CMakeFiles/homework_5_lib.dir/src/serialize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/homework_5_lib.dir/src/serialize.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5/src/serialize.cpp > CMakeFiles/homework_5_lib.dir/src/serialize.cpp.i

CMakeFiles/homework_5_lib.dir/src/serialize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/homework_5_lib.dir/src/serialize.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5/src/serialize.cpp -o CMakeFiles/homework_5_lib.dir/src/serialize.cpp.s

# Object files for target homework_5_lib
homework_5_lib_OBJECTS = \
"CMakeFiles/homework_5_lib.dir/src/convert_dataset.cpp.o" \
"CMakeFiles/homework_5_lib.dir/src/serialize.cpp.o"

# External object files for target homework_5_lib
homework_5_lib_EXTERNAL_OBJECTS =

libhomework_5_lib.a: CMakeFiles/homework_5_lib.dir/src/convert_dataset.cpp.o
libhomework_5_lib.a: CMakeFiles/homework_5_lib.dir/src/serialize.cpp.o
libhomework_5_lib.a: CMakeFiles/homework_5_lib.dir/build.make
libhomework_5_lib.a: CMakeFiles/homework_5_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libhomework_5_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/homework_5_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/homework_5_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/homework_5_lib.dir/build: libhomework_5_lib.a
.PHONY : CMakeFiles/homework_5_lib.dir/build

CMakeFiles/homework_5_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/homework_5_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/homework_5_lib.dir/clean

CMakeFiles/homework_5_lib.dir/depend:
	cd /home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5 /home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5 /home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5/build /home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5/build /home/paulieyap/Documents/MSR7/cpp-homeworks/homework_5/build/CMakeFiles/homework_5_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/homework_5_lib.dir/depend


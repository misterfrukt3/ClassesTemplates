# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /snap/cmake/1441/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1441/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/misterfrukt/CS-Labs/ClassesTemplates_Labs/myCalculate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/misterfrukt/CS-Labs/ClassesTemplates_Labs/myCalculate/build

# Include any dependencies generated for this target.
include CMakeFiles/myCalculate.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/myCalculate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/myCalculate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myCalculate.dir/flags.make

CMakeFiles/myCalculate.dir/codegen:
.PHONY : CMakeFiles/myCalculate.dir/codegen

CMakeFiles/myCalculate.dir/myCalculate.cpp.o: CMakeFiles/myCalculate.dir/flags.make
CMakeFiles/myCalculate.dir/myCalculate.cpp.o: /home/misterfrukt/CS-Labs/ClassesTemplates_Labs/myCalculate/myCalculate.cpp
CMakeFiles/myCalculate.dir/myCalculate.cpp.o: CMakeFiles/myCalculate.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/misterfrukt/CS-Labs/ClassesTemplates_Labs/myCalculate/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myCalculate.dir/myCalculate.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myCalculate.dir/myCalculate.cpp.o -MF CMakeFiles/myCalculate.dir/myCalculate.cpp.o.d -o CMakeFiles/myCalculate.dir/myCalculate.cpp.o -c /home/misterfrukt/CS-Labs/ClassesTemplates_Labs/myCalculate/myCalculate.cpp

CMakeFiles/myCalculate.dir/myCalculate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myCalculate.dir/myCalculate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/misterfrukt/CS-Labs/ClassesTemplates_Labs/myCalculate/myCalculate.cpp > CMakeFiles/myCalculate.dir/myCalculate.cpp.i

CMakeFiles/myCalculate.dir/myCalculate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myCalculate.dir/myCalculate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/misterfrukt/CS-Labs/ClassesTemplates_Labs/myCalculate/myCalculate.cpp -o CMakeFiles/myCalculate.dir/myCalculate.cpp.s

# Object files for target myCalculate
myCalculate_OBJECTS = \
"CMakeFiles/myCalculate.dir/myCalculate.cpp.o"

# External object files for target myCalculate
myCalculate_EXTERNAL_OBJECTS =

libmyCalculate.a: CMakeFiles/myCalculate.dir/myCalculate.cpp.o
libmyCalculate.a: CMakeFiles/myCalculate.dir/build.make
libmyCalculate.a: CMakeFiles/myCalculate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/misterfrukt/CS-Labs/ClassesTemplates_Labs/myCalculate/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmyCalculate.a"
	$(CMAKE_COMMAND) -P CMakeFiles/myCalculate.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myCalculate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myCalculate.dir/build: libmyCalculate.a
.PHONY : CMakeFiles/myCalculate.dir/build

CMakeFiles/myCalculate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myCalculate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myCalculate.dir/clean

CMakeFiles/myCalculate.dir/depend:
	cd /home/misterfrukt/CS-Labs/ClassesTemplates_Labs/myCalculate/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/misterfrukt/CS-Labs/ClassesTemplates_Labs/myCalculate /home/misterfrukt/CS-Labs/ClassesTemplates_Labs/myCalculate /home/misterfrukt/CS-Labs/ClassesTemplates_Labs/myCalculate/build /home/misterfrukt/CS-Labs/ClassesTemplates_Labs/myCalculate/build /home/misterfrukt/CS-Labs/ClassesTemplates_Labs/myCalculate/build/CMakeFiles/myCalculate.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/myCalculate.dir/depend


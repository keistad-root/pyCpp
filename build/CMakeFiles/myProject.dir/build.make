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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ychoi/source/pyCpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ychoi/source/pyCpp/build

# Include any dependencies generated for this target.
include CMakeFiles/myProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/myProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/myProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myProject.dir/flags.make

CMakeFiles/myProject.dir/src/cppargs.cpp.o: CMakeFiles/myProject.dir/flags.make
CMakeFiles/myProject.dir/src/cppargs.cpp.o: /Users/ychoi/source/pyCpp/src/cppargs.cpp
CMakeFiles/myProject.dir/src/cppargs.cpp.o: CMakeFiles/myProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ychoi/source/pyCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myProject.dir/src/cppargs.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myProject.dir/src/cppargs.cpp.o -MF CMakeFiles/myProject.dir/src/cppargs.cpp.o.d -o CMakeFiles/myProject.dir/src/cppargs.cpp.o -c /Users/ychoi/source/pyCpp/src/cppargs.cpp

CMakeFiles/myProject.dir/src/cppargs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/myProject.dir/src/cppargs.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ychoi/source/pyCpp/src/cppargs.cpp > CMakeFiles/myProject.dir/src/cppargs.cpp.i

CMakeFiles/myProject.dir/src/cppargs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/myProject.dir/src/cppargs.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ychoi/source/pyCpp/src/cppargs.cpp -o CMakeFiles/myProject.dir/src/cppargs.cpp.s

# Object files for target myProject
myProject_OBJECTS = \
"CMakeFiles/myProject.dir/src/cppargs.cpp.o"

# External object files for target myProject
myProject_EXTERNAL_OBJECTS =

libmyProject.dylib: CMakeFiles/myProject.dir/src/cppargs.cpp.o
libmyProject.dylib: CMakeFiles/myProject.dir/build.make
libmyProject.dylib: CMakeFiles/myProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ychoi/source/pyCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libmyProject.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myProject.dir/build: libmyProject.dylib
.PHONY : CMakeFiles/myProject.dir/build

CMakeFiles/myProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myProject.dir/clean

CMakeFiles/myProject.dir/depend:
	cd /Users/ychoi/source/pyCpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ychoi/source/pyCpp /Users/ychoi/source/pyCpp /Users/ychoi/source/pyCpp/build /Users/ychoi/source/pyCpp/build /Users/ychoi/source/pyCpp/build/CMakeFiles/myProject.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/myProject.dir/depend

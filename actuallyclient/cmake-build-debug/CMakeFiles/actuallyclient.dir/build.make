# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /cygdrive/c/Users/Igor/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Igor/.CLion2019.2/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/Igor/CLionProjects/actuallyclient

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/Igor/CLionProjects/actuallyclient/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/actuallyclient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/actuallyclient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/actuallyclient.dir/flags.make

CMakeFiles/actuallyclient.dir/client.cpp.o: CMakeFiles/actuallyclient.dir/flags.make
CMakeFiles/actuallyclient.dir/client.cpp.o: ../client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/Igor/CLionProjects/actuallyclient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/actuallyclient.dir/client.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/actuallyclient.dir/client.cpp.o -c /cygdrive/c/Users/Igor/CLionProjects/actuallyclient/client.cpp

CMakeFiles/actuallyclient.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/actuallyclient.dir/client.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/Igor/CLionProjects/actuallyclient/client.cpp > CMakeFiles/actuallyclient.dir/client.cpp.i

CMakeFiles/actuallyclient.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/actuallyclient.dir/client.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/Igor/CLionProjects/actuallyclient/client.cpp -o CMakeFiles/actuallyclient.dir/client.cpp.s

# Object files for target actuallyclient
actuallyclient_OBJECTS = \
"CMakeFiles/actuallyclient.dir/client.cpp.o"

# External object files for target actuallyclient
actuallyclient_EXTERNAL_OBJECTS =

actuallyclient.exe: CMakeFiles/actuallyclient.dir/client.cpp.o
actuallyclient.exe: CMakeFiles/actuallyclient.dir/build.make
actuallyclient.exe: CMakeFiles/actuallyclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/Igor/CLionProjects/actuallyclient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable actuallyclient.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/actuallyclient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/actuallyclient.dir/build: actuallyclient.exe

.PHONY : CMakeFiles/actuallyclient.dir/build

CMakeFiles/actuallyclient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/actuallyclient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/actuallyclient.dir/clean

CMakeFiles/actuallyclient.dir/depend:
	cd /cygdrive/c/Users/Igor/CLionProjects/actuallyclient/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/Igor/CLionProjects/actuallyclient /cygdrive/c/Users/Igor/CLionProjects/actuallyclient /cygdrive/c/Users/Igor/CLionProjects/actuallyclient/cmake-build-debug /cygdrive/c/Users/Igor/CLionProjects/actuallyclient/cmake-build-debug /cygdrive/c/Users/Igor/CLionProjects/actuallyclient/cmake-build-debug/CMakeFiles/actuallyclient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/actuallyclient.dir/depend

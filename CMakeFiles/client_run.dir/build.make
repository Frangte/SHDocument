# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nakhoadl/workspace/SHDocument

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nakhoadl/workspace/SHDocument

# Include any dependencies generated for this target.
include CMakeFiles/client_run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client_run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client_run.dir/flags.make

CMakeFiles/client_run.dir/client/Client.cpp.o: CMakeFiles/client_run.dir/flags.make
CMakeFiles/client_run.dir/client/Client.cpp.o: client/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nakhoadl/workspace/SHDocument/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client_run.dir/client/Client.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client_run.dir/client/Client.cpp.o -c /home/nakhoadl/workspace/SHDocument/client/Client.cpp

CMakeFiles/client_run.dir/client/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client_run.dir/client/Client.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nakhoadl/workspace/SHDocument/client/Client.cpp > CMakeFiles/client_run.dir/client/Client.cpp.i

CMakeFiles/client_run.dir/client/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client_run.dir/client/Client.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nakhoadl/workspace/SHDocument/client/Client.cpp -o CMakeFiles/client_run.dir/client/Client.cpp.s

CMakeFiles/client_run.dir/client/Client.cpp.o.requires:

.PHONY : CMakeFiles/client_run.dir/client/Client.cpp.o.requires

CMakeFiles/client_run.dir/client/Client.cpp.o.provides: CMakeFiles/client_run.dir/client/Client.cpp.o.requires
	$(MAKE) -f CMakeFiles/client_run.dir/build.make CMakeFiles/client_run.dir/client/Client.cpp.o.provides.build
.PHONY : CMakeFiles/client_run.dir/client/Client.cpp.o.provides

CMakeFiles/client_run.dir/client/Client.cpp.o.provides.build: CMakeFiles/client_run.dir/client/Client.cpp.o


CMakeFiles/client_run.dir/handler/Handler.cpp.o: CMakeFiles/client_run.dir/flags.make
CMakeFiles/client_run.dir/handler/Handler.cpp.o: handler/Handler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nakhoadl/workspace/SHDocument/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/client_run.dir/handler/Handler.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client_run.dir/handler/Handler.cpp.o -c /home/nakhoadl/workspace/SHDocument/handler/Handler.cpp

CMakeFiles/client_run.dir/handler/Handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client_run.dir/handler/Handler.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nakhoadl/workspace/SHDocument/handler/Handler.cpp > CMakeFiles/client_run.dir/handler/Handler.cpp.i

CMakeFiles/client_run.dir/handler/Handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client_run.dir/handler/Handler.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nakhoadl/workspace/SHDocument/handler/Handler.cpp -o CMakeFiles/client_run.dir/handler/Handler.cpp.s

CMakeFiles/client_run.dir/handler/Handler.cpp.o.requires:

.PHONY : CMakeFiles/client_run.dir/handler/Handler.cpp.o.requires

CMakeFiles/client_run.dir/handler/Handler.cpp.o.provides: CMakeFiles/client_run.dir/handler/Handler.cpp.o.requires
	$(MAKE) -f CMakeFiles/client_run.dir/build.make CMakeFiles/client_run.dir/handler/Handler.cpp.o.provides.build
.PHONY : CMakeFiles/client_run.dir/handler/Handler.cpp.o.provides

CMakeFiles/client_run.dir/handler/Handler.cpp.o.provides.build: CMakeFiles/client_run.dir/handler/Handler.cpp.o


CMakeFiles/client_run.dir/misc/client.cpp.o: CMakeFiles/client_run.dir/flags.make
CMakeFiles/client_run.dir/misc/client.cpp.o: misc/client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nakhoadl/workspace/SHDocument/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/client_run.dir/misc/client.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client_run.dir/misc/client.cpp.o -c /home/nakhoadl/workspace/SHDocument/misc/client.cpp

CMakeFiles/client_run.dir/misc/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client_run.dir/misc/client.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nakhoadl/workspace/SHDocument/misc/client.cpp > CMakeFiles/client_run.dir/misc/client.cpp.i

CMakeFiles/client_run.dir/misc/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client_run.dir/misc/client.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nakhoadl/workspace/SHDocument/misc/client.cpp -o CMakeFiles/client_run.dir/misc/client.cpp.s

CMakeFiles/client_run.dir/misc/client.cpp.o.requires:

.PHONY : CMakeFiles/client_run.dir/misc/client.cpp.o.requires

CMakeFiles/client_run.dir/misc/client.cpp.o.provides: CMakeFiles/client_run.dir/misc/client.cpp.o.requires
	$(MAKE) -f CMakeFiles/client_run.dir/build.make CMakeFiles/client_run.dir/misc/client.cpp.o.provides.build
.PHONY : CMakeFiles/client_run.dir/misc/client.cpp.o.provides

CMakeFiles/client_run.dir/misc/client.cpp.o.provides.build: CMakeFiles/client_run.dir/misc/client.cpp.o


# Object files for target client_run
client_run_OBJECTS = \
"CMakeFiles/client_run.dir/client/Client.cpp.o" \
"CMakeFiles/client_run.dir/handler/Handler.cpp.o" \
"CMakeFiles/client_run.dir/misc/client.cpp.o"

# External object files for target client_run
client_run_EXTERNAL_OBJECTS =

client_run: CMakeFiles/client_run.dir/client/Client.cpp.o
client_run: CMakeFiles/client_run.dir/handler/Handler.cpp.o
client_run: CMakeFiles/client_run.dir/misc/client.cpp.o
client_run: CMakeFiles/client_run.dir/build.make
client_run: CMakeFiles/client_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nakhoadl/workspace/SHDocument/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable client_run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client_run.dir/build: client_run

.PHONY : CMakeFiles/client_run.dir/build

CMakeFiles/client_run.dir/requires: CMakeFiles/client_run.dir/client/Client.cpp.o.requires
CMakeFiles/client_run.dir/requires: CMakeFiles/client_run.dir/handler/Handler.cpp.o.requires
CMakeFiles/client_run.dir/requires: CMakeFiles/client_run.dir/misc/client.cpp.o.requires

.PHONY : CMakeFiles/client_run.dir/requires

CMakeFiles/client_run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client_run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client_run.dir/clean

CMakeFiles/client_run.dir/depend:
	cd /home/nakhoadl/workspace/SHDocument && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nakhoadl/workspace/SHDocument /home/nakhoadl/workspace/SHDocument /home/nakhoadl/workspace/SHDocument /home/nakhoadl/workspace/SHDocument /home/nakhoadl/workspace/SHDocument/CMakeFiles/client_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client_run.dir/depend

# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Igora\Desktop\PJATK-NAI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Igora\Desktop\PJATK-NAI\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab01.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Lab01.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab01.dir/flags.make

CMakeFiles/Lab01.dir/main.cpp.obj: CMakeFiles/Lab01.dir/flags.make
CMakeFiles/Lab01.dir/main.cpp.obj: ../main.cpp
CMakeFiles/Lab01.dir/main.cpp.obj: CMakeFiles/Lab01.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Igora\Desktop\PJATK-NAI\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab01.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Lab01.dir/main.cpp.obj -MF CMakeFiles\Lab01.dir\main.cpp.obj.d -o CMakeFiles\Lab01.dir\main.cpp.obj -c C:\Users\Igora\Desktop\PJATK-NAI\main.cpp

CMakeFiles/Lab01.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab01.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Igora\Desktop\PJATK-NAI\main.cpp > CMakeFiles\Lab01.dir\main.cpp.i

CMakeFiles/Lab01.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab01.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Igora\Desktop\PJATK-NAI\main.cpp -o CMakeFiles\Lab01.dir\main.cpp.s

# Object files for target Lab01
Lab01_OBJECTS = \
"CMakeFiles/Lab01.dir/main.cpp.obj"

# External object files for target Lab01
Lab01_EXTERNAL_OBJECTS =

Lab01.exe: CMakeFiles/Lab01.dir/main.cpp.obj
Lab01.exe: CMakeFiles/Lab01.dir/build.make
Lab01.exe: CMakeFiles/Lab01.dir/linklibs.rsp
Lab01.exe: CMakeFiles/Lab01.dir/objects1.rsp
Lab01.exe: CMakeFiles/Lab01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Igora\Desktop\PJATK-NAI\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab01.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab01.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab01.dir/build: Lab01.exe
.PHONY : CMakeFiles/Lab01.dir/build

CMakeFiles/Lab01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab01.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab01.dir/clean

CMakeFiles/Lab01.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Igora\Desktop\PJATK-NAI C:\Users\Igora\Desktop\PJATK-NAI C:\Users\Igora\Desktop\PJATK-NAI\cmake-build-debug C:\Users\Igora\Desktop\PJATK-NAI\cmake-build-debug C:\Users\Igora\Desktop\PJATK-NAI\cmake-build-debug\CMakeFiles\Lab01.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab01.dir/depend

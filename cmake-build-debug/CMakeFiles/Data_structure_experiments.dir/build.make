# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = C:\Code\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\Code\cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\WeiZixiang\Desktop\Data-structure-experiments

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\WeiZixiang\Desktop\Data-structure-experiments\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Data_structure_experiments.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Data_structure_experiments.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Data_structure_experiments.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Data_structure_experiments.dir/flags.make

CMakeFiles/Data_structure_experiments.dir/main.cpp.obj: CMakeFiles/Data_structure_experiments.dir/flags.make
CMakeFiles/Data_structure_experiments.dir/main.cpp.obj: C:/Users/WeiZixiang/Desktop/Data-structure-experiments/main.cpp
CMakeFiles/Data_structure_experiments.dir/main.cpp.obj: CMakeFiles/Data_structure_experiments.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\WeiZixiang\Desktop\Data-structure-experiments\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Data_structure_experiments.dir/main.cpp.obj"
	C:\Code\MinGW-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Data_structure_experiments.dir/main.cpp.obj -MF CMakeFiles\Data_structure_experiments.dir\main.cpp.obj.d -o CMakeFiles\Data_structure_experiments.dir\main.cpp.obj -c C:\Users\WeiZixiang\Desktop\Data-structure-experiments\main.cpp

CMakeFiles/Data_structure_experiments.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Data_structure_experiments.dir/main.cpp.i"
	C:\Code\MinGW-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\WeiZixiang\Desktop\Data-structure-experiments\main.cpp > CMakeFiles\Data_structure_experiments.dir\main.cpp.i

CMakeFiles/Data_structure_experiments.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Data_structure_experiments.dir/main.cpp.s"
	C:\Code\MinGW-64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\WeiZixiang\Desktop\Data-structure-experiments\main.cpp -o CMakeFiles\Data_structure_experiments.dir\main.cpp.s

# Object files for target Data_structure_experiments
Data_structure_experiments_OBJECTS = \
"CMakeFiles/Data_structure_experiments.dir/main.cpp.obj"

# External object files for target Data_structure_experiments
Data_structure_experiments_EXTERNAL_OBJECTS =

Data_structure_experiments.exe: CMakeFiles/Data_structure_experiments.dir/main.cpp.obj
Data_structure_experiments.exe: CMakeFiles/Data_structure_experiments.dir/build.make
Data_structure_experiments.exe: CMakeFiles/Data_structure_experiments.dir/linkLibs.rsp
Data_structure_experiments.exe: CMakeFiles/Data_structure_experiments.dir/objects1
Data_structure_experiments.exe: CMakeFiles/Data_structure_experiments.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\WeiZixiang\Desktop\Data-structure-experiments\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Data_structure_experiments.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Data_structure_experiments.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Data_structure_experiments.dir/build: Data_structure_experiments.exe
.PHONY : CMakeFiles/Data_structure_experiments.dir/build

CMakeFiles/Data_structure_experiments.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Data_structure_experiments.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Data_structure_experiments.dir/clean

CMakeFiles/Data_structure_experiments.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\WeiZixiang\Desktop\Data-structure-experiments C:\Users\WeiZixiang\Desktop\Data-structure-experiments C:\Users\WeiZixiang\Desktop\Data-structure-experiments\cmake-build-debug C:\Users\WeiZixiang\Desktop\Data-structure-experiments\cmake-build-debug C:\Users\WeiZixiang\Desktop\Data-structure-experiments\cmake-build-debug\CMakeFiles\Data_structure_experiments.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Data_structure_experiments.dir/depend


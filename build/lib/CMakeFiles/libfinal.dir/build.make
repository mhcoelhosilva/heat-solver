# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Matheus\Desktop\Aerospace Engineering\CSE minor\Object-Oriented Programming with C++\AnotherTry"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Matheus\Desktop\Aerospace Engineering\CSE minor\Object-Oriented Programming with C++\AnotherTry\build"

# Include any dependencies generated for this target.
include lib/CMakeFiles/libfinal.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/libfinal.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/libfinal.dir/flags.make

# Object files for target libfinal
libfinal_OBJECTS =

# External object files for target libfinal
libfinal_EXTERNAL_OBJECTS =

lib/liblibfinal.a: lib/CMakeFiles/libfinal.dir/build.make
lib/liblibfinal.a: lib/CMakeFiles/libfinal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Matheus\Desktop\Aerospace Engineering\CSE minor\Object-Oriented Programming with C++\AnotherTry\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library liblibfinal.a"
	cd /d "C:\Users\Matheus\Desktop\AEROSP~1\CSE minor\Object-Oriented Programming with C++\AnotherTry\build\lib" && $(CMAKE_COMMAND) -P CMakeFiles\libfinal.dir\cmake_clean_target.cmake
	cd /d "C:\Users\Matheus\Desktop\AEROSP~1\CSE minor\Object-Oriented Programming with C++\AnotherTry\build\lib" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\libfinal.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/libfinal.dir/build: lib/liblibfinal.a

.PHONY : lib/CMakeFiles/libfinal.dir/build

lib/CMakeFiles/libfinal.dir/clean:
	cd /d "C:\Users\Matheus\Desktop\AEROSP~1\CSE minor\Object-Oriented Programming with C++\AnotherTry\build\lib" && $(CMAKE_COMMAND) -P CMakeFiles\libfinal.dir\cmake_clean.cmake
.PHONY : lib/CMakeFiles/libfinal.dir/clean

lib/CMakeFiles/libfinal.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Matheus\Desktop\Aerospace Engineering\CSE minor\Object-Oriented Programming with C++\AnotherTry" "C:\Users\Matheus\Desktop\Aerospace Engineering\CSE minor\Object-Oriented Programming with C++\AnotherTry\lib" "C:\Users\Matheus\Desktop\Aerospace Engineering\CSE minor\Object-Oriented Programming with C++\AnotherTry\build" "C:\Users\Matheus\Desktop\Aerospace Engineering\CSE minor\Object-Oriented Programming with C++\AnotherTry\build\lib" "C:\Users\Matheus\Desktop\Aerospace Engineering\CSE minor\Object-Oriented Programming with C++\AnotherTry\build\lib\CMakeFiles\libfinal.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : lib/CMakeFiles/libfinal.dir/depend

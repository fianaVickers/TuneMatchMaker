# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\fiana\CLionProjects\SongEditorFinder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\fiana\CLionProjects\SongEditorFinder\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SongEditorFinder.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SongEditorFinder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SongEditorFinder.dir/flags.make

CMakeFiles/SongEditorFinder.dir/main.cpp.obj: CMakeFiles/SongEditorFinder.dir/flags.make
CMakeFiles/SongEditorFinder.dir/main.cpp.obj: CMakeFiles/SongEditorFinder.dir/includes_CXX.rsp
CMakeFiles/SongEditorFinder.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\fiana\CLionProjects\SongEditorFinder\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SongEditorFinder.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SongEditorFinder.dir\main.cpp.obj -c C:\Users\fiana\CLionProjects\SongEditorFinder\main.cpp

CMakeFiles/SongEditorFinder.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SongEditorFinder.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\fiana\CLionProjects\SongEditorFinder\main.cpp > CMakeFiles\SongEditorFinder.dir\main.cpp.i

CMakeFiles/SongEditorFinder.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SongEditorFinder.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\fiana\CLionProjects\SongEditorFinder\main.cpp -o CMakeFiles\SongEditorFinder.dir\main.cpp.s

CMakeFiles/SongEditorFinder.dir/TextureManager.cpp.obj: CMakeFiles/SongEditorFinder.dir/flags.make
CMakeFiles/SongEditorFinder.dir/TextureManager.cpp.obj: CMakeFiles/SongEditorFinder.dir/includes_CXX.rsp
CMakeFiles/SongEditorFinder.dir/TextureManager.cpp.obj: ../TextureManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\fiana\CLionProjects\SongEditorFinder\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SongEditorFinder.dir/TextureManager.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SongEditorFinder.dir\TextureManager.cpp.obj -c C:\Users\fiana\CLionProjects\SongEditorFinder\TextureManager.cpp

CMakeFiles/SongEditorFinder.dir/TextureManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SongEditorFinder.dir/TextureManager.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\fiana\CLionProjects\SongEditorFinder\TextureManager.cpp > CMakeFiles\SongEditorFinder.dir\TextureManager.cpp.i

CMakeFiles/SongEditorFinder.dir/TextureManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SongEditorFinder.dir/TextureManager.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\fiana\CLionProjects\SongEditorFinder\TextureManager.cpp -o CMakeFiles\SongEditorFinder.dir\TextureManager.cpp.s

# Object files for target SongEditorFinder
SongEditorFinder_OBJECTS = \
"CMakeFiles/SongEditorFinder.dir/main.cpp.obj" \
"CMakeFiles/SongEditorFinder.dir/TextureManager.cpp.obj"

# External object files for target SongEditorFinder
SongEditorFinder_EXTERNAL_OBJECTS =

SongEditorFinder.exe: CMakeFiles/SongEditorFinder.dir/main.cpp.obj
SongEditorFinder.exe: CMakeFiles/SongEditorFinder.dir/TextureManager.cpp.obj
SongEditorFinder.exe: CMakeFiles/SongEditorFinder.dir/build.make
SongEditorFinder.exe: C:/Users/fiana/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/libsfml-graphics-d.a
SongEditorFinder.exe: C:/Users/fiana/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/libsfml-audio-d.a
SongEditorFinder.exe: C:/Users/fiana/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/libsfml-window-d.a
SongEditorFinder.exe: C:/Users/fiana/Downloads/SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit/SFML-2.5.1/lib/libsfml-system-d.a
SongEditorFinder.exe: CMakeFiles/SongEditorFinder.dir/linklibs.rsp
SongEditorFinder.exe: CMakeFiles/SongEditorFinder.dir/objects1.rsp
SongEditorFinder.exe: CMakeFiles/SongEditorFinder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\fiana\CLionProjects\SongEditorFinder\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SongEditorFinder.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SongEditorFinder.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SongEditorFinder.dir/build: SongEditorFinder.exe

.PHONY : CMakeFiles/SongEditorFinder.dir/build

CMakeFiles/SongEditorFinder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SongEditorFinder.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SongEditorFinder.dir/clean

CMakeFiles/SongEditorFinder.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\fiana\CLionProjects\SongEditorFinder C:\Users\fiana\CLionProjects\SongEditorFinder C:\Users\fiana\CLionProjects\SongEditorFinder\cmake-build-debug C:\Users\fiana\CLionProjects\SongEditorFinder\cmake-build-debug C:\Users\fiana\CLionProjects\SongEditorFinder\cmake-build-debug\CMakeFiles\SongEditorFinder.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SongEditorFinder.dir/depend


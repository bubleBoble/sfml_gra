# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\zcPg\004_gra_na_infe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\zcPg\004_gra_na_infe\build

# Include any dependencies generated for this target.
include CMakeFiles/OUTPUT.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OUTPUT.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OUTPUT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OUTPUT.dir/flags.make

CMakeFiles/OUTPUT.dir/src/main.cpp.obj: CMakeFiles/OUTPUT.dir/flags.make
CMakeFiles/OUTPUT.dir/src/main.cpp.obj: CMakeFiles/OUTPUT.dir/includes_CXX.rsp
CMakeFiles/OUTPUT.dir/src/main.cpp.obj: ../src/main.cpp
CMakeFiles/OUTPUT.dir/src/main.cpp.obj: CMakeFiles/OUTPUT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\zcPg\004_gra_na_infe\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OUTPUT.dir/src/main.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OUTPUT.dir/src/main.cpp.obj -MF CMakeFiles\OUTPUT.dir\src\main.cpp.obj.d -o CMakeFiles\OUTPUT.dir\src\main.cpp.obj -c C:\zcPg\004_gra_na_infe\src\main.cpp

CMakeFiles/OUTPUT.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OUTPUT.dir/src/main.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\zcPg\004_gra_na_infe\src\main.cpp > CMakeFiles\OUTPUT.dir\src\main.cpp.i

CMakeFiles/OUTPUT.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OUTPUT.dir/src/main.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\zcPg\004_gra_na_infe\src\main.cpp -o CMakeFiles\OUTPUT.dir\src\main.cpp.s

CMakeFiles/OUTPUT.dir/src/Game.cpp.obj: CMakeFiles/OUTPUT.dir/flags.make
CMakeFiles/OUTPUT.dir/src/Game.cpp.obj: CMakeFiles/OUTPUT.dir/includes_CXX.rsp
CMakeFiles/OUTPUT.dir/src/Game.cpp.obj: ../src/Game.cpp
CMakeFiles/OUTPUT.dir/src/Game.cpp.obj: CMakeFiles/OUTPUT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\zcPg\004_gra_na_infe\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OUTPUT.dir/src/Game.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OUTPUT.dir/src/Game.cpp.obj -MF CMakeFiles\OUTPUT.dir\src\Game.cpp.obj.d -o CMakeFiles\OUTPUT.dir\src\Game.cpp.obj -c C:\zcPg\004_gra_na_infe\src\Game.cpp

CMakeFiles/OUTPUT.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OUTPUT.dir/src/Game.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\zcPg\004_gra_na_infe\src\Game.cpp > CMakeFiles\OUTPUT.dir\src\Game.cpp.i

CMakeFiles/OUTPUT.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OUTPUT.dir/src/Game.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\zcPg\004_gra_na_infe\src\Game.cpp -o CMakeFiles\OUTPUT.dir\src\Game.cpp.s

CMakeFiles/OUTPUT.dir/src/Entity.cpp.obj: CMakeFiles/OUTPUT.dir/flags.make
CMakeFiles/OUTPUT.dir/src/Entity.cpp.obj: CMakeFiles/OUTPUT.dir/includes_CXX.rsp
CMakeFiles/OUTPUT.dir/src/Entity.cpp.obj: ../src/Entity.cpp
CMakeFiles/OUTPUT.dir/src/Entity.cpp.obj: CMakeFiles/OUTPUT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\zcPg\004_gra_na_infe\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OUTPUT.dir/src/Entity.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OUTPUT.dir/src/Entity.cpp.obj -MF CMakeFiles\OUTPUT.dir\src\Entity.cpp.obj.d -o CMakeFiles\OUTPUT.dir\src\Entity.cpp.obj -c C:\zcPg\004_gra_na_infe\src\Entity.cpp

CMakeFiles/OUTPUT.dir/src/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OUTPUT.dir/src/Entity.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\zcPg\004_gra_na_infe\src\Entity.cpp > CMakeFiles\OUTPUT.dir\src\Entity.cpp.i

CMakeFiles/OUTPUT.dir/src/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OUTPUT.dir/src/Entity.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\zcPg\004_gra_na_infe\src\Entity.cpp -o CMakeFiles\OUTPUT.dir\src\Entity.cpp.s

CMakeFiles/OUTPUT.dir/src/Hud.cpp.obj: CMakeFiles/OUTPUT.dir/flags.make
CMakeFiles/OUTPUT.dir/src/Hud.cpp.obj: CMakeFiles/OUTPUT.dir/includes_CXX.rsp
CMakeFiles/OUTPUT.dir/src/Hud.cpp.obj: ../src/Hud.cpp
CMakeFiles/OUTPUT.dir/src/Hud.cpp.obj: CMakeFiles/OUTPUT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\zcPg\004_gra_na_infe\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/OUTPUT.dir/src/Hud.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OUTPUT.dir/src/Hud.cpp.obj -MF CMakeFiles\OUTPUT.dir\src\Hud.cpp.obj.d -o CMakeFiles\OUTPUT.dir\src\Hud.cpp.obj -c C:\zcPg\004_gra_na_infe\src\Hud.cpp

CMakeFiles/OUTPUT.dir/src/Hud.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OUTPUT.dir/src/Hud.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\zcPg\004_gra_na_infe\src\Hud.cpp > CMakeFiles\OUTPUT.dir\src\Hud.cpp.i

CMakeFiles/OUTPUT.dir/src/Hud.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OUTPUT.dir/src/Hud.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\zcPg\004_gra_na_infe\src\Hud.cpp -o CMakeFiles\OUTPUT.dir\src\Hud.cpp.s

CMakeFiles/OUTPUT.dir/src/Player.cpp.obj: CMakeFiles/OUTPUT.dir/flags.make
CMakeFiles/OUTPUT.dir/src/Player.cpp.obj: CMakeFiles/OUTPUT.dir/includes_CXX.rsp
CMakeFiles/OUTPUT.dir/src/Player.cpp.obj: ../src/Player.cpp
CMakeFiles/OUTPUT.dir/src/Player.cpp.obj: CMakeFiles/OUTPUT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\zcPg\004_gra_na_infe\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/OUTPUT.dir/src/Player.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OUTPUT.dir/src/Player.cpp.obj -MF CMakeFiles\OUTPUT.dir\src\Player.cpp.obj.d -o CMakeFiles\OUTPUT.dir\src\Player.cpp.obj -c C:\zcPg\004_gra_na_infe\src\Player.cpp

CMakeFiles/OUTPUT.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OUTPUT.dir/src/Player.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\zcPg\004_gra_na_infe\src\Player.cpp > CMakeFiles\OUTPUT.dir\src\Player.cpp.i

CMakeFiles/OUTPUT.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OUTPUT.dir/src/Player.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\zcPg\004_gra_na_infe\src\Player.cpp -o CMakeFiles\OUTPUT.dir\src\Player.cpp.s

CMakeFiles/OUTPUT.dir/src/animation2xxx.cpp.obj: CMakeFiles/OUTPUT.dir/flags.make
CMakeFiles/OUTPUT.dir/src/animation2xxx.cpp.obj: CMakeFiles/OUTPUT.dir/includes_CXX.rsp
CMakeFiles/OUTPUT.dir/src/animation2xxx.cpp.obj: ../src/animation2xxx.cpp
CMakeFiles/OUTPUT.dir/src/animation2xxx.cpp.obj: CMakeFiles/OUTPUT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\zcPg\004_gra_na_infe\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/OUTPUT.dir/src/animation2xxx.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OUTPUT.dir/src/animation2xxx.cpp.obj -MF CMakeFiles\OUTPUT.dir\src\animation2xxx.cpp.obj.d -o CMakeFiles\OUTPUT.dir\src\animation2xxx.cpp.obj -c C:\zcPg\004_gra_na_infe\src\animation2xxx.cpp

CMakeFiles/OUTPUT.dir/src/animation2xxx.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OUTPUT.dir/src/animation2xxx.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\zcPg\004_gra_na_infe\src\animation2xxx.cpp > CMakeFiles\OUTPUT.dir\src\animation2xxx.cpp.i

CMakeFiles/OUTPUT.dir/src/animation2xxx.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OUTPUT.dir/src/animation2xxx.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\zcPg\004_gra_na_infe\src\animation2xxx.cpp -o CMakeFiles\OUTPUT.dir\src\animation2xxx.cpp.s

CMakeFiles/OUTPUT.dir/src/FireBall.cpp.obj: CMakeFiles/OUTPUT.dir/flags.make
CMakeFiles/OUTPUT.dir/src/FireBall.cpp.obj: CMakeFiles/OUTPUT.dir/includes_CXX.rsp
CMakeFiles/OUTPUT.dir/src/FireBall.cpp.obj: ../src/FireBall.cpp
CMakeFiles/OUTPUT.dir/src/FireBall.cpp.obj: CMakeFiles/OUTPUT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\zcPg\004_gra_na_infe\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/OUTPUT.dir/src/FireBall.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OUTPUT.dir/src/FireBall.cpp.obj -MF CMakeFiles\OUTPUT.dir\src\FireBall.cpp.obj.d -o CMakeFiles\OUTPUT.dir\src\FireBall.cpp.obj -c C:\zcPg\004_gra_na_infe\src\FireBall.cpp

CMakeFiles/OUTPUT.dir/src/FireBall.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OUTPUT.dir/src/FireBall.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\zcPg\004_gra_na_infe\src\FireBall.cpp > CMakeFiles\OUTPUT.dir\src\FireBall.cpp.i

CMakeFiles/OUTPUT.dir/src/FireBall.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OUTPUT.dir/src/FireBall.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\zcPg\004_gra_na_infe\src\FireBall.cpp -o CMakeFiles\OUTPUT.dir\src\FireBall.cpp.s

CMakeFiles/OUTPUT.dir/src/FireballAnimation.cpp.obj: CMakeFiles/OUTPUT.dir/flags.make
CMakeFiles/OUTPUT.dir/src/FireballAnimation.cpp.obj: CMakeFiles/OUTPUT.dir/includes_CXX.rsp
CMakeFiles/OUTPUT.dir/src/FireballAnimation.cpp.obj: ../src/FireballAnimation.cpp
CMakeFiles/OUTPUT.dir/src/FireballAnimation.cpp.obj: CMakeFiles/OUTPUT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\zcPg\004_gra_na_infe\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/OUTPUT.dir/src/FireballAnimation.cpp.obj"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OUTPUT.dir/src/FireballAnimation.cpp.obj -MF CMakeFiles\OUTPUT.dir\src\FireballAnimation.cpp.obj.d -o CMakeFiles\OUTPUT.dir\src\FireballAnimation.cpp.obj -c C:\zcPg\004_gra_na_infe\src\FireballAnimation.cpp

CMakeFiles/OUTPUT.dir/src/FireballAnimation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OUTPUT.dir/src/FireballAnimation.cpp.i"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\zcPg\004_gra_na_infe\src\FireballAnimation.cpp > CMakeFiles\OUTPUT.dir\src\FireballAnimation.cpp.i

CMakeFiles/OUTPUT.dir/src/FireballAnimation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OUTPUT.dir/src/FireballAnimation.cpp.s"
	C:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\zcPg\004_gra_na_infe\src\FireballAnimation.cpp -o CMakeFiles\OUTPUT.dir\src\FireballAnimation.cpp.s

# Object files for target OUTPUT
OUTPUT_OBJECTS = \
"CMakeFiles/OUTPUT.dir/src/main.cpp.obj" \
"CMakeFiles/OUTPUT.dir/src/Game.cpp.obj" \
"CMakeFiles/OUTPUT.dir/src/Entity.cpp.obj" \
"CMakeFiles/OUTPUT.dir/src/Hud.cpp.obj" \
"CMakeFiles/OUTPUT.dir/src/Player.cpp.obj" \
"CMakeFiles/OUTPUT.dir/src/animation2xxx.cpp.obj" \
"CMakeFiles/OUTPUT.dir/src/FireBall.cpp.obj" \
"CMakeFiles/OUTPUT.dir/src/FireballAnimation.cpp.obj"

# External object files for target OUTPUT
OUTPUT_EXTERNAL_OBJECTS =

../bin/OUTPUT.exe: CMakeFiles/OUTPUT.dir/src/main.cpp.obj
../bin/OUTPUT.exe: CMakeFiles/OUTPUT.dir/src/Game.cpp.obj
../bin/OUTPUT.exe: CMakeFiles/OUTPUT.dir/src/Entity.cpp.obj
../bin/OUTPUT.exe: CMakeFiles/OUTPUT.dir/src/Hud.cpp.obj
../bin/OUTPUT.exe: CMakeFiles/OUTPUT.dir/src/Player.cpp.obj
../bin/OUTPUT.exe: CMakeFiles/OUTPUT.dir/src/animation2xxx.cpp.obj
../bin/OUTPUT.exe: CMakeFiles/OUTPUT.dir/src/FireBall.cpp.obj
../bin/OUTPUT.exe: CMakeFiles/OUTPUT.dir/src/FireballAnimation.cpp.obj
../bin/OUTPUT.exe: CMakeFiles/OUTPUT.dir/build.make
../bin/OUTPUT.exe: C:/Program\ Files\ (x86)/SFML/lib/libsfml-graphics.a
../bin/OUTPUT.exe: C:/Program\ Files\ (x86)/SFML/lib/libsfml-audio.a
../bin/OUTPUT.exe: C:/Program\ Files\ (x86)/SFML/lib/libsfml-window.a
../bin/OUTPUT.exe: C:/Program\ Files\ (x86)/SFML/lib/libsfml-system.a
../bin/OUTPUT.exe: CMakeFiles/OUTPUT.dir/linklibs.rsp
../bin/OUTPUT.exe: CMakeFiles/OUTPUT.dir/objects1.rsp
../bin/OUTPUT.exe: CMakeFiles/OUTPUT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\zcPg\004_gra_na_infe\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable ..\bin\OUTPUT.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OUTPUT.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OUTPUT.dir/build: ../bin/OUTPUT.exe
.PHONY : CMakeFiles/OUTPUT.dir/build

CMakeFiles/OUTPUT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OUTPUT.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OUTPUT.dir/clean

CMakeFiles/OUTPUT.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\zcPg\004_gra_na_infe C:\zcPg\004_gra_na_infe C:\zcPg\004_gra_na_infe\build C:\zcPg\004_gra_na_infe\build C:\zcPg\004_gra_na_infe\build\CMakeFiles\OUTPUT.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OUTPUT.dir/depend


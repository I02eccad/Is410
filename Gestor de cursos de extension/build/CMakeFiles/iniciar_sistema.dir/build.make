# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_SOURCE_DIR = "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/build"

# Include any dependencies generated for this target.
include CMakeFiles/iniciar_sistema.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/iniciar_sistema.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/iniciar_sistema.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/iniciar_sistema.dir/flags.make

CMakeFiles/iniciar_sistema.dir/lib/tinyxml2.cpp.o: CMakeFiles/iniciar_sistema.dir/flags.make
CMakeFiles/iniciar_sistema.dir/lib/tinyxml2.cpp.o: /home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor\ de\ cursos\ de\ extension/lib/tinyxml2.cpp
CMakeFiles/iniciar_sistema.dir/lib/tinyxml2.cpp.o: CMakeFiles/iniciar_sistema.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/iniciar_sistema.dir/lib/tinyxml2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/iniciar_sistema.dir/lib/tinyxml2.cpp.o -MF CMakeFiles/iniciar_sistema.dir/lib/tinyxml2.cpp.o.d -o CMakeFiles/iniciar_sistema.dir/lib/tinyxml2.cpp.o -c "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/lib/tinyxml2.cpp"

CMakeFiles/iniciar_sistema.dir/lib/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iniciar_sistema.dir/lib/tinyxml2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/lib/tinyxml2.cpp" > CMakeFiles/iniciar_sistema.dir/lib/tinyxml2.cpp.i

CMakeFiles/iniciar_sistema.dir/lib/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iniciar_sistema.dir/lib/tinyxml2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/lib/tinyxml2.cpp" -o CMakeFiles/iniciar_sistema.dir/lib/tinyxml2.cpp.s

CMakeFiles/iniciar_sistema.dir/src/Curso.cpp.o: CMakeFiles/iniciar_sistema.dir/flags.make
CMakeFiles/iniciar_sistema.dir/src/Curso.cpp.o: /home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor\ de\ cursos\ de\ extension/src/Curso.cpp
CMakeFiles/iniciar_sistema.dir/src/Curso.cpp.o: CMakeFiles/iniciar_sistema.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/iniciar_sistema.dir/src/Curso.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/iniciar_sistema.dir/src/Curso.cpp.o -MF CMakeFiles/iniciar_sistema.dir/src/Curso.cpp.o.d -o CMakeFiles/iniciar_sistema.dir/src/Curso.cpp.o -c "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/src/Curso.cpp"

CMakeFiles/iniciar_sistema.dir/src/Curso.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iniciar_sistema.dir/src/Curso.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/src/Curso.cpp" > CMakeFiles/iniciar_sistema.dir/src/Curso.cpp.i

CMakeFiles/iniciar_sistema.dir/src/Curso.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iniciar_sistema.dir/src/Curso.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/src/Curso.cpp" -o CMakeFiles/iniciar_sistema.dir/src/Curso.cpp.s

CMakeFiles/iniciar_sistema.dir/src/Estadistica.cpp.o: CMakeFiles/iniciar_sistema.dir/flags.make
CMakeFiles/iniciar_sistema.dir/src/Estadistica.cpp.o: /home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor\ de\ cursos\ de\ extension/src/Estadistica.cpp
CMakeFiles/iniciar_sistema.dir/src/Estadistica.cpp.o: CMakeFiles/iniciar_sistema.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/iniciar_sistema.dir/src/Estadistica.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/iniciar_sistema.dir/src/Estadistica.cpp.o -MF CMakeFiles/iniciar_sistema.dir/src/Estadistica.cpp.o.d -o CMakeFiles/iniciar_sistema.dir/src/Estadistica.cpp.o -c "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/src/Estadistica.cpp"

CMakeFiles/iniciar_sistema.dir/src/Estadistica.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iniciar_sistema.dir/src/Estadistica.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/src/Estadistica.cpp" > CMakeFiles/iniciar_sistema.dir/src/Estadistica.cpp.i

CMakeFiles/iniciar_sistema.dir/src/Estadistica.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iniciar_sistema.dir/src/Estadistica.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/src/Estadistica.cpp" -o CMakeFiles/iniciar_sistema.dir/src/Estadistica.cpp.s

CMakeFiles/iniciar_sistema.dir/src/SistemaDeGestionDeCursos.cpp.o: CMakeFiles/iniciar_sistema.dir/flags.make
CMakeFiles/iniciar_sistema.dir/src/SistemaDeGestionDeCursos.cpp.o: /home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor\ de\ cursos\ de\ extension/src/SistemaDeGestionDeCursos.cpp
CMakeFiles/iniciar_sistema.dir/src/SistemaDeGestionDeCursos.cpp.o: CMakeFiles/iniciar_sistema.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/iniciar_sistema.dir/src/SistemaDeGestionDeCursos.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/iniciar_sistema.dir/src/SistemaDeGestionDeCursos.cpp.o -MF CMakeFiles/iniciar_sistema.dir/src/SistemaDeGestionDeCursos.cpp.o.d -o CMakeFiles/iniciar_sistema.dir/src/SistemaDeGestionDeCursos.cpp.o -c "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/src/SistemaDeGestionDeCursos.cpp"

CMakeFiles/iniciar_sistema.dir/src/SistemaDeGestionDeCursos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iniciar_sistema.dir/src/SistemaDeGestionDeCursos.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/src/SistemaDeGestionDeCursos.cpp" > CMakeFiles/iniciar_sistema.dir/src/SistemaDeGestionDeCursos.cpp.i

CMakeFiles/iniciar_sistema.dir/src/SistemaDeGestionDeCursos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iniciar_sistema.dir/src/SistemaDeGestionDeCursos.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/src/SistemaDeGestionDeCursos.cpp" -o CMakeFiles/iniciar_sistema.dir/src/SistemaDeGestionDeCursos.cpp.s

CMakeFiles/iniciar_sistema.dir/src/Usuario.cpp.o: CMakeFiles/iniciar_sistema.dir/flags.make
CMakeFiles/iniciar_sistema.dir/src/Usuario.cpp.o: /home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor\ de\ cursos\ de\ extension/src/Usuario.cpp
CMakeFiles/iniciar_sistema.dir/src/Usuario.cpp.o: CMakeFiles/iniciar_sistema.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/iniciar_sistema.dir/src/Usuario.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/iniciar_sistema.dir/src/Usuario.cpp.o -MF CMakeFiles/iniciar_sistema.dir/src/Usuario.cpp.o.d -o CMakeFiles/iniciar_sistema.dir/src/Usuario.cpp.o -c "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/src/Usuario.cpp"

CMakeFiles/iniciar_sistema.dir/src/Usuario.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iniciar_sistema.dir/src/Usuario.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/src/Usuario.cpp" > CMakeFiles/iniciar_sistema.dir/src/Usuario.cpp.i

CMakeFiles/iniciar_sistema.dir/src/Usuario.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iniciar_sistema.dir/src/Usuario.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/src/Usuario.cpp" -o CMakeFiles/iniciar_sistema.dir/src/Usuario.cpp.s

CMakeFiles/iniciar_sistema.dir/src/main.cpp.o: CMakeFiles/iniciar_sistema.dir/flags.make
CMakeFiles/iniciar_sistema.dir/src/main.cpp.o: /home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor\ de\ cursos\ de\ extension/src/main.cpp
CMakeFiles/iniciar_sistema.dir/src/main.cpp.o: CMakeFiles/iniciar_sistema.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/iniciar_sistema.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/iniciar_sistema.dir/src/main.cpp.o -MF CMakeFiles/iniciar_sistema.dir/src/main.cpp.o.d -o CMakeFiles/iniciar_sistema.dir/src/main.cpp.o -c "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/src/main.cpp"

CMakeFiles/iniciar_sistema.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iniciar_sistema.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/src/main.cpp" > CMakeFiles/iniciar_sistema.dir/src/main.cpp.i

CMakeFiles/iniciar_sistema.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iniciar_sistema.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/src/main.cpp" -o CMakeFiles/iniciar_sistema.dir/src/main.cpp.s

# Object files for target iniciar_sistema
iniciar_sistema_OBJECTS = \
"CMakeFiles/iniciar_sistema.dir/lib/tinyxml2.cpp.o" \
"CMakeFiles/iniciar_sistema.dir/src/Curso.cpp.o" \
"CMakeFiles/iniciar_sistema.dir/src/Estadistica.cpp.o" \
"CMakeFiles/iniciar_sistema.dir/src/SistemaDeGestionDeCursos.cpp.o" \
"CMakeFiles/iniciar_sistema.dir/src/Usuario.cpp.o" \
"CMakeFiles/iniciar_sistema.dir/src/main.cpp.o"

# External object files for target iniciar_sistema
iniciar_sistema_EXTERNAL_OBJECTS =

iniciar_sistema: CMakeFiles/iniciar_sistema.dir/lib/tinyxml2.cpp.o
iniciar_sistema: CMakeFiles/iniciar_sistema.dir/src/Curso.cpp.o
iniciar_sistema: CMakeFiles/iniciar_sistema.dir/src/Estadistica.cpp.o
iniciar_sistema: CMakeFiles/iniciar_sistema.dir/src/SistemaDeGestionDeCursos.cpp.o
iniciar_sistema: CMakeFiles/iniciar_sistema.dir/src/Usuario.cpp.o
iniciar_sistema: CMakeFiles/iniciar_sistema.dir/src/main.cpp.o
iniciar_sistema: CMakeFiles/iniciar_sistema.dir/build.make
iniciar_sistema: CMakeFiles/iniciar_sistema.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable iniciar_sistema"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iniciar_sistema.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/iniciar_sistema.dir/build: iniciar_sistema
.PHONY : CMakeFiles/iniciar_sistema.dir/build

CMakeFiles/iniciar_sistema.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/iniciar_sistema.dir/cmake_clean.cmake
.PHONY : CMakeFiles/iniciar_sistema.dir/clean

CMakeFiles/iniciar_sistema.dir/depend:
	cd "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension" "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension" "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/build" "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/build" "/home/michal/Desktop/SCHOOL/CÓRDOBA/Ingeniría_del_Software/Is410/Gestor de cursos de extension/build/CMakeFiles/iniciar_sistema.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/iniciar_sistema.dir/depend

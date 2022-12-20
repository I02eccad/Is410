CMAKE_MINIMUM_REQUIRED(VERSION 2.9)
PROJECT(Gestor_de_cursos_de_extension)

file(GLOB SOURCES "src/*" "lib/*")

add_executable(iniciar_sistema ${SOURCES})
add_executable(probar_sistema pruebas/pruebas.cpp src/Curso.cpp src/Estadistica.cpp src/SistemaDeGestionDeCursos.cpp src/Usuario.cpp)

#include "../src/Curso.h"
#include "../src/Estadistica.h"
#include "../src/SistemaDeGestionDeCursos.h"

#include <map>
#include <functional>
#include <string>
#include <iostream>

bool probarCursoSubscribir();
bool probarCursoDarseDeBaja();
bool probarCursoAsignarRecurso();
bool probarCursoRetirarRecurso();
bool probarSistemaIniciar();
bool probarSistemaAcceder();
bool probarSistemaDarDeAltaCurso();



map<string, function<bool(void)>> casos_de_prueba = {
		{"probarCursoSubscribir", probarCursoSubscribir},
		{"probarCursoDarseDeBaja", probarCursoDarseDeBaja},
		{"probarCursoAsignarRecurso", probarCursoAsignarRecurso},
		{"probarCursoRetirarRecurso", probarCursoRetirarRecurso},
		{"probarSistemaIniciar", probarSistemaIniciar},
		{"probarSistemaAcceder", probarSistemaAcceder},
		{"probarSistemaDarDeAltaCurso", probarSistemaDarDeAltaCurso}
};

int main()
{
	for ( const auto &myPair : casos_de_prueba ) {
        std::cout << myPair.first << ":" << casos_de_prueba[myPair.first]() << endl;
	}
}

bool probarCursoSubscribir()
{
	vector<int> ponentes({1, 2 ,3});
	vector<int> asistentes({1, 2, 3});
	Curso curso = Curso("JAVA22", "JavaProgramming", "This is a java course.",
				         time(NULL), time(NULL), 40, 400, 123, ponentes, asistentes);
	curso.subscribir(1);
	return curso.listaDeEstudiantes[0] == 1;
}

bool probarCursoDarseDeBaja()
{
	vector<int> ponentes({1, 2 ,3});
	vector<int> asistentes({1, 2, 3});
	Curso curso = Curso("JAVA22", "JavaProgramming", "This is a java course.",
					     time(NULL), time(NULL), 40, 400, 123, ponentes, asistentes);
	curso.subscribir(1);
	curso.subscribir(2);
	curso.darseDeBaja(1);
	return curso.listaDeEstudiantes[0] == 2;
}

bool probarCursoAsignarRecurso()
{
	vector<int> ponentes({1, 2 ,3});
	vector<int> asistentes({1, 2, 3});
	Curso curso = Curso("JAVA22", "JavaProgramming", "This is a java course.",
						 time(NULL), time(NULL), 40, 400, 123, ponentes, asistentes);
	curso.asignarRecurso("camara");
	return strcmp(curso.recursosAudiovisuales[0], "camara") == 0;
}

bool probarCursoRetirarRecurso()
{
	vector<int> ponentes({1, 2 ,3});
	vector<int> asistentes({1, 2, 3});
	Curso curso = Curso("JAVA22", "JavaProgramming", "This is a java course.",
						 time(NULL), time(NULL), 40, 400, 123, ponentes, asistentes);
	curso.asignarRecurso("camara");
	curso.asignarRecurso("microfono");
	curso.retirarRecurso("camara")
	return strcmp(curso.recursosAudiovisuales[0], "microfono") == 0;
}

bool probarSistemaIniciar()
{
	SistemaDeGestionDeCursos sistema = SistemaDeGestionDeCursos();
	return sistema.autorizacion == Visitante;
}

template <typename T>
bool estaEnLaLista(vector<T> elems, T in_elem)
{
	for (T elem : elems){
		if (elem == in_elem){
			return true;
		}
	}
	false;
}

bool probarSistemaAcceder()
{
	SistemaDeGestionDeCursos sistema = SistemaDeGestionDeCursos();
	Usuario usuario = Usuario(1, "--", "--", "--", "--", "--", Estudiante);
	sistema.registrar(usuario);
	return estaEnLaLista<Usuario>(sistema.listaDeUsuarios, usuario);
}

bool probarSistemaDarDeAltaCurso()
{
	SistemaDeGestionDeCursos sistema = SistemaDeGestionDeCursos();
	vector<int> ponentes({1, 2 ,3});
	vector<int> asistentes({1, 2, 3});
	Curso curso = Curso("JAVA22", "JavaProgramming", "This is a java course.",
							 time(NULL), time(NULL), 40, 400, 123, ponentes, asistentes);
	sistema.darDeAltaCurso(curso);
	return estaEnLaLista<Curso>(sistema.listaDeCursos, curso);
}



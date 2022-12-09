/*
 * SistemaDeGestionDeCursos.h
 *
 *  Created on: Nov 28, 2022
 *      Author: Michal Spiegel
 */

#ifndef SISTEMADEGESTIONDECURSOS_H_
#define SISTEMADEGESTIONDECURSOS_H_

#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include "../lib/tinyxml2.h"
#include "Curso.h"
#include "Usuario.h"



class SistemaDeGestionDeCursos {
	std::vector<Curso> listaDeCursos;
	std::vector<Usuario> listaDeUsuarios;

	char *fichero_usuarios = "usuarios.xml";
	char *fichero_cursos   = "cursos.xml";

	void cargarCursos();
	void cargarUsuarios();
	vector<char*> cargarListaDeString(tinyxml2::XMLElement *root);
	vector<int> cargarListaDeInt(tinyxml2::XMLElement *root);
	time_t SistemaDeGestionDeCursos::convertirStringDatetime(const char *datetime_str);
	int  guardarCursos();
	// Solo funciona con tipos atómicos como string y int
	template <typename T>
	int guardarListaDeElem(tinyxml2::XMLDocument doc, tinyxml2::XMLElement *recursosAV, vector<T> listaDeRecursosAV);
	int guardarUsuarios();


public:
	SistemaDeGestionDeCursos();
	virtual ~SistemaDeGestionDeCursos();
	void verLosCursos();
	void acceder();
	void menuPrincipal();
	void darDeAltaCurso(Curso curso);
	void darDeBajaCurso(Curso curso);
};

#endif /* SISTEMADEGESTIONDECURSOS_H_ */

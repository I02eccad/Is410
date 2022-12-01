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
	int  guardarCursos();
	void guardarUsuarios();

public:
	SistemaDeGestionDeCursos();
	void verLosCursos();
	void acceder();
};

#endif /* SISTEMADEGESTIONDECURSOS_H_ */

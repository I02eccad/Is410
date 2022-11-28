/*
 * SistemaDeGestionDeCursos.h
 *
 *  Created on: Nov 28, 2022
 *      Author: Michal Spiegel
 */

#include <vector>

#include "Curso.h"
#include "Usuario.h"

#ifndef SISTEMADEGESTIONDECURSOS_H_
#define SISTEMADEGESTIONDECURSOS_H_

class SistemaDeGestionDeCursos {
	std::vector<Curso> listaDeCursos;
	std::vector<Usuario> listaDeUsuarios;

	void cargarCursos();
	void cargarUsuarios();

public:
	SistemaDeGestionDeCursos();
	void verLosCursos();
	void acceder();
};

void SistemaDeGestionDeCursos::cargarCursos()
{

}

void SistemaDeGestionDeCursos::cargarUsuarios()
{

}

#endif /* SISTEMADEGESTIONDECURSOS_H_ */

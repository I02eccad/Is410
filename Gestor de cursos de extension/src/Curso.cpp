/*
 * Curso.cpp
 *
 *  Created on: Nov 28, 2022
 *      Author: michal
 */

#include "Curso.h"

Curso::	Curso(const char *id,
		  const char *nombre,
		  const char *descripcion,
		  time_t fechaFinal,
		  vector<char*> recursosAudiovisuales,
		  int aforo,
	      int precio,
		  vector<int> listaDeEsperaDeEstud,
	      vector<int> listaDeAsistentes,
	      int ponentePrincipal,
	      vector<int> listaDePonentes)
{
	Curso::id = id;
	Curso::nombre = nombre;
	Curso::descripcion = descripcion;
	Curso::fechaFinal = fechaFinal;
	Curso::recursosAudiovisuales = recursosAudiovisuales;
	Curso::aforo = aforo;
	Curso::precio = precio;
	Curso::listaDeEsperaDeEstud = listaDeEsperaDeEstud;
	Curso::listaDeAsistentes = listaDeAsistentes;
	Curso::ponentePrincipal = ponentePrincipal;
	Curso::listaDePonentes = listaDePonentes;
}

void Curso::imprimirCursoFormateado()
{
	// Imprimir datos del curso en una forma como linea de base de datos
}

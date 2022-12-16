/*
 * Curso.h
 *
 *  Created on: Nov 28, 2022
 *      Author: michal
 */

#ifndef CURSO_H_
#define CURSO_H_

#include <ctime>
#include <vector>
#include "Usuario.h"


using namespace std;

class Curso {
public:
	Curso(const char *id,
		  const char *nombre,
		  const char *descripcion,
		  time_t fechaFinal,
		  vector<const char*> recursosAudiovisuales,
		  int aforo,
	      int precio,
		  vector<int> listaDeEsperaDeEstud,
	      vector<int> listaDeAsistentes,
	      int ponentePrincipal,
	      vector<int> listaDePonentes);

	const char *id;
	const char *nombre;
	const char *descripcion;
	time_t fechaFinal;
	vector<const char*> recursosAudiovisuales;
	int aforo;
	int precio;
	// Listas de IDs de Usuarios
	vector<int> listaDeEsperaDeEstud;
	vector<int> listaDeAsistentes;
	int ponentePrincipal;
	vector<int> listaDePonentes;

	bool isVisible = true;

	void imprimirCursoFormateado();

};

#endif /* CURSO_H_ */

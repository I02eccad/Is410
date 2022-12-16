/*
 * main.cpp
 *
 *  Created on: Nov 29, 2022
 *      Author: Michal Spiegel
 */

#include "SistemaDeGestionDeCursos.h"
#include "Curso.h"
#include <iostream>
#include <ctime>

int main ()
{
	SistemaDeGestionDeCursos sistema = SistemaDeGestionDeCursos();
	/*
	vector<const char*> vect1{"camara", "microfono"};
	vector<int> vect2{12321, 232, 2323, 232};
	vector<int> vect3{12, 121, 122, 324};
	vector<int> vect4{123, 1234, 4344};

	Curso calculo("123HD",
					      "Cálculo",
			             "Esto es un curso de Cálculo I.",
						 time(NULL),
						 vect1,
						 40, 60,
						 vect2,
						 vect3,
						 123456,
						 vect4);


	sistema.darDeAltaCurso(calculo);
	*/
	sistema.verLosCursos();
	sistema.guardarDatos();
}

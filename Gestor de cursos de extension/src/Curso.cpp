/*
 * Curso.cpp
 *
 *  Created on: Nov 28, 2022
 *      Author: michal
 */

#include "Curso.h"

Curso::Curso(int id, const char *contrasena, const char *nombre, const char *apellidos, const char *dni, const char *email)
{
	Curso::id = id;
	Curso::contrasena = contrasena;
	Curso::nombre = nombre;
	Curso::apellidos = apellidos;
	Curso::dni = dni;
	Curso::email = email;

}


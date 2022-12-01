/*
 * Curso.h
 *
 *  Created on: Nov 28, 2022
 *      Author: michal
 */

#ifndef CURSO_H_
#define CURSO_H_

class Curso {
public:
	Curso(int id, const char *contrasena, const char *nombre, const char *apellidos, const char *dni, const char *email);

	int id;
	char *contrasena;
	char *nombre;
	char *apellidos;
	char *dni;
	char *email;
};

#endif /* CURSO_H_ */

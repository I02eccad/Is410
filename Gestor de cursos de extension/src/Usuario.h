/*
 * Usuario.h
 *
 *  Created on: Nov 28, 2022
 *      Author: michal
 */

#ifndef USUARIO_H_
#define USUARIO_H_

enum Rol {
	Visitante,
	Estudiante,
	CoordinadorDeRecursos,
	CoordinadorDeCursos,
	Administrador
};

class Usuario {
public:
	Usuario(int id, const char *contrasena, const char *nombre, const char *apellidos, const char *dni, const char *email, Rol rol);

	int id;
	const char *contrasena;
	const char *nombre;
	const char *apellidos;
	const char *dni;
	const char *email;
	Rol rol;
};

#endif /* USUARIO_H_ */

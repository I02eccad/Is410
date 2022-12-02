/*
 * Usuario.h
 *
 *  Created on: Nov 28, 2022
 *      Author: michal
 */

#ifndef USUARIO_H_
#define USUARIO_H_

class Usuario {
public:
	Usuario(int id, const char *contrasena, const char *nombre, const char *apellidos, const char *dni, const char *email);

	int id;
	char *contrasena;
	char *nombre;
	char *apellidos;
	char *dni;
	char *email;w
};

#endif /* USUARIO_H_ */

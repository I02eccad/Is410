/*
 * Usuario.cpp
 *
 *  Created on: Nov 28, 2022
 *      Author: michal
 */

#include "Usuario.h"

Usuario::Usuario(int id, const char *contrasena, const char *nombre, const char *apellidos, const char *dni, const char *email, Rol rol)
{
	Usuario::id = id;
	Usuario::contrasena = contrasena;
	Usuario::nombre = nombre;
	Usuario::apellidos = apellidos;
	Usuario::dni = dni;
	Usuario::email = email;
	Usuario::rol = rol;

}

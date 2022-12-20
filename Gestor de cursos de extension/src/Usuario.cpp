#include "Usuario.h"
#include <string.h>

Usuario::Usuario(int id, const char *contrasena, const char *nombre, const char *apellidos, const char *dni, const char *email, Rol rol)
{
	Usuario::id = id;
	Usuario::contrasena = strdup(contrasena);
	Usuario::nombre = strdup(nombre);
	Usuario::apellidos = strdup(apellidos);
	Usuario::dni = strdup(dni);
	Usuario::email = strdup(email);
	Usuario::rol = rol;

}

Usuario::Usuario()
{
	Usuario::id = -1;
	Usuario::contrasena = "";
	Usuario::nombre = "";
	Usuario::apellidos = "";
	Usuario::dni = "";
	Usuario::email = "";
	Usuario::rol = Visitante;
}

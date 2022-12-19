#include "SistemaDeGestionDeCursos.h"
#include "Curso.h"
#include <iostream>
#include <ctime>
#include <map>
#include <functional>
#include "Excepciones.h"

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

using namespace std;

void menu(SistemaDeGestionDeCursos sistema);
void realizar_accion(SistemaDeGestionDeCursos sistema, char *comando);
void help();
void dividir(string const &str, const char delim, vector<string> &out);
void acceder(SistemaDeGestionDeCursos, vector<string>);
void verCursos(SistemaDeGestionDeCursos, vector<string>);
void cerrarSesion(SistemaDeGestionDeCursos, vector<string>);
void subscribirse(SistemaDeGestionDeCursos, vector<string>);
void darseDeBaja(SistemaDeGestionDeCursos, vector<string>);
void asignarRecurso(SistemaDeGestionDeCursos, vector<string>);
void retirarRecurso(SistemaDeGestionDeCursos, vector<string>);
void crearCurso(SistemaDeGestionDeCursos, vector<string>);
void eliminarCurso(SistemaDeGestionDeCursos, vector<string>);
void registrar(SistemaDeGestionDeCursos, vector<string>);
void imprimirInformeEstadistico(SistemaDeGestionDeCursos, vector<string>);
time_t convertirStringDatetime(char *datetime_str);




map<string, function<void(SistemaDeGestionDeCursos, vector<string>)>> comandos = {
    { "acceder", acceder},
	{ "ver-cursos", verCursos },
	{ "cerrar-sesion", cerrarSesion },
	{ "subscribirse" , subscribirse},
	{ "darse-de-baja", darseDeBaja },
	{ "asignar-recurso", asignarRecurso },
	{ "retirar-recurso", retirarRecurso },
	{ "crear-curso", crearCurso },
	{ "eliminar-curso", eliminarCurso },
	{ "registrar", registrar },
	{ "informe-estadistico", imprimirInformeEstadistico}
};

int main ()
{
	SistemaDeGestionDeCursos sistema = SistemaDeGestionDeCursos();

	help();

	char *comando = "";
	while (std::strcmp(comando, "salir"))
	{
		cin << comando;
		try {
			realizar_accion(sistema, comando);
		} catch (exception& e){
			cout << e.what() << endl;
		}
	}

	sistema.guardarDatos();
}

void realizar_accion(SistemaDeGestionDeCursos sistema, char *comando)
{
	vector<string> comandoDividido;
	dividir(comando, ' ', comandoDividido);
	// Esto llamará a la función asignada al comando dado.
	// Si el comando es desconocido, esto lanzará una excepción.
	comandos.at(comandoDividido[0])(sistema, comandoDividido);
}

void menu(SistemaDeGestionDeCursos sistema)
{
	switch(sistema.autorizacion){

		case Visitante:
			cout << "----------------------------------------------" << endl;
			cout << "Como Visitante tiene las siguientes opciones:" << endl;
			cout << "\t" << "acceder <email> <contraseña>" << endl;
			cout << "\t" << "ver-cursos" << endl;
			cout << "----------------------------------------------" << endl;

			break;

		case Estudiante:
			cout << "----------------------------------------------" << endl;
			cout << "Como Estudiante tiene las siguientes opciones:" << endl;
			cout << "\t" << "cerrar-sesion" << endl;
			cout << "\t" << "ver-cursos" << endl;
			cout << "\t" << "subscribirse <Id del curso>" << endl;
			cout << "\t" << "darse-de-baja <Id del curso>" << endl;
			cout << "----------------------------------------------" << endl;
			break;

		case CoordinadorDeCursos:
			cout << "----------------------------------------------" << endl;
			cout << "Como Coordinador de Cursos tiene las siguientes opciones:" << endl;
			cout << "\t" << "cerrar-sesion" << endl;
			cout << "\t" << "ver-cursos" << endl;
			cout << "\t" << "asignar-recurso <Id del curso> <Nombre del recurso>" << endl;
			cout << "\t" << "retirar-recurso <Id del curso> <Nombre del recurso>" << endl;
			cout << "----------------------------------------------" << endl;
			break;

		case CoordinadorDeRecursos:
			cout << "----------------------------------------------" << endl;
			cout << "Como Coordinador de Recursos tiene las siguientes opciones:" << endl;
			cout << "\t" << "cerrar-sesion" << endl;
			cout << "\t" << "ver-cursos" << endl;
			cout << "\t" << "crear-curso <Id del curso> <Nombre del recurso> <Descripción> "
					"                    <Fecha de Inicio> <Fecha final> <Aforo> <Precio>" << endl;
			cout << "\t" << "eliminar-curso <Id del curso>" << endl;
			cout << "----------------------------------------------" << endl;
			break;

		case Administrador:
			cout << "----------------------------------------------" << endl;
			cout << "Como Administrador tiene las siguientes opciones:" << endl;
			cout << "\t" << "cerrar-sesion" << endl;
			cout << "\t" << "ver-cursos" << endl;
			cout << "\t" << "crear-curso <Id del curso> <Nombre del recurso> <Descripción> "
					"                    <Fecha de Inicio> <Fecha final> <Aforo> <Precio>" << endl;
			cout << "\t" << "eliminar-curso <Id del curso>" << endl;
			cout << "\t" << "asignar-recurso <Id del curso> <Nombre del recurso>" << endl;
			cout << "\t" << "retirar-recurso <Id del curso> <Nombre del recurso>" << endl;
			cout << "\t" << "registrar <Id del usuario> <Contraseña> <Nombre> <Apellidos> <DNI> <Email> <Rol>" << endl;
			cout << "\t" << "informe-estadistico <Id del curso>" << endl;
			cout << "----------------------------------------------" << endl;

			break;
	}
}

void help()
{
	cout << "-----------------USO--------------------" << endl;
	cout << "" << endl;
	cout << "----------------------------------------" << endl;
}

void dividir(string const &str, const char delim,
            vector<string> &out)
{
    std::stringstream ss(str);

    string s;
    while (getline(ss, s, delim)) {
        out.push_back(s);
    }
}

void acceder(SistemaDeGestionDeCursos sistema, vector<string> args)
{
	if (args.size() != 3){
		throw ArgsIncorrectos();
	}

	sistema.acceder(args[1], args[2]);
	cout << "Ha iniciado sesión correctamente!" << endl;
}
void verCursos(SistemaDeGestionDeCursos sistema, vector<string> args)
{
	if (args.size() != 1){
		throw ArgsIncorrectos();
	}

	sistema.verLosCursos();
}
void cerrarSesion(SistemaDeGestionDeCursos sistema, vector<string> args)
{
	if (args.size() != 1){
		throw ArgsIncorrectos();
	}

	sistema.cerrarSesion();
	cout << "Se ha desconectado correctamente!" << endl;
}

void subscribirse(SistemaDeGestionDeCursos sistema, vector<string> args)
{
	if (args.size() != 2){
		throw ArgsIncorrectos();
	}

	sistema.subscribirse(args[1]);
	cout << "Se ha suscrito correctamente!" << endl;
}

void darseDeBaja(SistemaDeGestionDeCursos sistema, vector<string> args)
{
	if (args.size() != 2){
		throw ArgsIncorrectos();
	}

	sistema.darseDeBaja(args[1]);
	cout << "Se ha dado de baja correctamente!" << endl;
}
void asignarRecurso(SistemaDeGestionDeCursos sistema, vector<string> args)
{
	if (args.size() != 3){
		throw ArgsIncorrectos();
	}

	sistema.asignarRecursoACurso(args[1], (char *) args[2]);
	cout << "Se ha asignado el recurso correctamente!" << endl;
}
void retirarRecurso(SistemaDeGestionDeCursos sistema, vector<string> args)
{
	if (args.size() != 3){
		throw ArgsIncorrectos();
	}

	sistema.asignarRecursoACurso(args[1], (char *) args[2].c_str());
	cout << "Se ha retirado el recurso correctamente!" << endl;
}
void crearCurso(SistemaDeGestionDeCursos sistema, vector<string> args)
{
	if (args.size() != 8){
		throw ArgsIncorrectos();
	}

	Curso cursoNuevo(args[1].c_str(),
			         args[2].c_str(),
					 args[3].c_str(),
					 convertirStringDatetime((char *) args[4].c_str()),
					 convertirStringDatetime((char *) args[5].c_str()),
					 atoi(args[6].c_str()),
					 atoi(args[7].c_str()));

	sistema.darDeAltaCurso(cursoNuevo);
	cout << "Se ha creado el curso correctamente!" << endl;

}
void eliminarCurso(SistemaDeGestionDeCursos sistema, vector<string> args)
{
	if (args.size() != 2){
		throw ArgsIncorrectos();
	}

	sistema.darDeBajaCurso(args[1]);
	cout << "Se ha eliminado el curso correctamente!" << endl;
}
void registrar(SistemaDeGestionDeCursos sistema, vector<string> args)
{
	if (args.size() != 8){
		throw ArgsIncorrectos();
	}

	Rol rol;
	switch (args[7]){
		case "Visitante":
			rol = Visitante;
			break;
		case "Estudiante":
			rol = Estudiante;
			break;
		case "CoordinadorDeRecursos":
			rol = CoordinadorDeRecursos;
			break;
		case "CoordinadorDeCursos":
			rol = CoordinadorDeCursos;
			break;
		case "Administrador":
			rol = Administrador;
			break;
		default:
			throw ArgsIncorrectos();
			break;
	}

	Usuario usuarioNuevo(atoi(args[1].c_str()),
	          args[2].c_str(),
			  args[3].c_str(),
			  args[4].c_str(),
			  args[5].c_str(),
			  args[6].c_str(),
			  rol);
	sistema.registrar(usuarioNuevo);
	cout << "El usuario se ha registrado con exíto!" << endl;
}
void imprimirInformeEstadistico(SistemaDeGestionDeCursos sistema, vector<string> args)
{
	if (args.size() != 2){
		throw ArgsIncorrectos();
	}

	sistema.imprimirInformeEstadistico(args[1]);
}

time_t convertirStringDatetime(char *datetime_str)
{
	 tm tm{};
	 istringstream str_stream(datetime_str);
	 str_stream >> get_time(&tm, "%c");
	 time_t time = mktime(&tm);
	 return time;
}

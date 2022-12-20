#include "SistemaDeGestionDeCursos.h"
#include "Curso.h"
#include <iostream>
#include <ctime>
#include <map>
#include <functional>
#include "Excepciones.h"

using namespace std;

void menu(SistemaDeGestionDeCursos sistema, vector<string>);
void realizar_accion(SistemaDeGestionDeCursos sistema, string comando);
void ayuda(SistemaDeGestionDeCursos sistema, vector<string> args);
void dividir(string const &str, const char delim, vector<string> &out);
vector<int> cargarListaDeInt(string str_lista);
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
	{"ayuda", ayuda},
	{ "menu", menu},
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

map<string, Rol> str2rol = {
		{"Visitante", Visitante},
		{"Estudiante", Estudiante},
		{"CoordinadorDeRecursos", CoordinadorDeRecursos},
		{"CoordinadorDeCursos", CoordinadorDeCursos},
		{"Administrador", Administrador}
};

int main ()
{
	SistemaDeGestionDeCursos sistema = SistemaDeGestionDeCursos();

	vector<const char*> vect1{"camara", "microfono"};
	vector<int> vect2{12321, 232, 2323, 232};
	vector<int> vect3{12, 121, 122, 324};
	vector<int> vect4{123, 1234, 4344};

	Curso calculo("123HD",
					      "Cálculo",
			             "Esto es un curso de Cálculo I.",
						 time(NULL),
						 time(NULL),
						 40,
						 60,
						 123456,
						 vect2,
						 vect3);


	sistema.darDeAltaCurso(calculo);

	ayuda(sistema, vector<string>());

	string comando = "";
	getline(cin, comando);

	while (comando.compare("salir"))
	{
		try {
			realizar_accion(sistema, comando);
		} catch (exception& e){
			cout << e.what() << endl;
		}
		getline(cin, comando);
	}

	sistema.guardarDatos();
}

void realizar_accion(SistemaDeGestionDeCursos sistema, string comando)
{
	vector<string> comandoDividido;
	dividir(comando, ' ', comandoDividido);
	// Esto llamará a la función asignada al comando dado.
	// Si el comando es desconocido, esto lanzará una excepción.

	try{
		comandos.at(comandoDividido[0])(sistema, comandoDividido);
	} catch (out_of_range& e){
		throw ComandoDesconocido();
	}
}

void menu(SistemaDeGestionDeCursos sistema, vector<string> args)
{
	switch(sistema.autorizacion){

		case Visitante:
			cout << "----------------------------------------------" << endl;
			cout << "Como Visitante tiene las siguientes opciones:" << endl;
			cout << "\t" << "acceder <email> <contraseña>" << endl;
			cout << "\t" << "ver-cursos" << endl;
			cout << "----------------------------------------------" << endl;

			break;

		case Estudiante:
			cout << "----------------------------------------------" << endl;
			cout << "Como Estudiante tiene las siguientes opciones:" << endl;
			cout << "\t" << "cerrar-sesion" << endl;
			cout << "\t" << "ver-cursos" << endl;
			cout << "\t" << "subscribirse <Id del curso>" << endl;
			cout << "\t" << "darse-de-baja <Id del curso>" << endl;
			cout << "----------------------------------------------" << endl;
			break;

		case CoordinadorDeCursos:
			cout << "----------------------------------------------" << endl;
			cout << "Como Coordinador de Cursos tiene las siguientes opciones:" << endl;
			cout << "\t" << "cerrar-sesion" << endl;
			cout << "\t" << "ver-cursos" << endl;
			cout << "\t" << "asignar-recurso <Id del curso> <Nombre del recurso>" << endl;
			cout << "\t" << "retirar-recurso <Id del curso> <Nombre del recurso>" << endl;
			cout << "----------------------------------------------" << endl;
			break;

		case CoordinadorDeRecursos:
			cout << "----------------------------------------------" << endl;
			cout << "Como Coordinador de Recursos tiene las siguientes opciones:" << endl;
			cout << "\t" << "cerrar-sesion" << endl;
			cout << "\t" << "ver-cursos" << endl;
			cout << "\t" << "crear-curso <Id del curso> <Nombre del recurso> <Descripción> "
					"                    <Fecha de Inicio> <Fecha final> <Aforo> <Precio> <Ponente Principal> <[Lista,de,Pontentes]> <[Lista,de,Asistentes]>" << endl;
			cout << "\t" << "eliminar-curso <Id del curso>" << endl;
			cout << "----------------------------------------------" << endl;
			break;

		case Administrador:
			cout << "----------------------------------------------" << endl;
			cout << "Como Administrador tiene las siguientes opciones:" << endl;
			cout << "\t" << "cerrar-sesion" << endl;
			cout << "\t" << "ver-cursos" << endl;
			cout << "\t" << "crear-curso <Id del curso> <Nombre del recurso> <Descripción> "
					                    "<Fecha de Inicio> <Fecha final> <Aforo> <Precio> <Ponente Principal> <[Lista,de,Pontentes]> <[Lista,de,Asistentes]>" << endl;
			cout << "\t" << "eliminar-curso <Id del curso>" << endl;
			cout << "\t" << "asignar-recurso <Id del curso> <Nombre del recurso>" << endl;
			cout << "\t" << "retirar-recurso <Id del curso> <Nombre del recurso>" << endl;
			cout << "\t" << "registrar <Id del usuario> <Contraseña> <Nombre> <Apellidos> <DNI> <Email> <Rol>" << endl;
			cout << "\t" << "informe-estadistico <Id del curso>" << endl;
			cout << "----------------------------------------------" << endl;

			break;
	}
}

void ayuda(SistemaDeGestionDeCursos sistema, vector<string> args)
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

	sistema.asignarRecursoACurso(args[1], (char *) args[2].c_str());
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
	if (args.size() != 11){
		throw ArgsIncorrectos();
	}

	Curso cursoNuevo(args[1].c_str(),
			         args[2].c_str(),
					 args[3].c_str(),
					 convertirStringDatetime((char *) args[4].c_str()),
					 convertirStringDatetime((char *) args[5].c_str()),
					 atoi(args[6].c_str()),
					 atoi(args[7].c_str()),
					 atoi(args[8].c_str()),
					 cargarListaDeInt(args[9]),
					 cargarListaDeInt(args[10]));

	sistema.darDeAltaCurso(cursoNuevo);
	cout << "Se ha creado el curso correctamente!" << endl;

}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

vector<int> cargarListaDeInt(string str_lista)
{
	if (str_lista[0] != '[' && str_lista[str_lista.size() - 1] != ']'){
		throw ArgsIncorrectos();
	}
	vector<string> resultStr;
	dividir(str_lista.substr(1, str_lista.size() - 1), ',', resultStr);

	vector<int> result = vector<int>();
	for (string elem : resultStr)
	{
		// Si no esta numero o el número potencial está más grande que el 'int' puede ser
		if (!is_number(elem) || elem.size() > 9){
			throw ArgsIncorrectos();
		}
		result.push_back(atoi(elem.c_str()));
	}
	return result;
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

	Rol rol = str2rol.at(args[7]);

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
	 str_stream >> get_time(&tm, "%d.%m.%Y-%H:%M:%S");
	 time_t time = mktime(&tm);
	 return time;
}

#include "SistemaDeGestionDeCursos.h"
#include "Curso.h"
#include <iostream>
#include <ctime>
#include <map>
#include <functional>
#include "Excepciones.h"

using namespace std;

void menu(SistemaDeGestionDeCursos *sistema, vector<string>);
void realizar_accion(SistemaDeGestionDeCursos *sistema, string comando);
void ayuda(SistemaDeGestionDeCursos *sistema, vector<string> args);
void dividir(string const &str, const char delim, vector<string> &out);
vector<int> cargarListaDeInt(string str_lista);
void acceder(SistemaDeGestionDeCursos*, vector<string>);
void verCursos(SistemaDeGestionDeCursos*, vector<string>);
void cerrarSesion(SistemaDeGestionDeCursos*, vector<string>);
void subscribirse(SistemaDeGestionDeCursos*, vector<string>);
void darseDeBaja(SistemaDeGestionDeCursos*, vector<string>);
void asignarRecurso(SistemaDeGestionDeCursos*, vector<string>);
void retirarRecurso(SistemaDeGestionDeCursos*, vector<string>);
void crearCurso(SistemaDeGestionDeCursos*, vector<string>);
void eliminarCurso(SistemaDeGestionDeCursos*, vector<string>);
void registrar(SistemaDeGestionDeCursos*, vector<string>);
void imprimirInformeEstadistico(SistemaDeGestionDeCursos*, vector<string>);
time_t convertirStringDatetime(char *datetime_str);




map<string, function<void(SistemaDeGestionDeCursos*, vector<string>)>> comandos = {
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

	ayuda(&sistema, vector<string>());

	string comando = "";
	getline(cin, comando);

	while (comando.compare("salir"))
	{
		try {
			realizar_accion(&sistema, comando);
		} catch (exception& e){
			cout << e.what() << endl;
		}
		getline(cin, comando);
	}

	sistema.guardarDatos();
}

void realizar_accion(SistemaDeGestionDeCursos *sistema, string comando)
{
	vector<string> comandoDividido;
	dividir(comando, ' ', comandoDividido);
	// Esto llamar?? a la funci??n asignada al comando dado.
	// Si el comando es desconocido, esto lanzar?? una excepci??n.

	try{
		comandos.at(comandoDividido[0])(sistema, comandoDividido);
	} catch (out_of_range& e){
		throw ComandoDesconocido();
	}
}

void menu(SistemaDeGestionDeCursos *sistema, vector<string> args)
{
	switch(sistema->autorizacion){

		case Visitante:
			cout << "************************************************" << endl;
			cout << "Como Visitante tiene las siguientes opciones:" << endl;
			cout << "\t" << "ayuda" << endl;
			cout << "\t" << "menu" << endl;
			cout << "\t" << "acceder <email> <contrase??a>" << endl;
			cout << "\t" << "ver-cursos" << endl;
			cout << "************************************************" << endl;

			break;

		case Estudiante:
			cout << "************************************************" << endl;
			cout << "Como Estudiante tiene las siguientes opciones:" << endl;
			cout << "\t" << "ayuda" << endl;
			cout << "\t" << "menu" << endl;
			cout << "\t" << "cerrar-sesion" << endl;
			cout << "\t" << "ver-cursos" << endl;
			cout << "\t" << "subscribirse <Id del curso>" << endl;
			cout << "\t" << "darse-de-baja <Id del curso>" << endl;
			cout << "************************************************" << endl;
			break;

		case CoordinadorDeCursos:
			cout << "************************************************" << endl;
			cout << "Como Coordinador de Cursos tiene las siguientes opciones:" << endl;
			cout << "\t" << "ayuda" << endl;
			cout << "\t" << "menu" << endl;
			cout << "\t" << "cerrar-sesion" << endl;
			cout << "\t" << "ver-cursos" << endl;
			cout << "\t" << "asignar-recurso <Id del curso> <Nombre del recurso>" << endl;
			cout << "\t" << "retirar-recurso <Id del curso> <Nombre del recurso>" << endl;
			cout << "************************************************" << endl;
			break;

		case CoordinadorDeRecursos:
			cout << "************************************************" << endl;
			cout << "Como Coordinador de Recursos tiene las siguientes opciones:" << endl;
			cout << "\t" << "ayuda" << endl;
			cout << "\t" << "menu" << endl;
			cout << "\t" << "cerrar-sesion" << endl;
			cout << "\t" << "ver-cursos" << endl;
			cout << "\t" << "crear-curso <Id del curso> <Nombre del recurso> <Descripci??n> "
					"                    <Fecha de Inicio> <Fecha final> <Aforo> <Precio> <Ponente Principal> <[Lista,de,Pontentes]> <[Lista,de,Asistentes]>" << endl;
			cout << "\t" << "eliminar-curso <Id del curso>" << endl;
			cout << "************************************************" << endl;
			break;

		case Administrador:
			cout << "************************************************" << endl;
			cout << "Como Administrador tiene las siguientes opciones:" << endl;
			cout << "\t" << "ayuda" << endl;
			cout << "\t" << "menu" << endl;
			cout << "\t" << "cerrar-sesion" << endl;
			cout << "\t" << "ver-cursos" << endl;
			cout << "\t" << "crear-curso <Id del curso> <Nombre del recurso> <Descripci??n> "
					                    "<Fecha de Inicio> <Fecha final> <Aforo> <Precio> <Ponente Principal> <[Lista,de,Pontentes]> <[Lista,de,Asistentes]>" << endl;
			cout << "\t" << "eliminar-curso <Id del curso>" << endl;
			cout << "\t" << "asignar-recurso <Id del curso> <Nombre del recurso>" << endl;
			cout << "\t" << "retirar-recurso <Id del curso> <Nombre del recurso>" << endl;
			cout << "\t" << "registrar <Id del usuario> <Contrase??a> <Nombre> <Apellidos> <DNI> <Email> <Rol>" << endl;
			cout << "\t" << "informe-estadistico <Id del curso>" << endl;
			cout << "************************************************" << endl;

			break;
	}
}

void ayuda(SistemaDeGestionDeCursos *sistema, vector<string> args)
{
	cout << "**********************USO***********************" << endl;
	cout << "El sistema funcione en la manera de que puede\n"
			"escribir comandos de texto dentro del terminal.\n"
			"\nSi no sabe que comandos puede usar, puede utiliar \n"
			"el comando 'menu' para ver un menu de los distintos comandos \n"
			"que un usuario con su rol puede utilizar.\n"
			"\nLos comandos siempre tienen la siguienta forma:\n"
			"\n\t nombre_del_comando <argumentos obligatorios>\n"
			"\nPara salir de la aplicaci??n puede usar el comando 'salir'\n"
			"\nNotas:\n"
			"1. Todavia, en esta version de sistema, dentro de un argumento\n"
			"   no puedes escribir car??cter de espacio.\n"
			"   Siempre un argumento esta una palabra de n??meros, letras o \n"
			"   otras car??cteros sin c??racteros de espacio\n"
			"2. Si el argumento es de la forma de la lista como el siguente: [Lista,de,algo]\n"
			"   Tiene que escribir los elementos solamente divididos con el car??cter de ','\n"
			"   No es posible usar los c??racteros de espacios dentro de la lista.\n" << endl;
	cout << "************************************************" << endl;
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

void acceder(SistemaDeGestionDeCursos *sistema, vector<string> args)
{
	if (args.size() != 3){
		throw ArgsIncorrectos();
	}

	sistema->acceder(args[1], args[2]);
	cout << "Ha iniciado sesi??n correctamente!" << endl;
}
void verCursos(SistemaDeGestionDeCursos *sistema, vector<string> args)
{
	if (args.size() != 1){
		throw ArgsIncorrectos();
	}
	cout << "cursos:" << endl;
	cout << "************************************************" << endl;
	sistema->verLosCursos();
	cout << "************************************************" << endl;

}
void cerrarSesion(SistemaDeGestionDeCursos *sistema, vector<string> args)
{
	if (args.size() != 1){
		throw ArgsIncorrectos();
	}

	sistema->cerrarSesion();
	cout << "Se ha desconectado correctamente!" << endl;
}

void subscribirse(SistemaDeGestionDeCursos *sistema, vector<string> args)
{
	if (args.size() != 2){
		throw ArgsIncorrectos();
	}

	sistema->subscribirse(args[1]);
	cout << "Se ha suscrito correctamente!" << endl;
}

void darseDeBaja(SistemaDeGestionDeCursos *sistema, vector<string> args)
{
	if (args.size() != 2){
		throw ArgsIncorrectos();
	}

	sistema->darseDeBaja(args[1]);
	cout << "Se ha dado de baja correctamente!" << endl;
}
void asignarRecurso(SistemaDeGestionDeCursos *sistema, vector<string> args)
{
	if (args.size() != 3){
		throw ArgsIncorrectos();
	}

	sistema->asignarRecursoACurso(args[1], (char *) args[2].c_str());
	cout << "Se ha asignado el recurso correctamente!" << endl;
}
void retirarRecurso(SistemaDeGestionDeCursos *sistema, vector<string> args)
{
	if (args.size() != 3){
		throw ArgsIncorrectos();
	}

	sistema->retirarRecursoDeCurso(args[1], (char *) args[2].c_str());
	cout << "Se ha retirado el recurso correctamente!" << endl;
}
void crearCurso(SistemaDeGestionDeCursos *sistema, vector<string> args)
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

	sistema->darDeAltaCurso(cursoNuevo);
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
	dividir(str_lista.substr(1, str_lista.size() - 2), ',', resultStr);

	vector<int> result = vector<int>();
	for (string elem : resultStr)
	{
		// Si no esta numero o el n??mero potencial est?? m??s grande que el 'int' puede ser
		if (!is_number(elem) || elem.size() > 9){
			throw ArgsIncorrectos();
		}
		result.push_back(atoi(elem.c_str()));
	}
	return result;
}

void eliminarCurso(SistemaDeGestionDeCursos *sistema, vector<string> args)
{
	if (args.size() != 2){
		throw ArgsIncorrectos();
	}

	sistema->darDeBajaCurso(args[1]);
	cout << "Se ha eliminado el curso correctamente!" << endl;
}
void registrar(SistemaDeGestionDeCursos *sistema, vector<string> args)
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
	sistema->registrar(usuarioNuevo);
	cout << "El usuario se ha registrado con ex??to!" << endl;
}
void imprimirInformeEstadistico(SistemaDeGestionDeCursos *sistema, vector<string> args)
{
	if (args.size() != 2){
		throw ArgsIncorrectos();
	}

	sistema->imprimirInformeEstadistico(args[1]);
}

time_t convertirStringDatetime(char *datetime_str)
{
	 tm tm{};
	 istringstream str_stream(datetime_str);
	 str_stream >> get_time(&tm, "%d.%m.%Y-%H:%M:%S");
	 time_t time = mktime(&tm);
	 return time;
}

#include "Curso.h"
#include <iostream>
#include <algorithm>
#include <string.h>
#include "Estadistica.h"

Curso::Curso(const char *id,
		     const char *nombre,
			 const char *descripcion,
			 time_t fechaDeInicio,
			 time_t fechaFinal,
			 int aforo,
			 int precio,
		     int ponentePrincipal,
		     vector<int> listaDePonentes,
		     vector<int> listaDeAsistentes)
{
	Curso::id = strdup(id);
	Curso::nombre = strdup(nombre);
	Curso::descripcion = strdup(descripcion);
	Curso::fechaDeInicio = fechaDeInicio;
	Curso::fechaFinal = fechaFinal;
	Curso::recursosAudiovisuales = vector<const char *>();
	Curso::aforo = aforo;
	Curso::precio = precio;
	Curso::listaDeEsperaDeEstud = vector<int>();
	Curso::listaDeAsistentes = listaDeAsistentes;
	Curso::ponentePrincipal = -1;
	Curso::listaDePonentes = listaDePonentes;
	Curso::listaDeEstudiantes = vector<int>();
	Curso::estadistica = Estadistica(id, aforo);
}

Curso::Curso(const char *id,
		  const char *nombre,
		  const char *descripcion,
		  time_t fechaDeInicio,
		  time_t fechaFinal,
		  vector<const char*> recursosAudiovisuales,
		  int aforo,
	      int precio,
		  vector<int> listaDeEsperaDeEstud,
	      vector<int> listaDeAsistentes,
	      int ponentePrincipal,
	      vector<int> listaDePonentes,
		  vector<int> listaDeEstudiantes,
		  Estadistica estadistica,
		  bool isVisible)
{
	Curso::id = strdup(id);
	Curso::nombre = strdup(nombre);
	Curso::descripcion = strdup(descripcion);
	Curso::fechaDeInicio = fechaDeInicio;
	Curso::fechaFinal = fechaFinal;
	Curso::recursosAudiovisuales = recursosAudiovisuales;
	Curso::aforo = aforo;
	Curso::precio = precio;
	Curso::listaDeEsperaDeEstud = listaDeEsperaDeEstud;
	Curso::listaDeAsistentes = listaDeAsistentes;
	Curso::ponentePrincipal = ponentePrincipal;
	Curso::listaDePonentes = listaDePonentes;
	Curso::listaDeEstudiantes = listaDeEstudiantes;
	Curso::estadistica = estadistica;
	Curso::isVisible = isVisible;
}

string Curso::time2str(time_t seconds){
	std::tm * ptm = std::localtime(&seconds);
	char buffer[32];
	// Format: 15.06.2009-20:20:00
	std::strftime(buffer, 32, "%d.%m.%Y-%H:%M:%S", ptm);
	string str(buffer);
	return str;
}

void Curso::imprimirCursoFormateado()
{
	cout << "************************************************" << endl;

	cout << "ID: " << this->id << endl;
	cout << "Nombre: " << this->nombre << endl;
	cout << "Descripción: " << this->descripcion << endl;
	cout << "Fecha de Inicio: " << time2str(this->fechaDeInicio) << endl;
	cout << "Fecha Final: " << time2str(this->fechaFinal) << endl;
	cout << "Aforo: " << this->aforo << endl;
	cout << "Precio: " << this->precio << endl;
	cout << "ID de el Ponente Principal: " << this->ponentePrincipal << endl;

	cout << "Lista de Ponentes:";
	for (int ponente : this->listaDePonentes)
	{
		cout << " " << ponente;
	}
	cout << endl;

	cout << "Lista de Asistentes:";
	for (int asistente : this->listaDeAsistentes)
	{
		cout << " " << asistente;
	}
	cout << endl;

	cout << "Recursos Audiovisuales:";
	for (const char* recurso : this->recursosAudiovisuales)
	{
		cout << " " << recurso;
	}
	cout << endl;

	cout << "Lista de Espera de Estudiantes:";
	for (int estud : this->listaDeEsperaDeEstud)
	{
		cout << " " << estud;
	}
	cout << endl;

	cout << "************************************************" << endl;
}

void Curso::subscribir(int estudianteId)
{
	if (std::find(this->listaDeEstudiantes.begin(), this->listaDeEstudiantes.end(), estudianteId) != this->listaDeEstudiantes.end())
	{
		throw YaSuscrito();
	}

	this->listaDeEstudiantes.push_back(estudianteId);
	this->estadistica.numeroDeParticipantes++;
}

void Curso::darseDeBaja(int estudianteId)
{
	for (int i=0; i<this->listaDeEstudiantes.size(); i++)
	{
		if (estudianteId == this->listaDeEstudiantes[i]){
			this->listaDeEstudiantes.erase(this->listaDeEstudiantes.begin() + i);
			return;
		}
	}

	throw NoSuscrito();
}

void Curso::asignarRecurso(char *recurso)
{
	this->recursosAudiovisuales.push_back(recurso);
}
void Curso::retirarRecurso(char *recurso)
{
	string recStr(recurso);
	for (int i=0; i<this->recursosAudiovisuales.size(); i++)
	{
		string recCurStr(this->recursosAudiovisuales[i]);
		if (recStr.compare(recCurStr) == 0){
			this->recursosAudiovisuales.erase(this->recursosAudiovisuales.begin() + i);
			return;
		}
	}

	throw RecursoNoExiste();
}



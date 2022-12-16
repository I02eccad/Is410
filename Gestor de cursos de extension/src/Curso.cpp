/*
 * Curso.cpp
 *
 *  Created on: Nov 28, 2022
 *      Author: michal
 *
 *  TODO: Anadir conversion a nombres en cambio de IDs de los usuarios en imprimir funcion
 */

#include "Curso.h"
#include <iostream>

Curso::Curso(const char *id,
		  const char *nombre,
		  const char *descripcion,
		  time_t fechaFinal,
		  vector<const char*> recursosAudiovisuales,
		  int aforo,
	      int precio,
		  vector<int> listaDeEsperaDeEstud,
	      vector<int> listaDeAsistentes,
	      int ponentePrincipal,
	      vector<int> listaDePonentes)
{
	Curso::id = id;
	Curso::nombre = nombre;
	Curso::descripcion = descripcion;
	Curso::fechaFinal = fechaFinal;
	Curso::recursosAudiovisuales = recursosAudiovisuales;
	Curso::aforo = aforo;
	Curso::precio = precio;
	Curso::listaDeEsperaDeEstud = listaDeEsperaDeEstud;
	Curso::listaDeAsistentes = listaDeAsistentes;
	Curso::ponentePrincipal = ponentePrincipal;
	Curso::listaDePonentes = listaDePonentes;
}

void Curso::imprimirCursoFormateado()
{
	cout << "------------------------------------------" << endl;
	// Imprimir datos del curso en una forma como linea de base de datos
	cout << "ID: " << this->id << endl;
	cout << "Nombre: " << this->nombre << endl;
	cout << "Descripción: " << this->descripcion << endl;
	cout << "Fecha Final: " << ctime(&this->fechaFinal);
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

	cout << "--------------------------------------------" << endl;
}

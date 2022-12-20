#include "Estadistica.h"
#include <iostream>
#include <string.h>
Estadistica::Estadistica()
{
	Estadistica::cursoId = "";
	Estadistica::aforo = -1;
	Estadistica::numeroDeParticipantes = -1;
	Estadistica::calificacionesRecibidas = vector<int>();
}
Estadistica::Estadistica(const char *cursoId, int aforo) {
	Estadistica::cursoId = strdup(cursoId);
	Estadistica::aforo = aforo;
	Estadistica::numeroDeParticipantes = 0;
	Estadistica::calificacionesRecibidas = vector<int>();
}

Estadistica::Estadistica(const char *cursoId, int aforo, int numeroDeParticipantes, vector<int> calificacionesRecibidas)
{
	Estadistica::cursoId = strdup(cursoId);
	Estadistica::aforo = aforo;
	Estadistica::numeroDeParticipantes = numeroDeParticipantes;
	Estadistica::calificacionesRecibidas = calificacionesRecibidas;
}


void Estadistica::imprimirEstadisticas()
{
	cout << "************************************************" << endl;

	cout << "Curso ID: " << this->cursoId << endl;

	cout << "Aforo: " << this->aforo << endl;

	cout << "Numero de Participantes: " << this->numeroDeParticipantes << endl;

	cout << "Participación Porcentual: " << (this->numeroDeParticipantes / this->aforo)*100 << "%" << endl;

	if (this->calificacionesRecibidas.size() != 0){
		cout << "Calificación Media: " << calcularMedia(this->calificacionesRecibidas) << endl;
	}

	cout << "************************************************" << endl;
}

double Estadistica::calcularMedia(vector<int> numeros)
{
	int suma = 0;
	for (int num : numeros)
	{
		suma += num;
	}
	return suma / numeros.size();
}

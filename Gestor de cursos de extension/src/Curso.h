/*
 * Curso.h
 *
 *  Created on: Nov 28, 2022
 *      Author: michal
 */

#ifndef CURSO_H_
#define CURSO_H_

#include <ctime>
#include <vector>
#include "Usuario.h"
#include "Estadistica.h"


using namespace std;

struct YaSuscrito : public exception {
   const char * what () const throw () {
      return "No puedes subscribir en este curso porqué ya estás suscrito!";
   }
};

struct NoSuscrito : public exception {
   const char * what () const throw () {
      return "No estás suscrito en este curso!";
   }
};

struct RecursoNoExiste : public exception {
   const char * what () const throw () {
      return "El recurso que intenta eliminar no existe!";
   }
};

class Curso {
public:
	Curso(const char *id,
		  const char *nombre,
		  const char *descripcion,
		  time_t fechaFinal,
		  vector<const char*> recursosAudiovisuales,
		  int aforo,
	      int precio,
		  vector<int> listaDeEsperaDeEstud,
	      vector<int> listaDeAsistentes,
	      int ponentePrincipal,
	      vector<int> listaDePonentes);
	Curso(const char *id,
			  const char *nombre,
			  const char *descripcion,
			  time_t fechaFinal,
			  vector<const char*> recursosAudiovisuales,
			  int aforo,
		      int precio,
			  vector<int> listaDeEsperaDeEstud,
		      vector<int> listaDeAsistentes,
		      int ponentePrincipal,
		      vector<int> listaDePonentes,
			  vector<int> listaDeEstudiantes,
			  Estadistica estadistica);

	const char *id;
	const char *nombre;
	const char *descripcion;
	time_t fechaFinal;
	vector<const char*> recursosAudiovisuales;
	int aforo;
	int precio;
	// Listas de IDs de Usuarios
	vector<int> listaDeEsperaDeEstud;
	vector<int> listaDeAsistentes;
	int ponentePrincipal;
	vector<int> listaDePonentes;
	vector<int> listaDeEstudiantes;
	Estadistica estadistica;

	bool isVisible = true;

	void imprimirCursoFormateado();
	void subscribir(int estudianteId);
	void darseDeBaja(int estudianteId);
	void asignarRecurso(char *recurso);
	void retirarRecurso(char *recurso);

};

#endif /* CURSO_H_ */

#ifndef CURSO_H_
#define CURSO_H_

#include <ctime>
#include <vector>
#include <string>
#include "Usuario.h"
#include "Estadistica.h"
#include "Excepciones.h"

using namespace std;

class Curso {
private:
	string time2str(time_t seconds);
public:
	Curso(const char *id,
		  const char *nombre,
		  const char *descripción,
		  time_t fechaDeInicio,
		  time_t fechaFinal,
		  int aforo,
		  int precio,
	      int ponentePrincipal,
		  vector<int> listaDePonentes,
	      vector<int> listaDeAsistentes);
	Curso(const char *id,
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
		  bool isVisible);

	const char *id;
	const char *nombre;
	const char *descripcion;
	time_t fechaDeInicio;
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
	Estadistica estadistica = Estadistica();

	bool isVisible = true;

	void imprimirCursoFormateado();
	void subscribir(int estudianteId);
	void darseDeBaja(int estudianteId);
	void asignarRecurso(char *recurso);
	void retirarRecurso(char *recurso);

};

#endif /* CURSO_H_ */

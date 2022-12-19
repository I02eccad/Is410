#ifndef SRC_ESTADISTICA_H_
#define SRC_ESTADISTICA_H_

#include <vector>

using namespace std;

class Estadistica {
public:
	Estadistica(const char *cursoId, int aforo);
	Estadistica(const char *cursoId, int aforo, int numeroDeParticipantes, vector<int> calificacionesRecibidas);
	const char *cursoId;
	int aforo;
	int numeroDeParticipantes;
	vector<int> calificacionesRecibidas;

	void imprimirEstadisticas();
	double calcularMedia(vector<int> numeros);




};



#endif /* SRC_ESTADISTICA_H_ */

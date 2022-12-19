/*
 * SistemaDeGestionDeCursos.h
 *
 *  Created on: Nov 28, 2022
 *      Author: Michal Spiegel
 */

#ifndef SISTEMADEGESTIONDECURSOS_H_
#define SISTEMADEGESTIONDECURSOS_H_

#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include "../lib/tinyxml2.h"
#include "Curso.h"
#include "Usuario.h"
#include <exception>

struct NoAuthorizado : public exception {
   const char * what () const throw () {
      return "No tienes la authorización para esta funcionalidad!";
   }
};

struct CredencialesIncorrectas : public exception {
   const char * what () const throw () {
      return "Nombre o contraseña son incorrectas!";
   }
};

struct CursoNoEncontrado : public exception {
   const char * what () const throw () {
      return "Curso dado no existe!";
   }
};

struct SuperadoIntentos : public exception {
   const char * what () const throw () {
      return "Ha superado el número de intentos, póngase en contacto con el administrador!";
   }
};

struct NoExiste : public exception {
   const char * what () const throw () {
      return "El recurso solicitado no existe!";
   }
};

class SistemaDeGestionDeCursos {
	Rol autorizacion = Visitante;
	Usuario usuarioConectado;
	int contadorDeAccesosFallidos = 0;

	std::vector<Curso> listaDeCursos;
	std::vector<Usuario> listaDeUsuarios;

	const char *fichero_usuarios = "../data/usuarios.xml";
	const char *fichero_cursos   = "../data/cursos.xml";

	void cargarCursos();
	void cargarUsuarios();
	Estadistica cargarEstadistica(tinyxml2::XMLElement *root)
	vector<const char*> cargarListaDeString(tinyxml2::XMLElement *root);
	vector<int> cargarListaDeInt(tinyxml2::XMLElement *root);
	time_t convertirStringDatetime(const char *datetime_str);
	int  guardarCursos();
	// Solo funciona con tipos atómicos como string y int
	template <typename T>
	int guardarListaDeElem(tinyxml2::XMLDocument *doc, tinyxml2::XMLElement *padre, vector<T> listaDeElem);
	int guardarUsuarios();
	int guardarEstadistica(tinyxml2::XMLDocument *doc, tinyxml2::XMLElement *padre, Estadistica estadistica)


public:
	SistemaDeGestionDeCursos();
	void guardarDatos();
	void verLosCursos();
	void acceder(string email, string contrasena);
	void registrar(Usuario usuario);
	void darDeAltaCurso(Curso curso);
	void darDeBajaCurso(Curso curso);
	void modificarCurso(string cursoId, Curso curso_modificado);
	void subscribirse(string cursoId);
	void darseDeBaja(string cursoId);
	void asignarRecursoACurso(string cursoId, char *recurso);
	void retirarRecursoDeCurso(string cursoId, char *recurso);
	void imprimirInformeEstadistico(string cursoId);
};

#endif /* SISTEMADEGESTIONDECURSOS_H_ */

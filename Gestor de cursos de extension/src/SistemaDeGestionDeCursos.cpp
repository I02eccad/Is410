/*
 * SistemaDeGestionDeCursos.cpp
 *
 *  Created on: Nov 28, 2022
 *      Author: Michal Spiegel
 */

#include "SistemaDeGestionDeCursos.h"

SistemaDeGestionDeCursos::SistemaDeGestionDeCursos()
{
	// Cargar los datos de los XML ficheros a los vectores de datos dentro la clase
	this->cargarCursos();
	this->cargarUsuarios();
}

SistemaDeGestionDeCursos::~SistemaDeGestionDeCursos()
{
	// Guardar los datos de los vectores de datos dentro la clase a los XML ficheros
	this->guardarCursos();
	this->guardarUsuarios();
}

void SistemaDeGestionDeCursos::menuPrincipal()
{

}

void SistemaDeGestionDeCursos::verLosCursos()
{
	for (Curso curso : listaDeCursos)
	{
		if (curso.isVisible){
			curso.imprimirCursoFormateado();
		}
	}
}

void SistemaDeGestionDeCursos::darDeAltaCurso()
{
	// Crear curso con el constructor
	// Anadir a la lista de cursos
}
void SistemaDeGestionDeCursos::darDeBajaCurso(Curso curso)
{
	curso.isVisible = false;
}

void SistemaDeGestionDeCursos::acceder()
{

}

void SistemaDeGestionDeCursos::cargarCursos()
{

}

void SistemaDeGestionDeCursos::cargarUsuarios()
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(fichero_usuarios);

	tinyxml2::XMLElement *root = doc.FirstChildElement();

	for (tinyxml2::XMLElement* usuario = root->FirstChildElement(); usuario != NULL; usuario = usuario->NextSiblingElement())
	{
		Usuario usuario_nuevo(usuario->FirstChildElement()->IntText(-1), usuario->NextSiblingElement()->GetText(),
				    usuario->NextSiblingElement()->GetText(), usuario->NextSiblingElement()->GetText(),
					usuario->NextSiblingElement()->GetText(), usuario->NextSiblingElement()->GetText());
		listaDeUsuarios.push_back(usuario_nuevo)
	}
}

int SistemaDeGestionDeCursos::guardarCursos()
{


}

void SistemaDeGestionDeCursos::guardarUsuarios()
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* root = doc.NewElement("usuarios");
	doc.InsertFirstChild(root);

	for (Usuario usuario : listaDeUsuarios)
	{
		tinyxml2::XMLElement* usuario_nuevo = doc.NewElement("usuario");

		tinyxml2::XMLElement* id = doc.NewElement("id");
		id->SetText(curso.id);
		usuario_nuevo->InsertEndChild(id);

		tinyxml2::XMLElement* contrasena = doc.NewElement("contrasena");
		contrasena->SetText(curso.contrasena);
		usuario_nuevo->InsertEndChild(contrasena);

		tinyxml2::XMLElement* nombre = doc.NewElement("nombre");
		nombre->SetText(curso.nombre);
		usuario_nuevo->InsertEndChild(nombre);

		tinyxml2::XMLElement* apellidos = doc.NewElement("apellidos");
		apellidos->SetText(curso.apellidos);
		usuario_nuevo->InsertEndChild(apellidos);

		tinyxml2::XMLElement* dni = doc.NewElement("dni");
		dni->SetText(curso.dni);
		usuario_nuevo->InsertEndChild(dni);

		tinyxml2::XMLElement* email = doc.NewElement("email");
		email->SetText(curso.email);
		usuario_nuevo->InsertEndChild(email);

		root->InsertEndChild(usuario_nuevo);
	}

	doc.SaveFile(fichero_usuarios, false);

	return doc.ErrorID();
}

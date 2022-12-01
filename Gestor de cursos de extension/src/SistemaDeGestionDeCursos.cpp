/*
 * SistemaDeGestionDeCursos.cpp
 *
 *  Created on: Nov 28, 2022
 *      Author: Michal Spiegel
 */

#include "SistemaDeGestionDeCursos.h"

SistemaDeGestionDeCursos::SistemaDeGestionDeCursos()
{
	//cargarCursos()
	//cargarUsuarios()
}

void SistemaDeGestionDeCursos::verLosCursos()
{

}

void SistemaDeGestionDeCursos::acceder()
{

}
;
void SistemaDeGestionDeCursos::cargarCursos()
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(fichero_cursos);

	tinyxml2::XMLElement *root = doc.FirstChildElement();

	for (tinyxml2::XMLElement* curso = root->FirstChildElement(); curso != NULL; curso = curso->NextSiblingElement())
	{
		Curso curso_nuevo(curso->FirstChildElement()->IntText(-1), curso->NextSiblingElement()->GetText(),
				    curso->NextSiblingElement()->GetText(), curso->NextSiblingElement()->GetText(),
					curso->NextSiblingElement()->GetText(), curso->NextSiblingElement()->GetText());
		listaDeCursos.push_back(curso_nuevo)
	}
}

void SistemaDeGestionDeCursos::cargarUsuarios()
{

}

int SistemaDeGestionDeCursos::guardarCursos()
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* root = doc.NewElement("cursos");
	doc.InsertFirstChild(root);

	for (Curso curso : listaDeCursos)
	{
		tinyxml2::XMLElement* curso_nuevo = doc.NewElement("curso");

		tinyxml2::XMLElement* id = doc.NewElement("id");
		id->SetText(curso.id);
		curso_nuevo->InsertEndChild(id);

		tinyxml2::XMLElement* contrasena = doc.NewElement("contrasena");
		contrasena->SetText(curso.contrasena);
		curso_nuevo->InsertEndChild(contrasena);

		tinyxml2::XMLElement* nombre = doc.NewElement("nombre");
		nombre->SetText(curso.nombre);
		curso_nuevo->InsertEndChild(nombre);

		tinyxml2::XMLElement* apellidos = doc.NewElement("apellidos");
		apellidos->SetText(curso.apellidos);
		curso_nuevo->InsertEndChild(apellidos);

		tinyxml2::XMLElement* dni = doc.NewElement("dni");
		dni->SetText(curso.dni);
		curso_nuevo->InsertEndChild(dni);

		tinyxml2::XMLElement* emails = doc.NewElement("email");
		email->SetText(curso.email);
		curso_nuevo->InsertEndChild(email);

		root->InsertEndChild(curso_nuevo);
	}

	doc.SaveFile(fichero_cursos, false);

	return doc.ErrorID();

}

void SistemaDeGestionDeCursos::guardarUsuarios()
{

}

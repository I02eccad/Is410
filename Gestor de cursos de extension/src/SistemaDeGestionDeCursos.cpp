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

void SistemaDeGestionDeCursos::darDeAltaCurso(Curso curso)
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
	tinyxml2::XMLDocument doc;
	doc.LoadFile(fichero_cursos);

	tinyxml2::XMLElement *root = doc.FirstChildElement();

	for (tinyxml2::XMLElement* curso = root->FirstChildElement(); curso != NULL; curso = curso->NextSiblingElement())
	{
		Curso curso_nuevo(curso->FirstChildElement()->GetText(),
				          curso->NextSiblingElement()->GetText(),
						  curso->NextSiblingElement()->GetText(),
						  convertirStringDatetime(curso->NextSiblingElement()->GetText()),
						  cargarListaDeString(curso->NextSiblingElement()),
						  curso->NextSiblingElement()->IntText(),
						  curso->NextSiblingElement()->IntText(),
						  cargarListaDeInt(curso->NextSiblingElement()),
						  cargarListaDeInt(curso->NextSiblingElement()),
						  curso->NextSiblingElement()->IntText(),
						  cargarListaDeInt(curso->NextSiblingElement()))
	}
}

time_t SistemaDeGestionDeCursos::convertirStringDatetime(const char *datetime_str)
{
	 tm tm{};
	 istringstream str_stream(datetime_str);
	 str_stream >> get_time(&tm, "%c");
	 time_t time = mktime(&tm);
	 return time;
}

vector<char*> SistemaDeGestionDeCursos::cargarListaDeString(tinyxml2::XMLElement *root)
{
	vector<char*> listaFinal = vector<char*>();
	for (tinyxml2::XMLElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
	{
		listaFinal.push_back((char * const) elem->GetText());
	}
	return listaFinal;
}


vector<int> SistemaDeGestionDeCursos::cargarListaDeInt(tinyxml2::XMLElement *root)
{
	vector<int> listaFinal = vector<int>();
	for (tinyxml2::XMLElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
	{
		listaFinal.push_back(elem->IntText());
	}
	return listaFinal;
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
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* root = doc.NewElement("cursos");
	doc.InsertFirstChild(root);

	for (Curso curso : listaDeCursos)
	{
		tinyxml2::XMLElement* curso_nuevo = doc.NewElement("curso");

		tinyxml2::XMLElement* id = doc.NewElement("id");
		id->SetText(curso.id);
		curso_nuevo->InsertEndChild(id);

		tinyxml2::XMLElement* nombre = doc.NewElement("nombre");
		nombre->SetText(curso.nombre);
		curso_nuevo->InsertEndChild(nombre);

		tinyxml2::XMLElement* desc = doc.NewElement("descripcion");
		desc->SetText(curso.descripcion);
		curso_nuevo->InsertEndChild(desc);

		tinyxml2::XMLElement* fechaFinal = doc.NewElement("fechaFinal");
		fechaFinal->SetText(ctime(&curso.fechaFinal));
		curso_nuevo->InsertEndChild(fechaFinal);

		tinyxml2::XMLElement* recursosAV = doc.NewElement("recursosAudiovisuales");
		guardarListaDeElem<char*>(doc, recursosAV, curso.recursosAudiovisuales);
		curso_nuevo->InsertEndChild(recursosAV);

		tinyxml2::XMLElement* aforo = doc.NewElement("aforo");
		aforo->SetText(curso.aforo);
		curso_nuevo->InsertEndChild(aforo);

		tinyxml2::XMLElement* precio = doc.NewElement("precio");
		precio->SetText(curso.precio);
		curso_nuevo->InsertEndChild(precio);

		tinyxml2::XMLElement* listaDeEsperaDeEstud = doc.NewElement("listaDeEsperaDeEstud");
		guardarListaDeElem<int>(doc, listaDeEsperaDeEstud, curso.listaDeEsperaDeEstud);
		curso_nuevo->InsertEndChild(recursosAV);

		tinyxml2::XMLElement* listaDeAsistentes = doc.NewElement("listaDeAsistentes");
		guardarListaDeElem<int>(doc, listaDeAsistentes, curso.listaDeAsistentes);
		curso_nuevo->InsertEndChild(listaDeAsistentes);

		tinyxml2::XMLElement* ponentePrincipal = doc.NewElement("ponentePrincipal");
		ponentePrincipal->SetText(curso.ponentePrincipal);
		curso_nuevo->InsertEndChild(ponentePrincipal);

		tinyxml2::XMLElement* listaDePonentes = doc.NewElement("listaDePonentes");
		guardarListaDeElem<int>(doc, listaDePonentes, curso.listaDePonentes);
		curso_nuevo->InsertEndChild(listaDePonentes);

	}

}

template <typename T>
int SistemaDeGestionDeCursos::guardarListaDeElem(tinyxml2::XMLDocument doc, tinyxml2::XMLElement *padre, vector<T> lista)
{
	for (T elem : lista)
	{
		tinyxml2::XMLElement* xmlElem = doc.NewElement("recursoAV");
		xmlElem->SetText(elem);
		lista->InsertEndChild(xmlElem);
	}

	return doc.ErrorID();
}

int SistemaDeGestionDeCursos::guardarUsuarios()
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* root = doc.NewElement("usuarios");
	doc.InsertFirstChild(root);

	for (Usuario usuario : listaDeUsuarios)
	{
		tinyxml2::XMLElement* usuario_nuevo = doc.NewElement("usuario");

		tinyxml2::XMLElement* id = doc.NewElement("id");
		id->SetText(usuario.id);
		usuario_nuevo->InsertEndChild(id);

		tinyxml2::XMLElement* contrasena = doc.NewElement("contrasena");
		contrasena->SetText(usuario.contrasena);
		usuario_nuevo->InsertEndChild(contrasena);

		tinyxml2::XMLElement* nombre = doc.NewElement("nombre");
		nombre->SetText(usuario.nombre);
		usuario_nuevo->InsertEndChild(nombre);

		tinyxml2::XMLElement* apellidos = doc.NewElement("apellidos");
		apellidos->SetText(usuario.apellidos);
		usuario_nuevo->InsertEndChild(apellidos);

		tinyxml2::XMLElement* dni = doc.NewElement("dni");
		dni->SetText(usuario.dni);
		usuario_nuevo->InsertEndChild(dni);

		tinyxml2::XMLElement* email = doc.NewElement("email");
		email->SetText(usuario.email);
		usuario_nuevo->InsertEndChild(email);

		root->InsertEndChild(usuario_nuevo);
	}

	doc.SaveFile(fichero_usuarios, false);

	return doc.ErrorID();
}

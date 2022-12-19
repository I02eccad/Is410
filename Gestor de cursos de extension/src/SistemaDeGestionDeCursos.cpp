#include "SistemaDeGestionDeCursos.h"
#include <iostream>

SistemaDeGestionDeCursos::SistemaDeGestionDeCursos() : usuarioConectado(NULL)
{
	// Cargar los datos de los XML ficheros a los vectores de datos dentro la clase
	this->cargarCursos();
	this->cargarUsuarios();

}

void SistemaDeGestionDeCursos::guardarDatos()
{
	// Guardar los datos de los vectores de datos dentro la clase a los XML ficheros
	this->guardarCursos();
	this->guardarUsuarios();
}

void SistemaDeGestionDeCursos::verLosCursos()
{
	for (Curso curso : this->listaDeCursos)
	{
		if (curso.isVisible){
			curso.imprimirCursoFormateado();
		}
	}
}

void SistemaDeGestionDeCursos::darDeAltaCurso(Curso curso)
{
	if (!(this->autorizacion == Administrador || this->autorizacion == CoordinadorDeCursos)){
		throw NoAuthorizado();
	}

	this->listaDeCursos.push_back(curso);

}
void SistemaDeGestionDeCursos::darDeBajaCurso(string cursoId)
{
	if (!(this->autorizacion == Administrador || this->autorizacion == CoordinadorDeCursos)){
		throw NoAuthorizado();
	}

	for (int i=0; i<this->listaDeCursos.size(); i++)
	{
		if (cursoId.compare(this->listaDeCursos[i].id) == 0)
		{
			this->listaDeCursos[i].isVisible = false;
			return;
		}
	}

	throw CursoNoEncontrado();
}

void SistemaDeGestionDeCursos::modificarCurso(string cursoId, Curso curso_modificado)
{
	if (!(this->autorizacion == Administrador || this->autorizacion == CoordinadorDeCursos)){
		throw NoAuthorizado();
	}

	for (int i=0; i<this->listaDeCursos.size(); i++)
	{
		if (cursoId.compare(this->listaDeCursos[i].id) == 0)
		{
			this->listaDeCursos.erase(next(this->listaDeCursos.begin(), i));
			darDeAltaCurso(curso_modificado);
			return;
		}
	}

	throw CursoNoEncontrado();
}

void SistemaDeGestionDeCursos::asignarRecursoACurso(string cursoId, char *recurso)
{
	if (this->autorizacion != CoordinadorDeRecursos){
			throw NoAuthorizado();
	}

	for (Curso curso : this->listaDeCursos)
	{
		if (cursoId.compare(curso.id) == 0){
			curso.asignarRecurso(recurso);
			return;
		}
	}

	throw NoExiste();

}
void SistemaDeGestionDeCursos::retirarRecursoDeCurso(string cursoId, char *recurso)
{
	if (this->autorizacion != CoordinadorDeRecursos){
			throw NoAuthorizado();
	}

	for (Curso curso : this->listaDeCursos)
	{
		if (cursoId.compare(curso.id) == 0){
			curso.retirarRecurso(recurso);
			return;
		}
	}

	throw NoExiste();
}

void SistemaDeGestionDeCursos::subscribirse(string cursoId)
{
	if (this->autorizacion != Estudiante){
			throw NoAuthorizado();
	}

	for (Curso curso : this->listaDeCursos)
	{
		if (cursoId.compare(curso.id) == 0){
			curso.subscribir(this->usuarioConectado.id);
			return;
		}
	}

	throw NoExiste();

}
void SistemaDeGestionDeCursos::darseDeBaja(string cursoId)
{
	if (this->autorizacion != Estudiante){
			throw NoAuthorizado();
	}

	for (Curso curso : this->listaDeCursos)
	{
		if (cursoId.compare(curso.id) == 0){
			curso.darseDeBaja(this->usuarioConectado.id);
			return;
		}
	}

	throw NoExiste();
}

void SistemaDeGestionDeCursos::acceder(string email, string contrasena)
{
	if (this->contadorDeAccesosFallidos >= 3){
		throw SuperadoIntentos();
	}

	for (Usuario usuario : listaDeUsuarios)
	{
		if (email.compare(usuario.email) == 0 && contrasena.compare(usuario.contrasena) == 0){
			this->autorizacion = usuario.rol;
			this->usuarioConectado = usuario;
			return;
		}
	}
	throw CredencialesIncorrectas();
}

void SistemaDeGestionDeCursos::cerrarSesion()
{
	if (this->autorizacion == Visitante)
	{
		throw NoAuthorizado();
	}
	this->autorizacion = Visitante;
	this->usuarioConectado = NULL;
}

void SistemaDeGestionDeCursos::registrar(Usuario usuario)
{
	if (this->autorizacion != Administrador){
			throw NoAuthorizado();
	}

	this->listaDeUsuarios.push_back(usuario);
}

void SistemaDeGestionDeCursos::imprimirInformeEstadistico(string cursoId)
{
	if (this->autorizacion != Administrador){
			throw NoAuthorizado();
	}

	for (Curso curso : this->listaDeCursos)
	{
		if (cursoId.compare(curso.id) == 0){
			curso.estadistica.imprimirEstadisticas();
			return;
		}
	}

	throw NoExiste();

}



void SistemaDeGestionDeCursos::cargarCursos()
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile(fichero_cursos);

	tinyxml2::XMLElement *root = doc.FirstChildElement();

	for (tinyxml2::XMLElement *curso = root->FirstChildElement(); curso != NULL; curso = curso->NextSiblingElement())
	{
		tinyxml2::XMLElement *curr_child = curso->FirstChildElement();
		const char *id = curr_child->GetText();

		curr_child = curr_child->NextSiblingElement();
		const char *nombre = curr_child->GetText();

		curr_child = curr_child->NextSiblingElement();
		const char *desc   = curr_child->GetText();

		curr_child = curr_child->NextSiblingElement();
		time_t fechaDeInicio = convertirStringDatetime(curr_child->GetText());

		curr_child = curr_child->NextSiblingElement();
		time_t fechaFinal = convertirStringDatetime(curr_child->GetText());

		curr_child = curr_child->NextSiblingElement();
		vector<const char*> listaDeRecursosAV = cargarListaDeString(curr_child);

		curr_child = curr_child->NextSiblingElement();
		int aforo = curr_child->IntText();

		curr_child = curr_child->NextSiblingElement();
		int precio = curr_child->IntText();

		curr_child = curr_child->NextSiblingElement();
		vector<int> listaDeEsperaDeEstud = cargarListaDeInt(curr_child);

		curr_child = curr_child->NextSiblingElement();
		vector<int> listaDeAsistentes = cargarListaDeInt(curr_child);

		curr_child = curr_child->NextSiblingElement();
		int ponentePrincipal = curr_child->IntText();

		curr_child = curr_child->NextSiblingElement();
		vector<int> listaDePonentes = cargarListaDeInt(curr_child);

		curr_child = curr_child->NextSiblingElement();
		vector<int> listaDeEstudiantes = cargarListaDeInt(curr_child);

		curr_child = curr_child->NextSiblingElement();
		Estadistica estadistica = cargarEstadistica(curr_child);

		Curso cursoNuevo(id,
				         nombre,
						 desc,
						 fechaDeInicio,
						 fechaFinal,
						 listaDeRecursosAV,
						 aforo,
						 precio,
						 listaDeEsperaDeEstud,
						 listaDeAsistentes,
						 ponentePrincipal,
						 listaDePonentes,
						 listaDeEstudiantes,
						 estadistica);

		this->listaDeCursos.push_back(cursoNuevo);
	}
}

Estadistica SistemaDeGestionDeCursos::cargarEstadistica(tinyxml2::XMLElement *root)
{
	tinyxml2::XMLElement *curr_child = root->FirstChildElement();
	const char *cursoId = curr_child->GetText();

	curr_child = curr_child->NextSiblingElement();
	int aforo = curr_child->IntText();

	curr_child = curr_child->NextSiblingElement();
	int numeroDeParticipantes= curr_child->IntText();

	curr_child = curr_child->NextSiblingElement();
	vector<int> calificacionesRecibidas = cargarListaDeInt(curr_child);

	return Estadistica(cursoId, aforo, numeroDeParticipantes, calificacionesRecibidas);
}


time_t SistemaDeGestionDeCursos::convertirStringDatetime(const char *datetime_str)
{
	 tm tm{};
	 istringstream str_stream(datetime_str);
	 str_stream >> get_time(&tm, "%c");
	 time_t time = mktime(&tm);
	 return time;
}

vector<const char*> SistemaDeGestionDeCursos::cargarListaDeString(tinyxml2::XMLElement *root)
{
	vector<const char*> listaFinal = vector<const char*>();

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
	doc.LoadFile(this->fichero_usuarios);

	tinyxml2::XMLElement *root = doc.FirstChildElement();

	for (tinyxml2::XMLElement* usuario = root->FirstChildElement(); usuario != NULL; usuario = usuario->NextSiblingElement())
	{

		Usuario usuario_nuevo(usuario->FirstChildElement()->IntText(-1), usuario->NextSiblingElement()->GetText(),
				    usuario->NextSiblingElement()->GetText(), usuario->NextSiblingElement()->GetText(),
					usuario->NextSiblingElement()->GetText(), usuario->NextSiblingElement()->GetText(),
					(Rol) usuario->NextSiblingElement()->IntText(-1));
		this->listaDeUsuarios.push_back(usuario_nuevo);
	}
}

int SistemaDeGestionDeCursos::guardarCursos()
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* root = doc.NewElement("cursos");
	doc.InsertFirstChild(root);

	for (Curso curso : this->listaDeCursos)
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

		tinyxml2::XMLElement* fechaDeInicio = doc.NewElement("fechaDeInicio");
		fechaDeInicio->SetText(ctime(&curso.fechaDeInicio));
		curso_nuevo->InsertEndChild(fechaDeInicio);

		tinyxml2::XMLElement* fechaFinal = doc.NewElement("fechaFinal");
		fechaFinal->SetText(ctime(&curso.fechaFinal));
		curso_nuevo->InsertEndChild(fechaFinal);

		tinyxml2::XMLElement* recursosAV = doc.NewElement("recursosAudiovisuales");
		SistemaDeGestionDeCursos::guardarListaDeElem<const char*>(&doc, recursosAV, curso.recursosAudiovisuales);
		curso_nuevo->InsertEndChild(recursosAV);

		tinyxml2::XMLElement* aforo = doc.NewElement("aforo");
		aforo->SetText(curso.aforo);
		curso_nuevo->InsertEndChild(aforo);

		tinyxml2::XMLElement* precio = doc.NewElement("precio");
		precio->SetText(curso.precio);
		curso_nuevo->InsertEndChild(precio);

		tinyxml2::XMLElement* listaDeEsperaDeEstud = doc.NewElement("listaDeEsperaDeEstud");
		guardarListaDeElem<int>(&doc, listaDeEsperaDeEstud, curso.listaDeEsperaDeEstud);
		curso_nuevo->InsertEndChild(listaDeEsperaDeEstud);

		tinyxml2::XMLElement* listaDeAsistentes = doc.NewElement("listaDeAsistentes");
		guardarListaDeElem<int>(&doc, listaDeAsistentes, curso.listaDeAsistentes);
		curso_nuevo->InsertEndChild(listaDeAsistentes);

		tinyxml2::XMLElement* ponentePrincipal = doc.NewElement("ponentePrincipal");
		ponentePrincipal->SetText(curso.ponentePrincipal);
		curso_nuevo->InsertEndChild(ponentePrincipal);

		tinyxml2::XMLElement* listaDePonentes = doc.NewElement("listaDePonentes");
		guardarListaDeElem<int>(&doc, listaDePonentes, curso.listaDePonentes);
		curso_nuevo->InsertEndChild(listaDePonentes);

		tinyxml2::XMLElement* listaDeEstudiantes = doc.NewElement("listaDeEstudiantes");
		guardarListaDeElem<int>(&doc, listaDeEstudiantes, curso.listaDeEstudiantes);
		curso_nuevo->InsertEndChild(listaDeEstudiantes);

		tinyxml2::XMLElement* estadistica = doc.NewElement("estadistica");
		guardarEstadistica(&doc, estadistica, curso.estadistica);
		curso_nuevo->InsertEndChild(estadistica);

		root->InsertEndChild(curso_nuevo);

	}

	doc.SaveFile(fichero_cursos, false);

	return doc.ErrorID();
}

template <typename T>
int SistemaDeGestionDeCursos::guardarListaDeElem(tinyxml2::XMLDocument *doc, tinyxml2::XMLElement *padre, vector<T> lista)
{
	for (T elem : lista)
	{
		tinyxml2::XMLElement* xmlElem = (*doc).NewElement("elem");
		xmlElem->SetText(elem);
		padre->InsertEndChild(xmlElem);
	}

	return (*doc).ErrorID();
}

int SistemaDeGestionDeCursos::guardarUsuarios()
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* root = doc.NewElement("usuarios");
	doc.InsertFirstChild(root);

	for (Usuario usuario : this->listaDeUsuarios)
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

		tinyxml2::XMLElement* rol = doc.NewElement("rol");
		rol->SetText(usuario.rol);
		usuario_nuevo->InsertEndChild(rol);

		root->InsertEndChild(usuario_nuevo);
	}

	doc.SaveFile(fichero_usuarios, false);

	return doc.ErrorID();
}

int SistemaDeGestionDeCursos::guardarEstadistica(tinyxml2::XMLDocument *doc, tinyxml2::XMLElement *padre, Estadistica estadistica)
{

	tinyxml2::XMLElement* cursoId = (*doc).NewElement("cursoId");
	cursoId->SetText(estadistica.cursoId);
	padre->InsertEndChild(cursoId);

	tinyxml2::XMLElement* aforo = (*doc).NewElement("aforo");
	aforo->SetText(estadistica.aforo);
	padre->InsertEndChild(aforo);

	tinyxml2::XMLElement* numeroDeParticipantes = (*doc).NewElement("numeroDeParticipantes");
	numeroDeParticipantes->SetText(estadistica.numeroDeParticipantes);
	padre->InsertEndChild(numeroDeParticipantes);

	tinyxml2::XMLElement* calificacionesRecibidas = (*doc).NewElement("califacionesRecibidas");
	guardarListaDeElem<int>(doc, calificacionesRecibidas, estadistica.calificacionesRecibidas)

	return (*doc).ErrorID();
}
